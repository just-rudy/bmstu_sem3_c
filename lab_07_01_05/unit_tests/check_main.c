#include <stdlib.h>
#include <check.h>

Suite *sort_suite_create(void);
Suite *key_suite_create(void);

int main(void)
{
    Suite *suite_sort = sort_suite_create(), *suite_key = key_suite_create();
    SRunner *suite_runner_sort = srunner_create(suite_sort), *suite_runner_key = srunner_create(suite_key);
    int failed_count = 0;

    srunner_run_all(suite_runner_sort, CK_NORMAL);
    // Получаем количество проваленных тестов.
    failed_count += srunner_ntests_failed(suite_runner_sort);
    srunner_free(suite_runner_sort);

    srunner_run_all(suite_runner_key, CK_NORMAL);
    // Получаем количество проваленных тестов.
    failed_count += srunner_ntests_failed(suite_runner_key);
    srunner_free(suite_runner_key);
    
    if (failed_count != 0) {
        // Сигнализируем о том, что тестирование прошло неудачно.
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}