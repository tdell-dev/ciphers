module simon32s64 (
	input clk,
	input rst,

	input [31:0] enc_data_in,
	input        enc_data_in_vld,
	output       enc_data_in_rdy,

	input [63:0] enc_key_in,
	input        enc_key_in_vld,
	output       enc_key_in_rdy,

	output [31:0] enc_data_out,
	output        enc_data_out_vld,
	input         enc_data_out_rdy
);

  

endmodule
