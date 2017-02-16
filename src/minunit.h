 /* file: minunit.h */
#ifndef MINUNIT_H
#define MINUNIT_H
#define mu_assert(message, test) do { tests_run = tests_run + 1; print_test(test, message); if (!(test)){ \
    tests_error_count = tests_error_count + 1; \
    } } while (0)

#define ok(test, message) do { tests_run = tests_run + 1; print_test(test, message); if (!(test)){\
    tests_error_count = tests_error_count + 1; \
    }} while (0)

#define assertok(test, message, var) do { char *text; sprintf(text, message, var); ok(test, text);} while (0)

#define mu_run_test(test) do {test();} while (0)
 extern int tests_run;
 extern int tests_error_count;

 extern void print_test(int result, char * test);

#endif
