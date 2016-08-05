#include <check.h>

#include "converter.h"

START_TEST(index_of_returns_index_of_found_character)
{
    fail_unless(index_of("value", 'l') == 2, "Actual: %i", index_of("value", 'l'));
}
END_TEST

START_TEST(index_of_returns_negative_one_when_character_is_not_found)
{
    fail_unless(index_of("value", 'z') == -1, "Actual: %i", index_of("value", 'l'));
}
END_TEST

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

START_TEST(numeral_three_can_be_converted)
{
    fail_unless(convert("III") == 3, "three conversion failed");
}
END_TEST

START_TEST(numeral_four_can_be_converted)
{
    fail_unless(convert("IV") == 4, "four conversion failed");
}
END_TEST

START_TEST(numeral_five_can_be_converted)
{
    fail_unless(convert("V") == 5, "five conversion failed.");
}
END_TEST

START_TEST(numeral_ten_can_be_converted)
{
    fail_unless(convert("X") == 10, "ten conversion failed.");
}
END_TEST

START_TEST(numeral_one_hundred_can_be_converted)
{
    fail_unless(convert("C") == 100, "ten conversion failed.");
}
END_TEST

START_TEST(numeral_one_thousand_can_be_converted)
{
    fail_unless(convert("M") == 1000, "ten conversion failed.");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, index_of_returns_index_of_found_character);
    tcase_add_test(tc1_1, numeral_one_can_be_converted);
    tcase_add_test(tc1_1, numeral_two_can_be_converted);
    tcase_add_test(tc1_1, numeral_three_can_be_converted);
    tcase_add_test(tc1_1, numeral_four_can_be_converted);
    tcase_add_test(tc1_1, numeral_five_can_be_converted);
    tcase_add_test(tc1_1, numeral_ten_can_be_converted);
    tcase_add_test(tc1_1, numeral_one_hundred_can_be_converted);
    tcase_add_test(tc1_1, numeral_one_thousand_can_be_converted);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}