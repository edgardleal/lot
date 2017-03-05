/** \file minunit.h 
 *  \brief A simple unit test framework 
 *  
 *  This file was based on original Minunit project https://github.com/siu/minunit.
 *  I made some modifications to keep it more like JUnit.
 */
#ifndef MINUNIT_H
#define MINUNIT_H
#define mu_assert(message, test) do { tests_run = tests_run + 1; print_test(test, message); if (!(test)){ \
    tests_error_count = tests_error_count + 1; \
    } } while (0)

#define out(text, args...) do { printf(text, ##args); } while(0)
#define ok(test, message, args...) do { tests_run = tests_run + 1;\
    char text[255]; sprintf(text, message, ##args);\
    print_test(test, text);\
    if (!(test)){\
        tests_error_count = tests_error_count + 1; \
    }} while (0)

#define assertok(test, message, var) do { char *text; sprintf(text, message, var); ok(test, text);} while (0)

/** \def mu_run_test(test)
 *  \brief Execute a test method
 *
 *  Run a test passed by name ( only name, not a pointer ) and use this name to register the 
 *  test and call it. 
 */
#define mu_run_test(test) do {test_module(#test); test();} while (0)
extern int tests_run;
extern int tests_error_count;

extern void print_test(int result, char * test);
extern void test_module(char *module);
extern void test_summary();

#endif
