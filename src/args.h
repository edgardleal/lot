/** \file args.h
 *  \brief Parse and manager configurations 
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
 */
#ifndef ARGS_H
#define ARGS_H
#include <argp.h>

static char args_doc[] = "none";
static char description[] = "Lotofacil in C";

/** \struct Store the the possible options passed as command line args.
 * These options are show in help screen.
 *
 */
static struct argp_option options[] = {
    {"debug",      'd', 0, 0, "Execute in debug mode"},
    {"append",     'a', 0, 0, "Append generated numbers to ~/.lot/mynumbers file"},
    {"simulation", 't', 0, 0, "Exibe quanto voce ganharia em cada sorteio passado"},
    {"format",     'f', "format", 0, "Output format, should be b for binary, g for geometric and l for inline"},
    {"limit",      'l', "limit", 0, "Define the max numbers generated"},
    {"llimit",     'n', "lineLimit", 0, "This is the limit of numbers by line in geometric form"},
    {"my",         'm', "myNumbers", 0, "The file path to your saved numbers in csv format"},
    {"report",     'p', 0, 0, "Print a analitics report over the results dataset."},
    {"result",     'r', "result", 0, "The path of csv result"},
    {"similarity", 's', "similarity", 0, "How many the numbers has similarities, how they are equals."},
    {"command",    'c', "command", 0, "The command to run"},
    {0}
};

/** \struct
 * Store the defaults options and modified option by command line arguments passed by the user.
 *
 */
struct config {
    int LINE1;
    int LINE2;
    int LINE3;
    int LINE4;
    int LINE5;
    int DEBUG;
    int LINE_LIMIT;
    char SIMULATION;
    int SIMILARITY;
    char MY_NUMBERS_FILE_NAME[250];
    char *OUTPUT_FORMAT;
    char RESULT_PATH[250];
    char PRINT_REPORT;
    long LIMIT;
};

extern struct config config;

extern error_t 
parse_opt(int, char *, struct argp_state*);
void args_default(void);

static struct argp argp = { 
    options, 
    parse_opt, 
    args_doc, 
    description, 0, 0, 0 
};

#endif
