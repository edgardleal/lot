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

extern void args_default(struct config *config)
{
    config->LINE1 = 0;
    config->LINE2 = 0;
    config->LINE3 = 0;
    config->LINE4 = 0;
    config->LINE5 = 0;
    config->DEBUG = 0;
    config->LIMIT = MAX_NUMBER;
    IS_DEBUG = 0;
}

extern error_t 
parse_opt(int key, char *arg, struct argp_state *state)
{
    struct config *arguments = state->input;
    long value;
    switch (key) {
        case 'd': 
            arguments->DEBUG = 1; 
            IS_DEBUG = 1;
            break;
        case 'l':
            value = strtol(arg, NULL, 0);
            if(value > MAX_NUMBER)
                value = MAX_NUMBER;
            debug("Using %ld as limit\n", value);
            arguments->LIMIT = value;
            break;
        case ARGP_KEY_ARG: return 0;
        default: return ARGP_ERR_UNKNOWN;
    }   
    return 0;
}

#endif
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
