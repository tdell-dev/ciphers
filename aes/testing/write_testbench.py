wf = open("aes_test_test.cpp", 'w');
wf.write('#include <stdio.h>\n');


wf.write('#include <stdio.h>\n');
wf.write('#include <stdlib.h>\n');
wf.write('#include <math.h>\n');
wf.write('#include "aes.h"\n');
wf.write('\n');
wf.write('BITE gold_plaintxt  [NUM_DATA_BYTES];\n');
wf.write('BITE gold_key       [NUM_KEY_BYTES];\n');
wf.write('BITE gold_cyphertxt [NUM_DATA_BYTES];\n');
wf.write('BITE test_cyphertxt [NUM_DATA_BYTES];\n');
wf.write('\n');
wf.write('\n');
wf.write('int main()\n');
wf.write('{\n');


rf = open("out.gold.dat", "r");
trashline = rf.readline();
countline = rf.readline().rstrip();

while( '15' not in countline):
	value = ['0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'];
	keyline = rf.readline();
	ptline = rf.readline();	
	ctline = rf.readline();
	index=0;
	for x in range(len(keyline)):
		if (x > 5 and keyline[x] !='\n' ):
			print index;
			value[index] = keyline[x];
			index = index+1;
	k=0;
	for i in range(64):
		if( i%2 == 0):
			wf.write('gold_key[' + str(k) + '] = 0x' + str(value[i])+ str(value[i+1]) + ';\n');
			k+=1;
	
	value = ['0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'];
	index =0;
	for x in range(len(ptline)):
		if (x > 11 and ptline[x] != "\n"):
			value[index] = ptline[x];
			index = index+1;
			print index-1
	print "d";
	print value;

	k=0;
	for i in range(32):
		if( i%2 == 0):
			wf.write('gold_plaintxt[' + str(k) + '] = 0x' + str(value[i])+ str(value[i+1]) + ';\n');
			k+=1;
	
	
	value = ['0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'];
	index =0;
	for x in range(len(ctline)):
		if (x >12 and ctline[x] != '\n'):
			value[index] = ctline[x]
			index = index+1;
	print value;
	k=0;
	for i in range(32):
		if( i%2 == 0):
			wf.write('gold_cyphertxt[' + str(k) + '] = 0x' + str(value[i])+ str(value[i+1]) + ';\n');
			k+=1;
	
	
	wf.write(' aes( gold_plaintxt, gold_key, test_cyphertxt );\n');
	wf.write('        \n');
	wf.write('        for( int j=0; j<NUM_DATA_BYTES; j++ ) {\n');
	wf.write('            if (gold_cyphertxt[j] != test_cyphertxt[j]) {\n');
	wf.write('                fprintf(stdout, \"*******************************************\\n\");\n');
	wf.write('                fprintf(stdout, \"FAIL: ' + countline + ' Output DOES NOT match the golden output\\n\");\n');
	wf.write('                fprintf(stdout, \"Test Cypher %d: %02x\\n\", j, test_cyphertxt[j]);\n');
	wf.write('                fprintf(stdout, \"Gold Cypher %d: %02x\\n\", j, gold_cyphertxt[j]);\n');
	wf.write('                fprintf(stdout, \"*******************************************\\n\");\n');
	wf.write('                return 1;\n');
	wf.write('            } else {\n');
	wf.write('                fprintf(stdout, \"*******************************************\\n\");\n');
	wf.write('                fprintf(stdout, \"Test Cypher %d: %02x\\n\", j, test_cyphertxt[j]);\n');
	wf.write('                fprintf(stdout, \"Gold Cypher %d: %02x\\n\", j, gold_cyphertxt[j]);\n');
	wf.write('                fprintf(stdout, \"*******************************************\\n");\n');
	wf.write('            }\n');
	wf.write('        }\n');
	wf.write('    \n');
	
	trashline = rf.readline();
	countline = rf.readline().rstrip();





wf.write('    fprintf(stdout, "*******************************************\\n");\n');
wf.write('    fprintf(stdout, "PASS: The output matches the golden output!\\n");\n');
wf.write('    fprintf(stdout, "*******************************************\\n");\n');

wf.write('    }\n');

wf.close();