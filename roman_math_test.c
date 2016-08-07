#include <check.h>
#include <stdlib.h>

#include "roman_math.h"

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
    fail_unless(convert_to_integer("I") == 1);
}
END_TEST

START_TEST(numeral_two_can_be_converted)
{
    fail_unless(convert_to_integer("II") == 2);
}
END_TEST

START_TEST(numeral_three_can_be_converted)
{
    fail_unless(convert_to_integer("III") == 3);
}
END_TEST

START_TEST(numeral_four_can_be_converted)
{
    fail_unless(convert_to_integer("IV") == 4);
}
END_TEST

START_TEST(numeral_five_can_be_converted)
{
    fail_unless(convert_to_integer("V") == 5);
}
END_TEST

START_TEST(numeral_ten_can_be_converted)
{
    fail_unless(convert_to_integer("X") == 10);
}
END_TEST

START_TEST(numeral_one_hundred_can_be_converted)
{
    fail_unless(convert_to_integer("C") == 100);
}
END_TEST

START_TEST(numeral_one_thousand_can_be_converted)
{
    fail_unless(convert_to_integer("M") == 1000);
}
END_TEST

START_TEST(numeral_fifty_can_be_converted)
{
    fail_unless(convert_to_integer("L") == 50);
}
END_TEST

START_TEST(numeral_five_hundred_can_be_converted)
{
    fail_unless(convert_to_integer("D") == 500);
}
END_TEST

START_TEST(integration_test_edge_cases)
{
    fail_unless(convert_to_integer("XV") == 15);
    fail_unless(convert_to_integer("ML") == 1050);
    fail_unless(convert_to_integer("XCIX") == 99);
    fail_unless(convert_to_integer("MMMCMXCIX") == 3999);
    fail_unless(convert_to_integer("MCCXXXIV") == 1234);
    fail_unless(convert_to_integer("XLII") == 42);
}
END_TEST

START_TEST(integer_one_can_be_converted)
{
    char *actual_value = convert_to_numeral(1);
    ck_assert_str_eq(actual_value, "I");
    free(actual_value);
}
END_TEST

START_TEST(integer_four_can_be_converted)
{
    char *actual_value = convert_to_numeral(4);
    ck_assert_str_eq(actual_value, "IV");
    free(actual_value);
}
END_TEST

START_TEST(integer_five_can_be_converted)
{
    char *actual_value = convert_to_numeral(5);
    ck_assert_str_eq(actual_value, "V");
    free(actual_value);
}
END_TEST

START_TEST(integer_nine_can_be_converted)
{
    char *actual_value = convert_to_numeral(9);
    ck_assert_str_eq(actual_value, "IX");
    free(actual_value);
}
END_TEST

START_TEST(integer_ten_can_be_converted)
{
    char *actual_value = convert_to_numeral(10);
    ck_assert_str_eq(actual_value, "X");
    free(actual_value);
}
END_TEST

START_TEST(integer_forty_can_be_converted)
{
    char *actual_value = convert_to_numeral(40);
    ck_assert_str_eq(actual_value, "XL");
    free(actual_value);
}
END_TEST

START_TEST(integer_fifty_can_be_converted)
{
    char *actual_value = convert_to_numeral(50);
    ck_assert_str_eq(actual_value, "L");
    free(actual_value);
}
END_TEST

START_TEST(integer_ninety_can_be_converted)
{
    char *actual_value = convert_to_numeral(90);
    ck_assert_str_eq(actual_value, "XC");
    free(actual_value);
}
END_TEST

START_TEST(integer_one_hundred_can_be_converted)
{
    char *actual_value = convert_to_numeral(100);
    ck_assert_str_eq(actual_value, "C");
    free(actual_value);
}
END_TEST

START_TEST(integer_four_hundred_can_be_converted)
{
    char *actual_value = convert_to_numeral(400);
    ck_assert_str_eq(actual_value, "CD");
    free(actual_value);
}
END_TEST

START_TEST(integer_five_hundred_can_be_converted)
{
    char *actual_value = convert_to_numeral(500);
    ck_assert_str_eq(actual_value, "D");
    free(actual_value);
}
END_TEST

START_TEST(integer_nine_hundred_can_be_converted)
{
    char *actual_value = convert_to_numeral(900);
    ck_assert_str_eq(actual_value, "CM");
    free(actual_value);
}
END_TEST

START_TEST(integer_one_thousand_can_be_converted)
{
    char *actual_value = convert_to_numeral(1000);
    ck_assert_str_eq(actual_value, "M");
    free(actual_value);
}
END_TEST

START_TEST(integration_test_integer_conversion_edge_cases)
{
    char *c1 = convert_to_numeral(3999);
    ck_assert_str_eq(c1, "MMMCMXCIX");
    free(c1);

    char *c2 = convert_to_numeral(1234);
    ck_assert_str_eq(c2, "MCCXXXIV");
    free(c2);

    char *c3 = convert_to_numeral(99);
    ck_assert_str_eq(c3, "XCIX");
    free(c3);

    char *c4 = convert_to_numeral(42);
    ck_assert_str_eq(c4, "XLII");
    free(c4);
}
END_TEST

START_TEST(two_numerals_can_be_added)
{
    ck_assert_str_eq(add("I", "I"), "II");
    ck_assert_str_eq(add("I", "III"), "IV");
    ck_assert_str_eq(add("X", "X"), "XX");
    ck_assert_str_eq(add("CI", "XLII"), "CXLIII");
    ck_assert_str_eq(add("CL", "C"), "CCL");
}
END_TEST

START_TEST(two_numerals_can_be_subtracted)
{
    ck_assert_str_eq(subtract("II", "I"), "I");
    ck_assert_str_eq(subtract("III", "I"), "II");
    ck_assert_str_eq(subtract("X", "V"), "V");
    ck_assert_str_eq(subtract("XLII", "XL"), "II");
    ck_assert_str_eq(subtract("CLXXV", "C"), "LXXV");
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
    tcase_add_test(tc1_1, numeral_fifty_can_be_converted);
    tcase_add_test(tc1_1, numeral_five_hundred_can_be_converted);
    tcase_add_test(tc1_1, integration_test_edge_cases);

    tcase_add_test(tc1_1, integer_one_can_be_converted);
    tcase_add_test(tc1_1, integer_four_can_be_converted);
    tcase_add_test(tc1_1, integer_five_can_be_converted);
    tcase_add_test(tc1_1, integer_nine_can_be_converted);
    tcase_add_test(tc1_1, integer_ten_can_be_converted);
    tcase_add_test(tc1_1, integer_forty_can_be_converted);
    tcase_add_test(tc1_1, integer_fifty_can_be_converted);
    tcase_add_test(tc1_1, integer_ninety_can_be_converted);
    tcase_add_test(tc1_1, integer_one_hundred_can_be_converted);
    tcase_add_test(tc1_1, integer_four_hundred_can_be_converted);
    tcase_add_test(tc1_1, integer_five_hundred_can_be_converted);
    tcase_add_test(tc1_1, integer_nine_hundred_can_be_converted);
    tcase_add_test(tc1_1, integer_one_thousand_can_be_converted);
    tcase_add_test(tc1_1, integration_test_integer_conversion_edge_cases);

    tcase_add_test(tc1_1, two_numerals_can_be_added);
    tcase_add_test(tc1_1, two_numerals_can_be_subtracted);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}