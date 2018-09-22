#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include "../cu.h"
#include "test.h"

char* read_output_row(int row)
{
    char line[100];
    FILE *in;
    int looper = 0;
	in = fopen ("/home/c/tests/cu/testsuites/regressions/tmp.testSuite_compile.out","r");  /* open the file for reading */
	
	 fgets(line, 100, in); // throw out each line that is not needed

     while (looper <= row)
     {
	 fgets(line, 100, in); // throw out each line that is not needed
	 	 looper++;
     }

	fclose(in); // close file
    char *cptr = line;

    return cptr;
};

struct textmatrix process_output()
{
    int looper = 0; 
    int rownumber = 0;
    int columnnumber = 0;       
    char* cptr = NULL ;
    struct textmatrix txt;
             
	 for(rownumber=0;rownumber<NUM*8;rownumber++)
	 {
      cptr = read_output_row(rownumber);
    
      for(columnnumber=0;columnnumber<strlen(cptr);columnnumber++)
      {
		  {
		  txt.text[rownumber][columnnumber]=cptr[columnnumber];
	      }
	  }
	  columnnumber=0;
     }

	 return txt;
};

/**
 * Test suite from imported from other file.
 */

#include "sakk.h"

/**
 * Definition of test function
 */
TEST(testFunction)
{
	// compiling the code we want to test
  	main();

}

TEST(testFunction2)
{
	//read the output of the code that has been run
	
	int looper, loopout =0, loopin =0;
	      
    struct textmatrix test_output;
    test_output = process_output();

for(loopout=1;loopout<NUM*8;loopout++)
  { 
	for(looper=0;looper<NUM*8;looper++)
	{	
	printf("%c",test_output.text[loopout][looper]);
		
	if(loopout%(NUM*2) < NUM)
		{
		if (looper%(NUM*2) < NUM) 
		assertEquals(test_output.text[loopout][looper],'X');
		if (looper%(NUM*2) >= NUM) 
		assertEquals(test_output.text[loopout][looper],'.');
		}
		
	if(loopout%(NUM*2) >= NUM)
		{
		if (looper%(NUM*2) < NUM) 
		assertEquals(test_output.text[loopout][looper],'.');
		if (looper%(NUM*2) >= NUM) 
		assertEquals(test_output.text[loopout][looper],'X');
		}
    
    }
  printf("\n");
  }
}

TEST(testFunction3)
{
	
	
}

/**
 * Composition of tests into testsuite
 */
TEST_SUITE(testSuite_compile)
{
    TEST_ADD(testFunction), /* Add test to testsuite */
    TEST_SUITE_CLOSURE /* By this must end all lists of tests */
};

TEST_SUITE(testSuite_test)
{
    TEST_ADD(testFunction2),
    TEST_ADD(testFunction3),
    TEST_SUITE_CLOSURE /* By this must end all lists of tests */
};

TEST_SUITES{
    TEST_SUITE_ADD(testSuite_compile),
    TEST_SUITE_ADD(testSuite_test),
    TEST_SUITES_CLOSURE
};

int testmain(int argc, char *argv[])
{  

    CU_SET_OUT_PREFIX("regressions/"); /* define prefix for files written
                                           by testsuites */ 
                                           
    CU_RUN(argc, argv); /* Run testsuites defined by TEST_SUITES macro
                           in its own process and stdout is redirected to
                           regressions/tmp.testSuiteName.out
                           and stderr to regressions/tmp.testSuiteName.err
                           according to CU_SET_OUT_PREFIX called before */


                           
    return 0;
}
