// Simon Cypher decrypt and decrypt 
//
// This toplevel module will generate decrypt if ENCRYPT_EN is 1
// This toplevel module will generate decrypt if DECRYPT_EN is 1
// Due to the numerous key size capabilities and word size abilities, only one
// of the following should be set to 1
//
//    BLOCK/KEY SIZE |    NUM ROUNDS
//    simon32s64     |        32
//    simon48s72     |        36
//    simon48s96     |        36
//    simon64s96     |        42
//    simon64s128    |        44
//    simon96s96     |        52
//    simon96s144    |        54
//    simon128s128   |        68
//    simon128s192   |        69
//    simon128s256   |        72
//
//

module simon_top #(
    parameter ENCRYPT_EN=0,
    parameter DECRYPT_EN=0,
    parameter SIMON32S64=0,
    parameter SIMON48S72=0,
    parameter SIMON48S96=0,
    parameter SIMON64S96=0,
    parameter SIMON64S128=0,
    parameter SIMON96S96=0,
    parameter SIMON96S144=0,
    parameter SIMON128S128=0,
    parameter SIMON128S192=0,
    parameter SIMON128S256=0
    ) (
        input clk,
	input rst,

	//Encrypter Inputs
	input [255:0] enc_data_in,
	input         enc_data_in_vld,
	output        enc_data_in_rdy,

	input [255:0] enc_key_in,
	input         enc_key_in_vld,
	output        enc_key_in_rdy,

	//Encrypter Output
	output [255:0] enc_data_out,
	output         enc_data_out_vld,
	input          enc_data_out_rdy,

	//Decrypter Inputs
	input [255:0] dec_data_in,
	input         dec_data_in_vld,
	output        dec_data_in_rdy,

	input [255:0] dec_key_in,
	input         dec_key_in_vld,
	output        dec_key_in_rdy,

	//Decrypter Outputs
	output [255:0] dec_data_out,
	output         dec_data_out_vld,
	input          dec_data_out_rdy

    );

    if ( ENCRYPT_EN ) begin
        if ( SIMON32S64 ) begin
	    simon32s64_enc u_simon32s64_enc (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .enc_data_in      ( enc_data_in[31:0]  ),
		    .enc_data_in_vld  ( enc_data_in_vld    ),
		    .enc_data_in_rdy  ( enc_data_in_rdy    ),
                                         
		    .enc_key_in       ( enc_key_in[63:0]   ),
		    .enc_key_in_vld   ( enc_key_in_vld     ),
		    .enc_key_in_rdy   ( enc_key_in_rdy     ),
                                         
		    .enc_data_out     ( enc_data_out[31:0] ),
		    .enc_data_out_vld ( enc_data_out_vld   ),
		    .enc_data_out_rdy ( enc_data_out_rdy   )
	    );
        end

        if ( SIMON48S72 ) begin
	    simon48s72_enc u_simon48s72_enc (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .enc_data_in      ( enc_data_in[47:0]  ),
		    .enc_data_in_vld  ( enc_data_in_vld    ),
		    .enc_data_in_rdy  ( enc_data_in_rdy    ),
                                         
		    .enc_key_in       ( enc_key_in[71:0]   ),
		    .enc_key_in_vld   ( enc_key_in_vld     ),
		    .enc_key_in_rdy   ( enc_key_in_rdy     ),
                                         
		    .enc_data_out     ( enc_data_out[47:0] ),
		    .enc_data_out_vld ( enc_data_out_vld   ),
		    .enc_data_out_rdy ( enc_data_out_rdy   )
	    );
	end

        if ( SIMON48S96 ) begin
	    simon48s96_enc u_simon48s96_enc (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .enc_data_in      ( enc_data_in[47:0]  ),
		    .enc_data_in_vld  ( enc_data_in_vld    ),
		    .enc_data_in_rdy  ( enc_data_in_rdy    ),
                                         
		    .enc_key_in       ( enc_key_in[95:0]   ),
		    .enc_key_in_vld   ( enc_key_in_vld     ),
		    .enc_key_in_rdy   ( enc_key_in_rdy     ),
                                         
		    .enc_data_out     ( enc_data_out[47:0] ),
		    .enc_data_out_vld ( enc_data_out_vld   ),
		    .enc_data_out_rdy ( enc_data_out_rdy   )
	    );
	end

        if ( SIMON64S96 ) begin
	    simon64s96_enc u_simon64s96_enc (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .enc_data_in      ( enc_data_in[63:0]  ),
		    .enc_data_in_vld  ( enc_data_in_vld    ),
		    .enc_data_in_rdy  ( enc_data_in_rdy    ),
                                         
		    .enc_key_in       ( enc_key_in[95:0]   ),
		    .enc_key_in_vld   ( enc_key_in_vld     ),
		    .enc_key_in_rdy   ( enc_key_in_rdy     ),
                                         
		    .enc_data_out     ( enc_data_out[63:0] ),
		    .enc_data_out_vld ( enc_data_out_vld   ),
		    .enc_data_out_rdy ( enc_data_out_rdy   )
	    );
	end

        if ( SIMON64S128 ) begin
	    simon64s128_enc u_simon64s128_enc (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .enc_data_in      ( enc_data_in[63:0]  ),
		    .enc_data_in_vld  ( enc_data_in_vld    ),
		    .enc_data_in_rdy  ( enc_data_in_rdy    ),
                                         
		    .enc_key_in       ( enc_key_in[127:0]   ),
		    .enc_key_in_vld   ( enc_key_in_vld     ),
		    .enc_key_in_rdy   ( enc_key_in_rdy     ),
                                         
		    .enc_data_out     ( enc_data_out[63:0] ),
		    .enc_data_out_vld ( enc_data_out_vld   ),
		    .enc_data_out_rdy ( enc_data_out_rdy   )
	    );
	end

        if ( SIMON96S96 ) begin
	    simon96s96_enc u_simon96s96_enc (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .enc_data_in      ( enc_data_in[63:0]  ),
		    .enc_data_in_vld  ( enc_data_in_vld    ),
		    .enc_data_in_rdy  ( enc_data_in_rdy    ),
                                         
		    .enc_key_in       ( enc_key_in[127:0]   ),
		    .enc_key_in_vld   ( enc_key_in_vld     ),
		    .enc_key_in_rdy   ( enc_key_in_rdy     ),
                                         
		    .enc_data_out     ( enc_data_out[63:0] ),
		    .enc_data_out_vld ( enc_data_out_vld   ),
		    .enc_data_out_rdy ( enc_data_out_rdy   )
	    );
	end

        if ( SIMON96S144 ) begin
	    simon96s144_enc u_simon96s144_enc (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .enc_data_in      ( enc_data_in[95:0]  ),
		    .enc_data_in_vld  ( enc_data_in_vld    ),
		    .enc_data_in_rdy  ( enc_data_in_rdy    ),
                                         
		    .enc_key_in       ( enc_key_in[143:0]   ),
		    .enc_key_in_vld   ( enc_key_in_vld     ),
		    .enc_key_in_rdy   ( enc_key_in_rdy     ),
                                         
		    .enc_data_out     ( enc_data_out[95:0] ),
		    .enc_data_out_vld ( enc_data_out_vld   ),
		    .enc_data_out_rdy ( enc_data_out_rdy   )
	    );
	end

        if ( SIMON128S128 ) begin
	    simon128s128_enc u_simon128s128_enc (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .enc_data_in      ( enc_data_in[127:0]  ),
		    .enc_data_in_vld  ( enc_data_in_vld    ),
		    .enc_data_in_rdy  ( enc_data_in_rdy    ),
                                         
		    .enc_key_in       ( enc_key_in[127:0]   ),
		    .enc_key_in_vld   ( enc_key_in_vld     ),
		    .enc_key_in_rdy   ( enc_key_in_rdy     ),
                                         
		    .enc_data_out     ( enc_data_out[127:0] ),
		    .enc_data_out_vld ( enc_data_out_vld   ),
		    .enc_data_out_rdy ( enc_data_out_rdy   )
	    );
	end

        if ( SIMON128S192 ) begin
	    simon128s192_enc u_simon128s192_enc (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .enc_data_in      ( enc_data_in[127:0]  ),
		    .enc_data_in_vld  ( enc_data_in_vld    ),
		    .enc_data_in_rdy  ( enc_data_in_rdy    ),
                                         
		    .enc_key_in       ( enc_key_in[191:0]   ),
		    .enc_key_in_vld   ( enc_key_in_vld     ),
		    .enc_key_in_rdy   ( enc_key_in_rdy     ),
                                         
		    .enc_data_out     ( enc_data_out[127:0] ),
		    .enc_data_out_vld ( enc_data_out_vld   ),
		    .enc_data_out_rdy ( enc_data_out_rdy   )
	    );
	end

        if ( SIMON128S256 ) begin
	    simon128s256_enc u_simon128s256_enc (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .enc_data_in      ( enc_data_in[127:0]  ),
		    .enc_data_in_vld  ( enc_data_in_vld    ),
		    .enc_data_in_rdy  ( enc_data_in_rdy    ),
                                         
		    .enc_key_in       ( enc_key_in[255:0]   ),
		    .enc_key_in_vld   ( enc_key_in_vld     ),
		    .enc_key_in_rdy   ( enc_key_in_rdy     ),
                                         
		    .enc_data_out     ( enc_data_out[127:0] ),
		    .enc_data_out_vld ( enc_data_out_vld   ),
		    .enc_data_out_rdy ( enc_data_out_rdy   )
	    );
	end
    end

    if ( DECRYPT_EN ) begin
        if ( SIMON32S64 ) begin
	    simon32s64_dec u_simon32s64_dec (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .dec_data_in      ( dec_data_in[31:0]  ),
		    .dec_data_in_vld  ( dec_data_in_vld    ),
		    .dec_data_in_rdy  ( dec_data_in_rdy    ),
                                         
		    .dec_key_in       ( dec_key_in[63:0]   ),
		    .dec_key_in_vld   ( dec_key_in_vld     ),
		    .dec_key_in_rdy   ( dec_key_in_rdy     ),
                                         
		    .dec_data_out     ( dec_data_out[31:0] ),
		    .dec_data_out_vld ( dec_data_out_vld   ),
		    .dec_data_out_rdy ( dec_data_out_rdy   )
	    );
        end

        if ( SIMON48S72 ) begin
	    simon48s72_dec u_simon48s72_dec (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .dec_data_in      ( dec_data_in[47:0]  ),
		    .dec_data_in_vld  ( dec_data_in_vld    ),
		    .dec_data_in_rdy  ( dec_data_in_rdy    ),
                                         
		    .dec_key_in       ( dec_key_in[71:0]   ),
		    .dec_key_in_vld   ( dec_key_in_vld     ),
		    .dec_key_in_rdy   ( dec_key_in_rdy     ),
                                         
		    .dec_data_out     ( dec_data_out[47:0] ),
		    .dec_data_out_vld ( dec_data_out_vld   ),
		    .dec_data_out_rdy ( dec_data_out_rdy   )
	    );
	end

        if ( SIMON48S96 ) begin
	    simon48s96_dec u_simon48s96_dec (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .dec_data_in      ( dec_data_in[47:0]  ),
		    .dec_data_in_vld  ( dec_data_in_vld    ),
		    .dec_data_in_rdy  ( dec_data_in_rdy    ),
                                         
		    .dec_key_in       ( dec_key_in[95:0]   ),
		    .dec_key_in_vld   ( dec_key_in_vld     ),
		    .dec_key_in_rdy   ( dec_key_in_rdy     ),
                                         
		    .dec_data_out     ( dec_data_out[47:0] ),
		    .dec_data_out_vld ( dec_data_out_vld   ),
		    .dec_data_out_rdy ( dec_data_out_rdy   )
	    );
	end

        if ( SIMON64S96 ) begin
	    simon64s96_dec u_simon64s96_dec (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .dec_data_in      ( dec_data_in[63:0]  ),
		    .dec_data_in_vld  ( dec_data_in_vld    ),
		    .dec_data_in_rdy  ( dec_data_in_rdy    ),
                                         
		    .dec_key_in       ( dec_key_in[95:0]   ),
		    .dec_key_in_vld   ( dec_key_in_vld     ),
		    .dec_key_in_rdy   ( dec_key_in_rdy     ),
                                         
		    .dec_data_out     ( dec_data_out[63:0] ),
		    .dec_data_out_vld ( dec_data_out_vld   ),
		    .dec_data_out_rdy ( dec_data_out_rdy   )
	    );
	end

        if ( SIMON64S128 ) begin
	    simon64s128_dec u_simon64s128_dec (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .dec_data_in      ( dec_data_in[63:0]  ),
		    .dec_data_in_vld  ( dec_data_in_vld    ),
		    .dec_data_in_rdy  ( dec_data_in_rdy    ),
                                         
		    .dec_key_in       ( dec_key_in[127:0]   ),
		    .dec_key_in_vld   ( dec_key_in_vld     ),
		    .dec_key_in_rdy   ( dec_key_in_rdy     ),
                                         
		    .dec_data_out     ( dec_data_out[63:0] ),
		    .dec_data_out_vld ( dec_data_out_vld   ),
		    .dec_data_out_rdy ( dec_data_out_rdy   )
	    );
	end

        if ( SIMON96S96 ) begin
	    simon96s96_dec u_simon96s96_dec (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .dec_data_in      ( dec_data_in[63:0]  ),
		    .dec_data_in_vld  ( dec_data_in_vld    ),
		    .dec_data_in_rdy  ( dec_data_in_rdy    ),
                                         
		    .dec_key_in       ( dec_key_in[127:0]   ),
		    .dec_key_in_vld   ( dec_key_in_vld     ),
		    .dec_key_in_rdy   ( dec_key_in_rdy     ),
                                         
		    .dec_data_out     ( dec_data_out[63:0] ),
		    .dec_data_out_vld ( dec_data_out_vld   ),
		    .dec_data_out_rdy ( dec_data_out_rdy   )
	    );
	end

        if ( SIMON96S144 ) begin
	    simon96s144_dec u_simon96s144_dec (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .dec_data_in      ( dec_data_in[95:0]  ),
		    .dec_data_in_vld  ( dec_data_in_vld    ),
		    .dec_data_in_rdy  ( dec_data_in_rdy    ),
                                         
		    .dec_key_in       ( dec_key_in[143:0]   ),
		    .dec_key_in_vld   ( dec_key_in_vld     ),
		    .dec_key_in_rdy   ( dec_key_in_rdy     ),
                                         
		    .dec_data_out     ( dec_data_out[95:0] ),
		    .dec_data_out_vld ( dec_data_out_vld   ),
		    .dec_data_out_rdy ( dec_data_out_rdy   )
	    );
	end

        if ( SIMON128S128 ) begin
	    simon128s128_dec u_simon128s128_dec (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .dec_data_in      ( dec_data_in[127:0]  ),
		    .dec_data_in_vld  ( dec_data_in_vld    ),
		    .dec_data_in_rdy  ( dec_data_in_rdy    ),
                                         
		    .dec_key_in       ( dec_key_in[127:0]   ),
		    .dec_key_in_vld   ( dec_key_in_vld     ),
		    .dec_key_in_rdy   ( dec_key_in_rdy     ),
                                         
		    .dec_data_out     ( dec_data_out[127:0] ),
		    .dec_data_out_vld ( dec_data_out_vld   ),
		    .dec_data_out_rdy ( dec_data_out_rdy   )
	    );
	end

        if ( SIMON128S192 ) begin
	    simon128s192_dec u_simon128s192_dec (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .dec_data_in      ( dec_data_in[127:0]  ),
		    .dec_data_in_vld  ( dec_data_in_vld    ),
		    .dec_data_in_rdy  ( dec_data_in_rdy    ),
                                         
		    .dec_key_in       ( dec_key_in[191:0]   ),
		    .dec_key_in_vld   ( dec_key_in_vld     ),
		    .dec_key_in_rdy   ( dec_key_in_rdy     ),
                                         
		    .dec_data_out     ( dec_data_out[127:0] ),
		    .dec_data_out_vld ( dec_data_out_vld   ),
		    .dec_data_out_rdy ( dec_data_out_rdy   )
	    );
	end

        if ( SIMON128S256 ) begin
	    simon128s256_dec u_simon128s256_dec (
		    .clk              ( clk                ),
		    .rst              ( rst                ),
                                         
		    .dec_data_in      ( dec_data_in[127:0]  ),
		    .dec_data_in_vld  ( dec_data_in_vld    ),
		    .dec_data_in_rdy  ( dec_data_in_rdy    ),
                                         
		    .dec_key_in       ( dec_key_in[255:0]   ),
		    .dec_key_in_vld   ( dec_key_in_vld     ),
		    .dec_key_in_rdy   ( dec_key_in_rdy     ),
                                         
		    .dec_data_out     ( dec_data_out[127:0] ),
		    .dec_data_out_vld ( dec_data_out_vld   ),
		    .dec_data_out_rdy ( dec_data_out_rdy   )
	    );
	end
    end



endmodule

