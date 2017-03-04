#ifndef CSV_C
#define CSV_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include "args.h"

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
        if(line[i] == ',' || line[i] == '\0')
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
    char **columns = (char**)malloc(sizeof(char**) * 30);
    csv_start_columns(columns, 30);
    split_csv(string, columns, 30);

    int i;
    for (i = 0; i < 15; i++) {
        result->bols[atoi(columns[i + 3]) - 1] = 1;
        free(columns[i + 3]);
    }
    for (i = 18; i < 30; i++) {
        free(columns[i]);
    }

    free(columns[0]);
    free(columns[1]);
    free(columns[2]);
    free(columns);
    return result;
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
    struct Num *num = NULL;
    unsigned char line[650];
    
    while((fgets(line, 650, file)) != NULL)
    {
        if(line[0] == '*' ||  /* if line estarts with a *, this line is a comment */
                (line[0] == '"' && line[1] == '"')) { /* if line starts with "", will be ignored*/
            continue;
        }
        num = csv_new_num_from_string(line);
        node->add(node, num);
    }

    fclose(file);
}

#endif
/* vim: set expandtab tabstop=4 tabshift=4 :*/
