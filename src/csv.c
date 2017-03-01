/**
 *
 * @author Edgard Leal <edgardleal@gmail.com> 
 * @language C
 * @libs stdio 
 *
 **/
#ifndef CSV_C
#define CSV_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void copy(char *dest, char *src);

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

static void copy(char *dest, char *src)
{
    int i;
    for (i = 0; i < 3; i++) 
    {
        dest[i] = src[i];
    }

}

extern void csv_start_columns(char** columns, int size)
{
    int i;
    for(i = 0; i < size; i = i + 1)
    {
        columns[i] = (char*)malloc(sizeof(char) * 4);
        /*
        columns[i] = "   ";
          */
    }
}

#endif
/* vim: set expandtab tabstop=4 tabshift=4 :*/
