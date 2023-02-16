#include "../s21_string_tests.h"

// START_TEST(strspn_test_1) { // empty
//     char src[] = "";
//     char res[] = "";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_2) { // hello
//     char src[] = "hello";
//     char res[] = "";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_3) { // hi
//     char src[] = "";
//     char res[] = "hi";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_4) { // register
//     char src[] = "School21";
//     char res[] = "scho0l21";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_5) { // both numbers 
//     char src[] = "143";
//     char res[] = "143";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_6) { // diff numbers 1
//     char src[] = "14341";
//     char res[] = "143";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_7) { // diff numbers 2
//     char src[] = "143";
//     char res[] = "14341";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_8) { // numbers in diff order
//     char src[] = "123890";
//     char res[] = "098321";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_9) { // numbers + letters 
//     char src[] = "1I4L3U";
//     char res[] = "143";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_10) { // diff numbers + letters
//     char src[] = "1I4Love4You";
//     char res[] = "143";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_11) { // just test :/
//     char src[] = "goNext";
//     char res[] = "Go";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_12) { // letters + symbols 
//     char src[] = "WanNa Pa$$ Thi$ Pr0jEcT";
//     char res[] = "123890";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_13) { // upper letters + symbols
//     char src[] = "IREALLY WANN4 P4$$ THI$ PR0J";
//     char res[] = "123890ABCQWERTY";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_14) { // lower letters
//     char src[] = "the$e te$t$ m4ke me really $ick";
//     char res[] = "1234567890qwertyuiop";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST

// START_TEST(strspn_test_15) { // find another
//     char src[] = "000000000";
//     char res[] = "111111110";

//     ck_assert_int_eq(s21_strspn(res, src),
//                      strspn(res, src));
// } END_TEST


// Suite *get_suite_s21_strspn() {
//     Suite *s = suite_create("s21_strspn suite");
//     TCase *tc = tcase_create("s21_strspn test case");
//     suite_add_tcase(s, tc);

//     tcase_add_test(tc, strspn_test_1);
//     tcase_add_test(tc, strspn_test_2);
//     tcase_add_test(tc, strspn_test_3);
//     tcase_add_test(tc, strspn_test_4);
//     tcase_add_test(tc, strspn_test_5);
//     tcase_add_test(tc, strspn_test_6);
//     tcase_add_test(tc, strspn_test_7);
//     tcase_add_test(tc, strspn_test_8);
//     tcase_add_test(tc, strspn_test_9);
//     tcase_add_test(tc, strspn_test_10);
//     tcase_add_test(tc, strspn_test_11);
//     tcase_add_test(tc, strspn_test_12);
//     tcase_add_test(tc, strspn_test_13);
//     tcase_add_test(tc, strspn_test_14);
//     tcase_add_test(tc, strspn_test_15);

//     return s;
// }


START_TEST(empty) {
    char src[] = "";
    char res[] = "";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(gora_) {
    char src[] = "gora";
    char res[] = "";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(_gora) {
    char src[] = "";
    char res[] = "gora";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(any_register) {
    char src[] = "gora";
    char res[] = "gOra";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_num) {
    char src[] = "123";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(long_num_num) {
    char src[] = "12345";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_long_num) {
    char src[] = "123";
    char res[] = "12345";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(any_num) {
    char src[] = "1234567890";
    char res[] = "0987654321";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_with_letter) {
    char src[] = "1A2A3A4A5A";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(num_with_letter2) {
    char src[] = "a1aaa23aaa41235";
    char res[] = "123";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(basic_test) {
    char src[] = "absD";
    char res[] = "aD";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(any_sim) {
    char src[] = "32ASDASDPare[0g9jf m07y271234567890";
    char res[] = "0987654321";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(upper_letter) {
    char src[] = "32ASDASDPare[0g9jf m07y271234567890";
    char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(lower_letter) {
    char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
    char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

START_TEST(not_uniq_sim) {
    char src[] = "33333333333333333333333333333333333333333333333333333333333333333333333333333333333333";
    char res[] = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111113";

    ck_assert_int_eq(s21_strspn(res, src),
                     strspn(res, src));
} END_TEST

Suite *get_suite_s21_strspn() {
    Suite *s = suite_create("suite_strspn");
    TCase *tc = tcase_create("strspn_tc");

    tcase_add_test(tc, empty);
    tcase_add_test(tc, gora_);
    tcase_add_test(tc, _gora);
    tcase_add_test(tc, any_register);
    tcase_add_test(tc, num_num);
    tcase_add_test(tc, long_num_num);
    tcase_add_test(tc, num_long_num);
    tcase_add_test(tc, any_num);
    tcase_add_test(tc, num_with_letter);
    tcase_add_test(tc, num_with_letter2);
    tcase_add_test(tc, basic_test);
    tcase_add_test(tc, any_sim);
    tcase_add_test(tc, upper_letter);
    tcase_add_test(tc, lower_letter);
    tcase_add_test(tc, not_uniq_sim);

    suite_add_tcase(s, tc);
    return s;
}