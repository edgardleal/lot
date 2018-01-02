#ifndef CSV_C
#define CSV_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include "app.h"

static const int COLUMNS_TO_SKIP = 2;
static const int COLUMNS_COLUMNS_COUNT = 17;
/** \fn
 * Setup each column string with an empty String with 4 blocks
 *
 */
extern void csv_start_columns(char** columns, int size)
{
    int i;
    for(i = 0; i < size; i = i + 1)
    {
        columns[i] = (char*)malloc(sizeof(char) * 5);
        strcpy(columns[i], "00");
    }
}

/** \fn
 *  \brief Split a csv string 
 *
 *  Split a a csv String and put each value separated by , in each 
 *  column.
 */
extern void split_csv(char *line, char **result, int columns_count)
{
    char buffer[200];
    buffer[0] = '\0';
    int i = 0, 
        j = 0, 
        len = strlen(line),
        columnCount = 0;
    for(i = 0; i <= len; i++){
        if(line[i] == ',' || line[i] == ';' || line[i] == '\0')
        {
            strcpy(result[columnCount], buffer);
            columnCount = columnCount + 1;
            if(columnCount >= columns_count)
                return;
            buffer[0] = '\0';
            j = 0;
        } else {
            if((j == 0 && line[i] == ' ') || (line[i] == '"' && (i == 0 || line[i - 1] != '\\')))
            {
                /*  Do nothing  */
            } else {
                buffer[j] = line[i];
                buffer[j + 1] = '\0';
                j++;
            }
        }
    } /* for */
}

/** \fn
 *  \brief Generate a Num from a String
 *
 *  Allocate memory for a new Num and filled the values 
 *  based on csv string passed.
 */
extern struct Num * csv_new_num_from_string(char *string)
{
    struct Num *result = newNum();
    char **columns = (char**) malloc(sizeof(char**) * COLUMNS_COLUMNS_COUNT);
    csv_start_columns(columns, COLUMNS_COLUMNS_COUNT);
    split_csv(string, columns, COLUMNS_COLUMNS_COUNT);

    int i, index, started = 0;
    for (i = 0; i < 15; i++) {
        index = atoi(columns[i + COLUMNS_TO_SKIP]) - 1;
        if (index < 0 || index > 24) {
            continue;
        }
        started = 1;
        result->balls[index] = 1;
        free(columns[i]);
    }

    free(columns);
    if (started) {
        return result;
    }
    free(result);
    return NULL;
}

/** \fn
 *  \brief Load results from a csv file
 *
 *  Load the results file ( ~/.lot/results.csv ) and 
 *  create a new Num for each result line in csv file.
 */
extern void csv_load_from_file(char *file_name, struct Node *node)
{
    if(access(file_name, R_OK) == -1)
    {
        die("The file [%s] dont exits!!!\n", file_name);
    }
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        die("Cant read the file [%s]\n", file_name);
    }
    debug("Loading file: %s\n", file_name);
    struct Num *num = NULL;
    unsigned char line[650];
    
    while((fgets(line, 650, file)) != NULL)
    {
        if(line[0] == '*' ||  /* if line estarts with a *, this line is a comment */
                (line[0] == '"' && line[1] == '"')) { /* if line starts with "", will be ignored*/
            continue;
        }
        num = csv_new_num_from_string(line);
        debug("Line read: [%s]\n", line);
        if (num != NULL) {
            node->add(node, num);
        } else {
            debug("This line is discarted.\n");
        }
    }

    debug("File loaded succefull !\n");
    fclose(file);
}

#endif
/* vim: set expandtab tabstop=4 tabshift=4 :*/
