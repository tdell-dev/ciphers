import cocotb
from cocotb.triggers import Timer

@cocotb.test()
def run_test(dut):
    dut._log.info("Running Test!")
