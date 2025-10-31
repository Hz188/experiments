import gc
import random
import re
import socket
from functools import partial
from inspect import signature
from typing import Any, Callable, List

import torch
import torch.multiprocessing as mp
from packaging import version

from colossalai.accelerator import get_accelerator

def free_port() -> int:
    """Get a free port on localhost.

    Returns:
        int: A free port on localhost.
    """
    while True:
        port = random.randint(20000, 65000)
        try:
            with socket.socket() as sock:
                sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
                sock.bind(("localhost", port))
                return port
        except OSError:
            continue

def spawn(func, nprocs=1, **kwargs):
    """
    This function is used to spawn processes for testing.

    Usage:
        # must contains arguments rank, world_size, port
        def do_something(rank, world_size, port):
            ...

        spawn(do_something, nprocs=8)

        # can also pass other arguments
        def do_something(rank, world_size, port, arg1, arg2):
            ...

        spawn(do_something, nprocs=8, arg1=1, arg2=2)

    Args:
        func (Callable): The function to be spawned.
        nprocs (int, optional): The number of processes to spawn. Defaults to 1.
    """
    port = free_port()
    wrapped_func = partial(func, world_size=nprocs, port=port, **kwargs)
    mp.spawn(wrapped_func, nprocs=nprocs)