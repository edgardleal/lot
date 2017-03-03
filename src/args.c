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
#include "args.h"
#include "num.h"

struct config config;
extern void args_default()
{
    config.LINE1 = 0;
    config.LINE2 = 0;
    config.LINE3 = 0;
    config.LINE4 = 0;
    config.LINE5 = 0;
    config.DEBUG = 0;
    config.LIMIT = MAX_NUMBER;
    config.MY_NUMBERS_FILE_NAME = "~/.lot/mynumbers";
    mkdir("~/.lot", 0775);
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
            config.MY_NUMBERS_FILE_NAME = arg;
            debug("Loading mynumbers from: [%s]\n", arg);
            break;
        case 'f':
            config.OUTPUT_FORMAT = arg;
            debug("Defining output format to: [%s]\n", arg);
            break;
        case ARGP_KEY_ARG: return 0;
        default: return ARGP_ERR_UNKNOWN;
    }   
    return 0;
}

#endif
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
