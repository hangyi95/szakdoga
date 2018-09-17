#include <stdio.h>
#include "../cu.h"

void print()
{
    printf("Hello world");
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
    printf("Hello, world!\n");
    	main1();

    assertTrue(0);
}

TEST(testFunction2)
{
    assertEquals(1, 1);
    assertNotEquals(1, 0);
}

TEST(testFunction3)
{
    assertEquals(0, 1);
    assertNotEquals(1, 0);
}

/**
 * Composition of tests into testsuite
 */
TEST_SUITE(testSuiteName)
{
    TEST_ADD(testFunction), /* Add test to testsuite */
    TEST_ADD(testFunction2),
    TEST_ADD(testFunction3),
    TEST_SUITE_CLOSURE /* By this must end all lists of tests */
};



TEST_SUITES{
    TEST_SUITE_ADD(testSuiteName),
    TEST_SUITES_CLOSURE
};

int main(int argc, char *argv[])
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
