#include "gtest/gtest.h"

/*
 * https://github.com/google/googletest/blob/master/googletest/docs/primer.md#writing-the-main-function
 */
int main(int argc, char **argv) {
	  ::testing::InitGoogleTest(&argc, argv);
	    return RUN_ALL_TESTS();
}
