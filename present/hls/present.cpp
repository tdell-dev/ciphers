#include "present.h"




void present80_encrypt( WORD64 pt_0, KEYWORD key, WORD64* ct_0 ){
	
	WORD64 subKeyAr[33];
	gen_subkeys( &key, subKeyAr );

	WORD64 state;
	WORD64 intermediate1;
	WORD64 intermediate2;
	WORD64 intermediate3;
	
	add_round_key( pt_0, subKeyAr[0], &intermediate1);
	apply_sBox(intermediate1, &intermediate2);
	apply_pLayer(intermediate2, &intermediate3);
	state = intermediate3;
	
	for( INDEX i=1; i<32; i++) {
		add_round_key( state, subKeyAr[i], &intermediate1);
		apply_sBox(intermediate1, &intermediate2);
		apply_pLayer(intermediate2, &intermediate3);
		state = intermediate3;
	}

	add_round_key(state, subKeyAr[32], ct_0);
}

void present80_decrypt( WORD64 ct_0, KEYWORD key, WORD64* pt_0 ){
	
	WORD64 subKeyAr[33];
	gen_subkeys( &key, subKeyAr );

	WORD64 state;
	WORD64 intermediate1;
	WORD64 intermediate2;
	WORD64 intermediate3;
	
	add_round_key( ct_0, subKeyAr[0], &intermediate1);
	apply_sBox(intermediate1, &intermediate2);
	apply_pLayer(intermediate2, &intermediate3);
	state = intermediate3;
	
	for( INDEX i=1; i<32; i++) {
		add_round_key( state, subKeyAr[i], &intermediate1);
		apply_sBox(intermediate1, &intermediate2);
		apply_pLayer(intermediate2, &intermediate3);
		state = intermediate3;
	}

	add_round_key(state, subKeyAr[32], pt_0);
}


void present128_encrypt( WORD64 pt_0, KEYWORD_L key, WORD64 *ct_0 ){
	
	WORD64 subKeyAr[33];
	gen_subkeys( &key, subKeyAr );

	WORD64 state;
	WORD64 intermediate1;
	WORD64 intermediate2;
	WORD64 intermediate3;
	
	add_round_key( pt_0, subKeyAr[0], &intermediate1);
	apply_sBox(intermediate1, &intermediate2);
	apply_pLayer(intermediate2, &intermediate3);
	state = intermediate3;
	
	for( INDEX i=1; i<32; i++) {
		add_round_key( state, subKeyAr[i], &intermediate1);
		apply_sBox(intermediate1, &intermediate2);
		apply_pLayer(intermediate2, &intermediate3);
		state = intermediate3;
	}

	add_round_key(state, subKeyAr[32], ct_0);
}


void present128_decrypt( WORD64 ct_0, KEYWORD_L key, WORD64* pt_0 ){
		
	WORD64 subKeyAr[33];
	gen_subkeys( &key, subKeyAr );

	WORD64 state;
	WORD64 intermediate1;
	WORD64 intermediate2;
	WORD64 intermediate3;
	
	add_round_key( ct_0, subKeyAr[0], &intermediate1);
	apply_sBox(intermediate1, &intermediate2);
	apply_pLayer(intermediate2, &intermediate3);
	state = intermediate3;
	
	for( INDEX i=1; i<32; i++) {
		add_round_key( state, subKeyAr[i], &intermediate1);
		apply_sBox(intermediate1, &intermediate2);
		apply_pLayer(intermediate2, &intermediate3);
		state = intermediate3;
	}

	add_round_key(state, subKeyAr[32], pt_0);
}
