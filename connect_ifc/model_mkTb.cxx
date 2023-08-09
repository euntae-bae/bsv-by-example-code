/*
 * Generated by Bluespec Compiler, version 2022.01-29-gc526ff54 (build c526ff54)
 * 
 * On Wed Aug  9 18:35:03 KST 2023
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTb.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTb::MODEL_mkTb()
{
  mkTb_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTb()
{
  MODEL_mkTb *model = new MODEL_mkTb();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTb &INST_top = *((MOD_mkTb *)(instance_ptr));
	 tUInt8 DEF_INST_top_INST_dut_DEF_CAN_FIRE_RL_compute;
	 tUInt8 DEF_INST_top_INST_dut_DEF_WILL_FIRE_RL_compute;
	 tUInt8 DEF_INST_top_INST_stimulus_gen_DEF_CAN_FIRE_RL_gen_stimulus;
	 tUInt8 DEF_INST_top_INST_stimulus_gen_DEF_WILL_FIRE_RL_gen_stimulus;
	 tUInt8 DEF_INST_top_INST_stimulus_gen_DEF_CAN_FIRE_RL_check_results;
	 tUInt8 DEF_INST_top_INST_stimulus_gen_DEF_WILL_FIRE_RL_check_results;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_ClientServerRequest;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_ClientServerRequest;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_ClientServerResponse;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_ClientServerResponse;
	 DEF_INST_top_DEF_CAN_FIRE_RL_ClientServerRequest = INST_top.INST_stimulus_gen.METH_RDY_request_get() && INST_top.INST_dut.METH_RDY_request_put();
	 DEF_INST_top_DEF_WILL_FIRE_RL_ClientServerRequest = DEF_INST_top_DEF_CAN_FIRE_RL_ClientServerRequest;
	 DEF_INST_top_DEF_CAN_FIRE_RL_ClientServerResponse = INST_top.INST_stimulus_gen.METH_RDY_response_put() && INST_top.INST_dut.METH_RDY_response_get();
	 DEF_INST_top_DEF_WILL_FIRE_RL_ClientServerResponse = DEF_INST_top_DEF_CAN_FIRE_RL_ClientServerResponse;
	 DEF_INST_top_INST_dut_DEF_CAN_FIRE_RL_compute = INST_top.INST_dut.INST_f_in.METH_i_notEmpty() && INST_top.INST_dut.INST_f_out.METH_i_notFull();
	 DEF_INST_top_INST_dut_DEF_WILL_FIRE_RL_compute = DEF_INST_top_INST_dut_DEF_CAN_FIRE_RL_compute;
	 DEF_INST_top_INST_stimulus_gen_DEF_CAN_FIRE_RL_check_results = INST_top.INST_stimulus_gen.INST_f_in.METH_i_notEmpty() && INST_top.INST_stimulus_gen.INST_f_expected.METH_i_notEmpty();
	 DEF_INST_top_INST_stimulus_gen_DEF_WILL_FIRE_RL_check_results = DEF_INST_top_INST_stimulus_gen_DEF_CAN_FIRE_RL_check_results;
	 DEF_INST_top_INST_stimulus_gen_DEF_CAN_FIRE_RL_gen_stimulus = INST_top.INST_stimulus_gen.INST_f_out.METH_i_notFull() && INST_top.INST_stimulus_gen.INST_f_expected.METH_i_notFull();
	 DEF_INST_top_INST_stimulus_gen_DEF_WILL_FIRE_RL_gen_stimulus = DEF_INST_top_INST_stimulus_gen_DEF_CAN_FIRE_RL_gen_stimulus;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_ClientServerRequest)
	   INST_top.RL_ClientServerRequest();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_ClientServerResponse)
	   INST_top.RL_ClientServerResponse();
	 if (DEF_INST_top_INST_dut_DEF_WILL_FIRE_RL_compute)
	   INST_top.INST_dut.RL_compute();
	 if (DEF_INST_top_INST_stimulus_gen_DEF_WILL_FIRE_RL_check_results)
	   INST_top.INST_stimulus_gen.RL_check_results();
	 if (DEF_INST_top_INST_stimulus_gen_DEF_WILL_FIRE_RL_gen_stimulus)
	   INST_top.INST_stimulus_gen.RL_gen_stimulus();
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_stimulus_gen.INST_x.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_stimulus_gen.INST_f_out.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_stimulus_gen.INST_f_in.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_stimulus_gen.INST_f_expected.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_dut.INST_f_in.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_dut.INST_f_out.rst_tick_clk((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkTb::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTb_instance = new MOD_mkTb(sim_hdl, "top", NULL);
  bk_get_or_define_clock(sim_hdl, "CLK");
  if (master)
  {
    bk_alter_clock(sim_hdl, bk_get_clock_by_name(sim_hdl, "CLK"), CLK_LOW, false, 0llu, 5llu, 5llu);
    bk_use_default_reset(sim_hdl);
  }
  bk_set_clock_event_fn(sim_hdl,
			bk_get_clock_by_name(sim_hdl, "CLK"),
			schedule_posedge_CLK,
			NULL,
			(tEdgeDirection)(POSEDGE));
  (mkTb_instance->INST_stimulus_gen.INST_f_out.set_clk_0)("CLK");
  (mkTb_instance->INST_stimulus_gen.INST_f_in.set_clk_0)("CLK");
  (mkTb_instance->INST_stimulus_gen.INST_f_expected.set_clk_0)("CLK");
  (mkTb_instance->INST_stimulus_gen.set_clk_0)("CLK");
  (mkTb_instance->INST_dut.INST_f_in.set_clk_0)("CLK");
  (mkTb_instance->INST_dut.INST_f_out.set_clk_0)("CLK");
  (mkTb_instance->INST_dut.set_clk_0)("CLK");
  (mkTb_instance->set_clk_0)("CLK");
}
void MODEL_mkTb::destroy_model()
{
  delete mkTb_instance;
  mkTb_instance = NULL;
}
void MODEL_mkTb::reset_model(bool asserted)
{
  (mkTb_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTb::get_instance()
{
  return mkTb_instance;
}

/* Fill in version numbers */
void MODEL_mkTb::get_version(char const **name, char const **build)
{
  *name = "2022.01-29-gc526ff54";
  *build = "c526ff54";
}

/* Get the model creation time */
time_t MODEL_mkTb::get_creation_time()
{
  
  /* Wed Aug  9 09:35:03 UTC 2023 */
  return 1691573703llu;
}

/* State dumping function */
void MODEL_mkTb::dump_state()
{
  (mkTb_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTb & mkTb_backing(tSimStateHdl simHdl)
{
  static MOD_mkTb *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTb(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTb::dump_VCD_defs()
{
  (mkTb_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTb::dump_VCD(tVCDDumpType dt)
{
  (mkTb_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkTb_backing(sim_hdl));
}
