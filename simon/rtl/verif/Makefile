VERILOG_SOURCES = $(PWD)/../src/simon32s64.sv       \
                  $(PWD)/../src/simon_top.sv        \
                  $(PWD)/../src/simon_subkey.sv     \
                  $(PWD)/../src/simon_enc_subkey.sv \
                  $(PWD)/../src/simon32s64_enc.sv

TOPLEVEL = simon_top

MODULE = cipher_test.simon_offtarget

include $(shell cocotb-config --makefiles)/Makefile.inc
include $(shell cocotb-config --makefiles)/Makefile.sim
