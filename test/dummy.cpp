#include "gtest/gtest.h"

extern "C" {
#include "myctestexec/dummy.h"
}

TEST(dummytest, ok) {
	  ASSERT_EQ(dummy_func(1), 1);
}

TEST(dummytest, not_ok) {
	  ASSERT_EQ(dummy_func(0), 0);  
}

#if DUMMY_TEST_FORCE_ERROR
TEST(dummytest_forced_error, test_failed) {
	  ASSERT_EQ(dummy_func(0), 1);  // dummy_func should return 0 as g_x = 1 and 1 != 0
}
#endif // DUMMY_TEST_FORCE_ERROR