#include <check.h>

#include "test_point.c"
#include "test_vector.c"


int main(void) {
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(point_suite());
    srunner_add_suite(runner, vector_suite());

    // add more test suites by defining a suite, then adding it like this:
    // srunner_add_suite(runner, suite_name);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
