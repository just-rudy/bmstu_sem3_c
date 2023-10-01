#include <stdlib.h>
#include <check.h>
#include "sort.h"

// Функция тестирования какой-либо задачи.
START_TEST(single_correct_element)
{
    int arr[] = { 100, 1, 2, 4, 5, 10 };
    size_t n = 6;

    int res[] = { 100 };
    size_t n_res = 1;

    int *pb = NULL, *pe = NULL;

    key(arr, arr + n, &pb, &pe);

    // correct element cnt
    ck_assert_int_eq(n_res, pe - pb);
    // correct elements
    for (size_t i = 0; i < n_res; i++)
        ck_assert_int_eq(*(pb + i), res[i]);

    free(pb);
}
END_TEST

START_TEST(single_element)
{
    int arr[] = { 100 };
    size_t n = 1;

    int res[] = {  };
    size_t n_res = 0;

    int *pb = NULL, *pe = NULL;

    key(arr, arr + n, &pb, &pe);

    // correct element cnt
    ck_assert_int_eq(n_res, pe - pb);
    // correct elements
    for (size_t i = 0; i < n_res; i++)
        ck_assert_int_eq(*(pb + i), res[i]);

    free(pb);
}
END_TEST

START_TEST(two_elements)
{
    int arr[] = { 100, 1 };
    size_t n = 2;

    int res[] = { 100 };
    size_t n_res = 1;

    int *pb = NULL, *pe = NULL;

    key(arr, arr + n, &pb, &pe);

    // correct element cnt
    ck_assert_int_eq(n_res, pe - pb);
    // correct elements
    for (size_t i = 0; i < n_res; i++)
        ck_assert_int_eq(*(pb + i), res[i]);

    free(pb);
}
END_TEST

START_TEST(several_elements)
{
    int arr[] = {1, 100, 3, 5, 17, 12, 3};
    size_t n = 7;

    int res[] = {100, 17, 12};
    size_t n_res = 3;

    int *pb = NULL, *pe = NULL;

    key(arr, arr + n, &pb, &pe);

    // correct element cnt
    ck_assert_int_eq(n_res, pe - pb);
    // correct elements
    for (size_t i = 0; i < n_res; i++)
        ck_assert_int_eq(*(pb + i), res[i]);

    free(pb);
}
END_TEST

// Функция создания набора тестов.
Suite *example_suite_create(void)
{
    Suite *suite = suite_create("key");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Core of example");

    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, single_correct_element);
    tcase_add_test(tcase_core, single_element);
    tcase_add_test(tcase_core, two_elements);
    tcase_add_test(tcase_core, several_elements);

    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core);

    return suite;
}