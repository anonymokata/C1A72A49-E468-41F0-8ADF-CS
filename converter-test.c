#include <check.h>

#include "converter.h"

START_TEST(numeral_one_can_be_converted)
{
    fail_unless(convert("I") == 1, "one conversion failed");
}
END_TEST

START_TEST(numeral_two_can_be_converted)
{
    fail_unless(convert("II") == 2, "two conversion failed");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, numeral_one_can_be_converted);
    tcase_add_test(tc1_1, numeral_two_can_be_converted);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}