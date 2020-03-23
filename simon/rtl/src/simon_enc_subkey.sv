module simon_enc_subkey #(
	parameter BLK_SIZE_IND=0

) (
	input clk,
	input rst,
	input [255:0] enc_key_in,
	input         enc_key_in_vld,
	output        enc_key_in_rdy,

	output [255:0] subkey_out,
	output         subkey_out_vld,
	input          subkey_out_rdy

);

    wire clk;
    wire rst;

    wire [255:0] enc_key_in;
    wire         enc_key_in_vld;
    reg          enc_key_in_rdy;

    reg  [255:0] subkey_out;
    reg          subkey_out_vld;
    wire         subkey_out_rdy;

    reg [61:0] z;

    if ( BLK_SIZE_IND == 0 ) begin
       assign z=62'b11111010001001010110000111001101111101000100101011000011100110;
    end else if ( BLK_SIZE_IND == 1 ) begin
      assign   z=62'b10001110111110010011000010110101000111011111001001100001011010;
    end else if ( BLK_SIZE_IND == 2 ) begin
       assign  z=62'b10101111011100000011010010011000101000010001111110010110110011;
    end else if ( BLK_SIZE_IND == 3 ) begin
        assign z=62'b11011011101011000110010111100000010010001010011100110100001111;
    end else if ( BLK_SIZE_IND == 4 ) begin
        assign z=62'b11010001111001101011011000100000010111000011001010010011101111;
    end



endmodule
