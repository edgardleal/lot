#ifndef CSV_C
#define CSV_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

extern void split_csv(char *line, char **result)
{
    char buffer[200];
    buffer[0] = '\0';
    int i = 0, 
        j = 0, 
        columnCount = 0;
    for(i = 0; i <= strlen(line); i++){
        if(line[i] == ',' || line[i] == '\0')
        {
            result[columnCount][0] = buffer[0];
            result[columnCount][1] = buffer[1];
            result[columnCount][2] = buffer[2];
            columnCount = columnCount + 1;
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

extern struct Num * csv_new_num_from_string(char *string)
{
    struct Num *result = newNum();
    char **columns = (char**)malloc(sizeof(char**) * 30);
    csv_start_columns(columns, 30);
    split_csv(string, columns);

    int i;
    for (i = 0; i < 15; i++) {
        result->bols[atoi(columns[i + 3]) - 1] = 1;
    }


    free(columns);
    return result;
}

extern void csv_load_from_file(char *file_name, struct Node *node)
{
    FILE *file = fopen(file_name, "r");
    struct Num *num = NULL;
    unsigned char line[250];
    
    while((fgets(line, 250, file)) != NULL)
    {
        if(line[0] == '*') {
            continue;
        }
        num = csv_new_num_from_string(line);
        node->add(node, num);
    }

    fclose(file);
}

/*!
 * Setup each column string with an empty String with 4 blocks
 *
 */
extern void csv_start_columns(char** columns, int size)
{
    int i;
    for(i = 0; i < size; i = i + 1)
    {
        columns[i] = (char*)malloc(sizeof(char) * 4);
    }
}

#endif
/* vim: set expandtab tabstop=4 tabshift=4 :*/
