/*
 * =====================================================================================
 *
 *       Filename:  args.h
 *
 *    Description:  Parser and manager arguments passed for an application
 *
 *        Version:  1.0
 *        Created:  22-02-2017 21:43:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Edgard Leal (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef ARGS_H
#define ARGS_H
#include <argp.h>
#define debug(text, args...) do { if(IS_DEBUG)printf(text, ##args); } while(0)

static char args_doc[] = "none";
static char description[] = "Lotofacil in C";
static struct argp_option options[] = {
    {"debug", 'd', 0, 0, "Execute in debug mode"},
    {"limit", 'l', "limit", 0, "Define the max numbers generated"},
    {"my", 'm', "myNumbers", 0, "The file path to your saved numbers in csv format"},
    {"format", 'f', "format", 0, "Output format, should be b for binary, g for geometric and l for inline"},
    {0}
};
int IS_DEBUG;

extern struct config {
    int LINE1;
    int LINE2;
    int LINE3;
    int LINE4;
    int LINE5;
    int DEBUG;
    char *MY_NUMBERS_FILE_NAME;
    char *OUTPUT_FORMAT;
    long LIMIT;
};

extern struct config config;

extern error_t 
parse_opt(int, char *, struct argp_state*);
extern void args_default(void);

static struct argp argp = { 
    options, 
    parse_opt, 
    args_doc, 
    description, 0, 0, 0 
};

#endif
