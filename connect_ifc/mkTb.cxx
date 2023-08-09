/*
 * Generated by Bluespec Compiler, version 2022.01-29-gc526ff54 (build c526ff54)
 * 
 * On Wed Aug  9 18:35:03 KST 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkTb.h"


/* Constructor */
MOD_mkTb::MOD_mkTb(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_dut(simHdl, "dut", this),
    INST_stimulus_gen(simHdl, "stimulus_gen", this),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 4u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTb::init_symbols_0()
{
  init_symbol(&symbols[0u], "dut", SYM_MODULE, &INST_dut);
  init_symbol(&symbols[1u], "RL_ClientServerRequest", SYM_RULE);
  init_symbol(&symbols[2u], "RL_ClientServerResponse", SYM_RULE);
  init_symbol(&symbols[3u], "stimulus_gen", SYM_MODULE, &INST_stimulus_gen);
}


/* Rule actions */

void MOD_mkTb::RL_ClientServerRequest()
{
  tUInt32 DEF_stimulus_gen_request_get___d4;
  tUInt32 DEF_AVMeth_stimulus_gen_request_get;
  DEF_AVMeth_stimulus_gen_request_get = INST_stimulus_gen.METH_request_get();
  DEF_stimulus_gen_request_get___d4 = DEF_AVMeth_stimulus_gen_request_get;
  INST_dut.METH_request_put(DEF_stimulus_gen_request_get___d4);
}

void MOD_mkTb::RL_ClientServerResponse()
{
  tUInt32 DEF_dut_response_get___d8;
  tUInt32 DEF_AVMeth_dut_response_get;
  DEF_AVMeth_dut_response_get = INST_dut.METH_response_get();
  DEF_dut_response_get___d8 = DEF_AVMeth_dut_response_get;
  INST_stimulus_gen.METH_response_put(DEF_dut_response_get___d8);
}


/* Methods */


/* Reset routines */

void MOD_mkTb::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_stimulus_gen.reset_RST_N(ARG_rst_in);
  INST_dut.reset_RST_N(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTb::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTb::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_dut.dump_state(indent + 2u);
  INST_stimulus_gen.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTb::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 1u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  if (levels != 1u)
  {
    unsigned int l = levels == 0u ? 0u : levels - 1u;
    num = INST_dut.dump_VCD_defs(l);
    num = INST_stimulus_gen.dump_VCD_defs(l);
  }
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTb::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing)
{
  vcd_defs(dt, backing);
  if (levels != 1u)
    vcd_submodules(dt, levels - 1u, backing);
}

void MOD_mkTb::vcd_defs(tVCDDumpType dt, MOD_mkTb &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
    }
}

void MOD_mkTb::vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkTb &backing)
{
  INST_dut.dump_VCD(dt, levels, backing.INST_dut);
  INST_stimulus_gen.dump_VCD(dt, levels, backing.INST_stimulus_gen);
}
