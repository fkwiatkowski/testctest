# ctest and google test tryout

## Build

```bash
$ cd build
$ cmake ..
$ make
```

## Execution test

```bash
$ ./myctestexec
$ echo $? # should return should return 1
```

## ctest tryout

* Set DUMMY_TEST_FORCE_ERROR to 1 to for ctest fail
```bash
$ ctest
Test project /home/myuser/project/build
    Start 1: dummy
1/1 Test #1: dummy ............................***Failed    0.00 sec

0% tests passed, 1 tests failed out of 1

Total Test time (real) =   0.00 sec

The following tests FAILED:
          1 - dummy (Failed)
Errors while running CTest
```

* To see some details about the failure
```bash
$ test/dummy_tests
[==========] Running 3 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 2 tests from dummytest
[ RUN      ] dummytest.ok
[       OK ] dummytest.ok (0 ms)
[ RUN      ] dummytest.not_ok
[       OK ] dummytest.not_ok (0 ms)
[----------] 2 tests from dummytest (0 ms total)

[----------] 1 test from dummytest_forced_error
[ RUN      ] dummytest_forced_error.test_failed
/home/myuser/project/test/dummy.cpp:17: Failure
Expected equality of these values:
  dummy_func(0)
    Which is: 0
  1
[  FAILED  ] dummytest_forced_error.test_failed (0 ms)
[----------] 1 test from dummytest_forced_error (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 2 test cases ran. (1 ms total)
[  PASSED  ] 2 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] dummytest_forced_error.test_failed

 1 FAILED TEST
```
 
 
* Set DUMMY_TEST_FORCE_ERROR to 0 to test with success
```bash
$ ctest
Test project /home/myuser/project//build
    Start 1: dummy
1/1 Test #1: dummy ............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
```
 
* To see some details about the success
```bash
$ test/dummy_tests
[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from dummytest
[ RUN      ] dummytest.ok
[       OK ] dummytest.ok (0 ms)
[ RUN      ] dummytest.not_ok
[       OK ] dummytest.not_ok (0 ms)
[----------] 2 tests from dummytest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 2 tests.
```