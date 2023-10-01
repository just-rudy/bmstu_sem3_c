#include <stdlib.h>
#include <check.h>
#include "sort.h"

int comparator_double(const void *a, const void *b)
{
    if (*(double *)a < *(double *)b)
        return -1;
    else if (*(double *)a > *(double *)b)
        return 1;
    else
        return 0;
}

// Функция тестирования какой-либо задачи.
START_TEST(increasing_order)
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    size_t n = 6;

    int res[] = { 1, 2, 3, 4, 5, 6 };
    size_t n_res = 6;

    mysort(arr, n, sizeof(int), comparator);
    // correct elements
    for (size_t i = 0; i < n_res; i++)
        ck_assert_int_eq(arr[i], res[i]);

}
END_TEST

START_TEST(decreasing_order)
{
    int arr[] = { 6, 5, 4, 3, 2, 1 };
    size_t n = 6;

    int res[] = { 1, 2, 3, 4, 5, 6 };
    size_t n_res = 6;

    mysort(arr, n, sizeof(int), comparator);
    // correct elements
    for (size_t i = 0; i < n_res; i++)
        ck_assert_int_eq(arr[i], res[i]);

}
END_TEST


START_TEST(all_equal)
{
    int arr[] = { 7, 7, 7, 7, 7, 7 };
    size_t n = 6;

    int res[] = { 7, 7, 7, 7, 7, 7 };
    size_t n_res = 6;

    mysort(arr, n, sizeof(int), comparator);
    // correct elements
    for (size_t i = 0; i < n_res; i++)
        ck_assert_int_eq(arr[i], res[i]);

}
END_TEST


START_TEST(single_element)
{
    int arr[] = { 1 };
    size_t n = 1;

    int res[] = { 1 };
    size_t n_res = 1;

    mysort(arr, n, sizeof(int), comparator);
    // correct elements
    for (size_t i = 0; i < n_res; i++)
        ck_assert_int_eq(arr[i], res[i]);

}
END_TEST


START_TEST(random_elements)
{
    int arr[] = { 9, 2, 1, 6, -7, 4, 7 };
    size_t n = 7;

    int res[] = { -7, 1, 2, 4, 6, 7, 9 };
    size_t n_res = 7;

    mysort(arr, n, sizeof(int), comparator);
    // correct elements
    for (size_t i = 0; i < n_res; i++)
        ck_assert_int_eq(arr[i], res[i]);

}
END_TEST

START_TEST(double_elements)
{
    double arr[] = { 1.3, 5.6, 0, -1 };
    size_t n = 4;

    double res[] = { -1, 0, 1.3, 5.6 };
    size_t n_res = 4;

    mysort(arr, n, sizeof(int), comparator_double);
    // correct elements
    for (size_t i = 0; i < n_res; i++)
        ck_assert_int_eq(arr[i], res[i]);

}
END_TEST


// Функция создания набора тестов.
Suite *sort_suite_create(void)
{
    Suite *suite = suite_create("sort");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Core of example");

    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, increasing_order);
    tcase_add_test(tcase_core, decreasing_order);
    tcase_add_test(tcase_core, all_equal);
    tcase_add_test(tcase_core, single_element);
    tcase_add_test(tcase_core, random_elements);
    tcase_add_test(tcase_core, double_elements);

    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core);

    return suite;
}