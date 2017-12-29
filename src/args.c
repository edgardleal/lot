/**
 *
 * @author Edgard Leal <edgardleal@gmail.com> 
 * @language C
 * @libs stdio 
 *
 **/
#ifndef ARGS_C
#define ARGS_C

#include <argp.h>
#include <stdlib.h>
#include <string.h>
#include "args.h"
#include "num.h"

struct config config;
extern void args_default()
{
    char *home = getenv("HOME");
    char data_path[155], 
         numbers_file_name[200], 
         results_file_name[200];
    data_path[0] = '\0';
    strcat(data_path, home);
    strcat(data_path, "/.lot/");

    strcpy(numbers_file_name, data_path);
    strcat(numbers_file_name, "mynumbers");

    strcpy(results_file_name, data_path);
    strcpy(results_file_name, "results.csv");
    debug("Defining [%s] as default result file.\n", results_file_name);

    config.LINE1 = 0;
    config.LINE2 = 0;
    config.LINE3 = 0;
    config.LINE4 = 0;
    config.LINE5 = 0;
    config.DEBUG = 0;
    config.LIMIT = MAX_NUMBER;
    config.LINE_LIMIT = 4;
    strcpy(config.MY_NUMBERS_FILE_NAME, numbers_file_name);
    strcpy(config.RESULT_PATH, results_file_name);
    config.SIMILARITY = 8;
    config.PRINT_REPORT = 0;

    debug("Creating the %s directory....\n", data_path);
    int result = mkdir(data_path, 0750);
    if(result)
    {
        debug("Canot create the data directory [%s] result = %d!!\n", data_path, result);
    }
    config.OUTPUT_FORMAT = "g";
    IS_DEBUG = 0;
}

extern error_t 
parse_opt(int key, char *arg, struct argp_state *state)
{
    long value;
    switch (key) {
        case 'd': 
            config.DEBUG = 1; 
            IS_DEBUG = 1;
            debug("Executing in debug mode\n");
            break;
        case 'l':
            value = strtol(arg, NULL, 0);
            if(value > MAX_NUMBER)
                value = MAX_NUMBER;
            debug("Using %ld as limit\n", value);
            config.LIMIT = value;
            break;
        case 'm':
            strcpy(config.MY_NUMBERS_FILE_NAME, arg);
            debug("Loading mynumbers from: [%s]\n", arg);
            break;
        case 'r':
            strcpy(config.RESULT_PATH, arg);
            debug("Loading result path from: [%s]\n", arg);
            break;
        case 'f':
            config.OUTPUT_FORMAT = arg;
            debug("Defining output format to: [%s]\n", arg);
            break;
        case 'n':
            config.LINE_LIMIT = atoi(arg);
            debug("Defining line limit to: [%s]\n", arg);
            break;
        case 's':
            config.SIMILARITY = atoi(arg);
            debug("Defining similarity to: [%s]\n", arg);
            break;
        case 'p':
            config.PRINT_REPORT = 1;
            debug("Will print the report soon ...\n");
            break;
        case ARGP_KEY_ARG: return 0;
        default: return ARGP_ERR_UNKNOWN;
    }   
    return 0;
}

#endif
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
