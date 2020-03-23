#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "aes.h"

BITE gold_plaintxt  [NUM_DATA_BYTES];
BITE gold_key       [NUM_KEY_BYTES];
BITE gold_cyphertxt [NUM_DATA_BYTES];
BITE test_cyphertxt [NUM_DATA_BYTES];


int main()
{
    gold_plaintxt[0]  = 0xae;    gold_plaintxt[1]  = 0x2d;
    gold_plaintxt[2]  = 0x8a;    gold_plaintxt[3]  = 0x57;
    gold_plaintxt[4]  = 0x1e;    gold_plaintxt[5]  = 0x03;
    gold_plaintxt[6]  = 0xac;    gold_plaintxt[7]  = 0x9c;
    gold_plaintxt[8]  = 0x9e;    gold_plaintxt[9]  = 0xb7;
    gold_plaintxt[10] = 0x6f;    gold_plaintxt[11] = 0xac;
    gold_plaintxt[12] = 0x45;    gold_plaintxt[13] = 0xaf;
    gold_plaintxt[14] = 0x8e;    gold_plaintxt[15] = 0x51;

    gold_key[0]  = 0x60;    gold_key[1]  = 0x3d;
    gold_key[2]  = 0xeb;    gold_key[3]  = 0x10;
    gold_key[4]  = 0x15;    gold_key[5]  = 0xca;
    gold_key[6]  = 0x71;    gold_key[7]  = 0xbe;
    gold_key[8]  = 0x2b;    gold_key[9]  = 0x73;
    gold_key[10] = 0xae;    gold_key[11] = 0xf0;
    gold_key[12] = 0x85;    gold_key[13] = 0x7d;
    gold_key[14] = 0x77;    gold_key[15] = 0x81;
    gold_key[16] = 0x1f;    gold_key[17] = 0x35;
    gold_key[18] = 0x2c;    gold_key[19] = 0x07;
    gold_key[20] = 0x3b;    gold_key[21] = 0x61;
    gold_key[22] = 0x08;    gold_key[23] = 0xd7;
    gold_key[24] = 0x2d;    gold_key[25] = 0x98;
    gold_key[26] = 0x10;    gold_key[27] = 0xa3;
    gold_key[28] = 0x09;    gold_key[29] = 0x14;
    gold_key[30] = 0xdf;    gold_key[31] = 0xf4;

    gold_cyphertxt[0] =  0x59;    gold_cyphertxt[1] =  0x1c;
    gold_cyphertxt[2] =  0xcb;    gold_cyphertxt[3] =  0x10;
    gold_cyphertxt[4] =  0xd4;    gold_cyphertxt[5] =  0x10;
    gold_cyphertxt[6] =  0xed;    gold_cyphertxt[7] =  0x26;
    gold_cyphertxt[8] =  0xdc;    gold_cyphertxt[9] =  0x5b;
    gold_cyphertxt[10] = 0xa7;    gold_cyphertxt[11] = 0x4a;
    gold_cyphertxt[12] = 0x31;    gold_cyphertxt[13] = 0x36;
    gold_cyphertxt[14] = 0x28;    gold_cyphertxt[15] = 0x70;

        aes( gold_plaintxt, gold_key, test_cyphertxt );
        
        for( int j=0; j<NUM_DATA_BYTES; j++ ) {
            if (gold_cyphertxt[j] != test_cyphertxt[j]) {
                fprintf(stdout, "*******************************************\n");
                fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
                fprintf(stdout, "Test Cypher %d: %02x\n", j, test_cyphertxt[j]);
                fprintf(stdout, "Gold Cypher %d: %02x\n", j, gold_cyphertxt[j]);
                fprintf(stdout, "*******************************************\n");
                return 1;
            } else {
                fprintf(stdout, "*******************************************\n");
                fprintf(stdout, "Test Cypher %d: %02x\n", j, test_cyphertxt[j]);
                fprintf(stdout, "Gold Cypher %d: %02x\n", j, gold_cyphertxt[j]);
                fprintf(stdout, "*******************************************\n");
         
            }
        }
    
    fprintf(stdout, "*******************************************\n");
    fprintf(stdout, "PASS: The output matches the golden output!\n");
    fprintf(stdout, "*******************************************\n");
    return 0;
    
    

}
