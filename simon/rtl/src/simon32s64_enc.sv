module simon32s64_enc(
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

    



//x1 circular shift to the left 1
//x2 circular shift to the left 2
//x8 circular shift to the left 8
//
//next cycle X becomes y ^ ( x1 & x8 ) ^ x2 ^ subkey
//next cycle Y becomes x
//
//
//This encrypt takes 32 keys and fills subkeys 
	//subkeyAr[0] = key[3];
	//subkeyAr[1] = key[2];
	//subkeyAr[2] = key[1];
	//subkeyAr[3] = key[0];

//32 rounds are computed in total


endmodule
