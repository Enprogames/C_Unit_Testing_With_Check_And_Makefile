// test_vector.c

#include <stdlib.h>
#include <math.h>
#include <check.h>

#include "vector.h"


START_TEST(test_vector) {

    Vector my_vec = create_vector(3);
    my_vec.data[0] = 5;
    my_vec.data[1] = 3;
    my_vec.data[2] = 10;

    ck_assert_int_eq(my_vec.size, 3);
    ck_assert_int_eq(my_vec.data[0], 5);
    ck_assert_int_eq(my_vec.data[1], 3);
    ck_assert_int_eq(my_vec.data[2], 10);

} END_TEST

START_TEST(test_magnitude) {
    extern float magnitude(Vector);

    Vector v1 = create_vector(3);
    v1.data[0] = 1;
    v1.data[1] = 2;
    v1.data[2] = 3;

    float result = magnitude(v1);

    ck_assert_double_eq(result, (float) sqrt(14));
}

START_TEST (test_dot_product) {
    extern float dot_product(Vector, Vector);

    Vector v1 = create_vector(3);
    v1.data[0] = 1;
    v1.data[1] = 2;
    v1.data[2] = 3;

    Vector v2 = create_vector(3);
    v2.data[0] = 4.5;
    v2.data[1] = 5;
    v2.data[2] = 6;

    float result = dot_product(v1, v2);

    ck_assert_double_eq(result, 32.5);


} END_TEST

Suite *vector_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Vector");
    tc_core = tcase_create("Core");

    // IMPORTANT: Whenever new test cases are added, add them
    // to the test suite here.
    tcase_add_test(tc_core, test_vector);
    tcase_add_test(tc_core, test_magnitude);
    tcase_add_test(tc_core, test_dot_product);
    suite_add_tcase(s, tc_core);

    return s;
}


#include <check.h>

START_TEST (sanity_check)
{
    fail_unless(5 == 5, "this should succeed");
    fail_unless(6 == 5, "this should fail");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, sanity_check);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}