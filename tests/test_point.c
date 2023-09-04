#include <stdlib.h>
#include <check.h>

#include "point.h"


START_TEST(test_point) {

    Point2D my_point;
    my_point.x = 2;
    my_point.y = 3;

    ck_assert_int_eq(my_point.x, 2);
    ck_assert_int_eq(my_point.y, 3);
} END_TEST

Suite *point_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Point");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_point);
    suite_add_tcase(s, tc_core);

    return s;
}
