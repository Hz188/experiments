from dataclasses import dataclass, field


@dataclass
class A:
    a: int = field(default=1)
    b: int = field(default=2)


@dataclass
class B(A):
    a: int = field(default=4)
    c: int = field(default=3)


o1 = A()
o2 = B()

print(o1, o2)
