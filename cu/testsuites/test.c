#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include "../cu.h"
#include "test.h"

void read_compiled_output_row(char *line, int row)
{
    FILE *in = NULL;
    int looper = 0;
	in = fopen ("/home/c/tests/cu/testsuites/regressions/tmp.testSuite_compile.out","rt");  /* open the file for reading */
	
	fgets(line, 100, in) ; // throw out each line that is not needed

     while (looper <= row)
     {
	 fgets(line, 100, in) ; // throw out each line that is not needed
	 	 looper++;
     }

	fclose(in); // close file

};

void read_given_output_row(char *line, int row)
{
    FILE *in = NULL;
    int looper = 0;
	in = fopen ("/home/c/tests/cu/testsuites/output5.txt","rt");  /* open the file for reading */
	

     while (looper <= row)
     {
	fgets(line, 100, in) ; // throw out each line that is not needed
	 looper++;
     }

	fclose(in); // close file

};

void process_compiled_output(struct textmatrix* txt)
{
    int rownumber = 0;
    int columnnumber = 0;       
    char *line = (char *)malloc(100*sizeof(char));
             
	 for(rownumber=0;rownumber<NUM*8;rownumber++)
	 {
      read_compiled_output_row(line,rownumber);
    
      for(columnnumber=0;columnnumber<strlen(line);columnnumber++)
      {
		  {
		  txt->text[rownumber][columnnumber]=line[columnnumber];
	      }
	  }
	  columnnumber=0;
     }
	 free(line);
};

void process_given_output(struct textmatrix* txt)
{
    int rownumber = 0;
    int columnnumber = 0;       
    char *line = (char *)malloc(100*sizeof(char));
             
	 for(rownumber=0;rownumber<NUM*8;rownumber++)
	 {
      read_given_output_row(line,rownumber);
    
      for(columnnumber=0;columnnumber<strlen(line);columnnumber++)
      {
		  {
		  txt->text[rownumber][columnnumber]=line[columnnumber];
	      }
	  }
	  columnnumber=0;
     }
	 free(line);
};


TEST(testFunctionCompile)
{
	freopen("input5.txt", "r", stdin);
	// compiling the code we want to test
  	main();

}

TEST(testFunction)
{
	//read the output of the code that has been run
	
	int looper = 0; 
	int loopout =0;
	      
    struct textmatrix test_compiled_output;
    process_compiled_output(&test_compiled_output);

    struct textmatrix test_given_output;
    process_given_output(&test_given_output);
    
for(loopout=1;loopout<NUM*8 +1;loopout++)
  { 
	for(looper=0;looper<NUM*8 ;looper++)
	{	
	printf("%c",test_given_output.text[loopout][looper]);
		
	assertEquals(test_given_output.text[loopout][looper],test_compiled_output.text[loopout][looper]);
		
    }
  printf("\n");
  }
}


/**
 * Composition of tests into testsuite
 */
TEST_SUITE(testSuite_compile)
{
    TEST_ADD(testFunctionCompile), /* Add test to testsuite */
    TEST_SUITE_CLOSURE /* By this must end all lists of tests */
};

TEST_SUITE(testSuite_test)
{
    TEST_ADD(testFunction),
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
