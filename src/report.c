#ifndef REPORT_C
#define REPORT_C
#include <stdlib.h>
#include "report.h"
#include "app.h"
#define max(a, b) a>b?a:b;

char *COLOR_SCALE[10] = {
    GIT_COLOR_BOLD_BLUE,
    GIT_COLOR_BLUE,
    GIT_COLOR_BOLD_GREEN,
    GIT_COLOR_GREEN,
    GIT_COLOR_BOLD_YELLOW,
    GIT_COLOR_YELLOW,
    GIT_COLOR_BOLD_MAGENTA,
    GIT_COLOR_MAGENTA,
    GIT_COLOR_BOLD_RED,
    GIT_COLOR_RED
};

void fill_most_used(struct Node *node, struct MostUsed *data)
{
    struct Node *tmp = node;
    int i,
        lineIndex = 0,
        total = 0;
    // TODO: count lines
    // TODO: count columns 
    do {
        total++;
        for (i = 0; i < 25; i++) {
            if ((i + 1) % 5 == 0 && lineIndex < 5) 
            {
                lineIndex += 1;
            }
            data->lines[lineIndex] += tmp->current->balls[i];
            data->balls[i] += 
                tmp->current->balls[i];
        }
        tmp = tmp->next;
    } while(tmp != NULL);

    for (i = 0; i < 5;  i++) {
        data->lines[i] = (int)(data->lines[i] / total);
    }

    for (i = 0; i < 25; i++) {
        if(data->balls[i] > data->max)
        {
            data->max = data->balls[i];
        }
        if(data->balls[i] < data->min)
        {
            data->min = data->balls[i];
        }
    }
}

extern struct MostUsed *newMostUsed()
{
    struct MostUsed *result = malloc(sizeof(struct MostUsed));
    result->min = 9999;
    result->max = 0;
    int i;
    for (i = 0; i < 25; i++) {
        result->balls[i] = 0;
    }
    for (i = 0; i < 5; i++) {
        result->cols[i] = 0;
        result->lines[i] = 0;
    }

    return result;
}

char *color_for_ratio(int min, int max, int value)
{
    /*
     *  TODO: review
     */
    if(value <= min)
        return COLOR_SCALE[0];
    int v = max - min;
    int index = (int)((value - min) / (v / 10.0));
    debug("Index = %d\n", index);
    index = max(index, 9);
    return COLOR_SCALE[index - 1];
}

void print_most_used(struct MostUsed *data)
{
    int i;
    char space;
    char *space2;
    out("Min: %d\n", data->min);
    out("Max: %d\n", data->max);
    for (i = 0; i < 25; i++) {
        if((i + 1) % 5 == 0)
            space = '\n';
        else
            space = ' ';
        if(i < 9)
            space2 = " ";
        else
            space2 = "";

        out("%s%s%d%s%c", 
                color_for_ratio(data->min, data->max, data->balls[i]), 
                space2,
                i + 1, 
                GIT_COLOR_RESET, 
                space);
    }
    out("\n----------------------------------------\n");
    for (i = 0; i < 25; i++) {
        out("%s%d - %d\n", i  < 9 ? "0" : "", i + 1, data->balls[i]);
    }
    out("\n----------------------------------------\n");
    for (i = 0; i < 5; i++) {
        out("Linha %d -> %d\n", i + 1, data->lines[i]);
    }
    out("\n----------------------------------------\n");
    for (i = 0; i < 5; i++) {
        out("Coluna %d -> %d\n", i + 1, data->cols[i]);
    }
    out("\n----------------------------------------\n");
}
#endif
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
