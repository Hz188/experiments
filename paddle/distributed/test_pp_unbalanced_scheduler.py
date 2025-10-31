class Data:
    accumulate_steps = 10
    num_stages = 4
    num_model_chunks = 2
    _best_unbalanced_scheduler = False
d = Data()

def _get_virtual_pp_rank(self, micro_step, forward):
    first_chunk_acc = (
        self.accumulate_steps % self.num_stages + self.num_stages
    )
    first_chunk_steps = first_chunk_acc * self.num_model_chunks
    # print(f"[ghz vpp] {micro_step=} {first_chunk_acc=} {first_chunk_steps=}")
    if self._best_unbalanced_scheduler:
        num_group_last_chunk_forward = (
            (micro_step - first_chunk_acc) // self.num_stages
        ) // self.num_model_chunks
        misplace_start = (
            first_chunk_acc
            + self.num_model_chunks
            * self.num_stages
            * num_group_last_chunk_forward
        )
        misplace_end = (
            self.accumulate_steps % self.num_stages
            + num_group_last_chunk_forward * self.num_stages
        ) * self.num_model_chunks + self.num_stages
        forward_virtual_pp_stage = (
            (micro_step - first_chunk_acc) // self.num_stages
        ) % self.num_model_chunks
        print(f"[ghz vpp] 1 {num_group_last_chunk_forward=} {misplace_start=} {misplace_end=} {forward_virtual_pp_stage=}")

    if micro_step < first_chunk_steps:
        virtual_pp_stage = micro_step // first_chunk_acc
        print(f"[ghz vpp] 2 {virtual_pp_stage=}")
        if not forward and self._best_unbalanced_scheduler:
            if (
                micro_step
                >= first_chunk_acc
                + (self.num_model_chunks - 1) * self.num_stages
            ):
                if forward_virtual_pp_stage == self.num_model_chunks - 1:
                    virtual_pp_stage = 0
                elif (
                    micro_step >= misplace_start
                    and micro_step < misplace_end
                ):
                    virtual_pp_stage = (
                        micro_step - self.num_stages
                    ) // first_chunk_acc
                print(f"[ghz vpp] 22 {virtual_pp_stage=}")
    else:
        origin_micro_step = micro_step
        micro_step -= first_chunk_steps
        virtual_pp_stage = micro_step % (
            self.num_stages * self.num_model_chunks
        )
        print(f"[ghz vpp] 3 {virtual_pp_stage=}")
        virtual_pp_stage = virtual_pp_stage // self.num_stages
        print(f"[ghz vpp] 33 {virtual_pp_stage=}")
        if not forward and self._best_unbalanced_scheduler:
            total_num_forward_step_from_steady = (
                first_chunk_acc
                + (self.accumulate_steps - first_chunk_acc)
                * self.num_model_chunks
            )
            if (
                origin_micro_step <= total_num_forward_step_from_steady
                and forward_virtual_pp_stage == self.num_model_chunks - 1
            ):
                virtual_pp_stage = 0
            elif (
                misplace_start <= total_num_forward_step_from_steady
                and origin_micro_step >= misplace_start
                and origin_micro_step < misplace_end
            ):
                if origin_micro_step < first_chunk_steps + self.num_stages:
                    virtual_pp_stage = (
                        origin_micro_step - self.num_stages
                    ) // first_chunk_acc
                else:
                    virtual_pp_stage = (micro_step - self.num_stages) % (
                        self.num_stages * self.num_model_chunks
                    )
                    virtual_pp_stage = virtual_pp_stage // self.num_stages
            print(f"[ghz vpp] 333 {virtual_pp_stage=}")

    if not forward:
        virtual_pp_stage = self.num_model_chunks - virtual_pp_stage - 1

    return virtual_pp_stage


for micro_step in range(20):
    print(f"{micro_step=}")
    vpp_rank = _get_virtual_pp_rank(d, micro_step, False)
    print(f"{vpp_rank=}\n")