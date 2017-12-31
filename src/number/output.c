/** \file 
 * 
 * \brief Description 
 * @author Edgard Leal <edgardleal@gmail.com> 
 *
 **/
#ifndef output_c
#define output_c 

#include <stdio.h>
#include "../lang.h"
#include "../num.h"

void output_num_graph(struct Num *num, char* text)
{
    sprintf(text, "%s %s %s %s %s\n%s %s %s %s %s\n%s %s %s %s %s\n%s %s %s %s %s\n%s %s %s %s %s\n\n",
        iff(num->balls[0], " 1", "  "),
        iff(num->balls[1], " 2", "  "),
        iff(num->balls[2], " 3", "  "),
        iff(num->balls[3], " 4", "  "),
        iff(num->balls[4], " 5", "  "),
        iff(num->balls[5], " 6", "  "),
        iff(num->balls[6], " 7", "  "),
        iff(num->balls[7], " 8", "  "),
        iff(num->balls[8], " 9", "  "),
        iff(num->balls[9], "10", "  "),
        iff(num->balls[10],"11", "  "),
        iff(num->balls[11],"12", "  "),
        iff(num->balls[12],"13", "  "),
        iff(num->balls[13],"14", "  "),
        iff(num->balls[14],"15", "  "),
        iff(num->balls[15],"16", "  "),
        iff(num->balls[16],"17", "  "),
        iff(num->balls[17],"18", "  "),
        iff(num->balls[18],"19", "  "),
        iff(num->balls[19],"20", "  "),
        iff(num->balls[20],"21", "  "),
        iff(num->balls[21],"22", "  "),
        iff(num->balls[22],"23", "  "),
        iff(num->balls[23],"24", "  "),
        iff(num->balls[24],"25", "  "));
        
}

void output_num_binary(struct Num *num, char* text)
{
    sprintf(text, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
        num->balls[0],
        num->balls[1],
        num->balls[2],
        num->balls[3],
        num->balls[4],
        num->balls[5],
        num->balls[6],
        num->balls[7],
        num->balls[8],
        num->balls[9],
        num->balls[10],
        num->balls[11],
        num->balls[12],
        num->balls[13],
        num->balls[14],
        num->balls[15],
        num->balls[16],
        num->balls[17],
        num->balls[18],
        num->balls[19],
        num->balls[20],
        num->balls[21],
        num->balls[22],
        num->balls[23],
        num->balls[24]);
}

void output_num_csv(struct Num *num, char* text)
{
    sprintf(text, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
        num->balls[0],
        num->balls[1],
        num->balls[2],
        num->balls[3],
        num->balls[4],
        num->balls[5],
        num->balls[6],
        num->balls[7],
        num->balls[8],
        num->balls[9],
        num->balls[10],
        num->balls[11],
        num->balls[12],
        num->balls[13],
        num->balls[14],
        num->balls[15],
        num->balls[16],
        num->balls[17],
        num->balls[18],
        num->balls[19],
        num->balls[20],
        num->balls[21],
        num->balls[22],
        num->balls[23],
        num->balls[24]);
}

void output_num_simple(struct Num *num, char* text)
{
    sprintf(text, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",
        iff(num->balls[0], "  1", ""),
        iff(num->balls[1], "  2", ""),
        iff(num->balls[2], "  3", ""),
        iff(num->balls[3], "  4", ""),
        iff(num->balls[4], "  5", ""),
        iff(num->balls[5], "  6", ""),
        iff(num->balls[6], "  7", ""),
        iff(num->balls[7], "  8", ""),
        iff(num->balls[8], "  9", ""),
        iff(num->balls[9], " 10", ""),
        iff(num->balls[10]," 11", ""),
        iff(num->balls[11]," 12", ""),
        iff(num->balls[12]," 13", ""),
        iff(num->balls[13]," 14", ""),
        iff(num->balls[14]," 15", ""),
        iff(num->balls[15]," 16", ""),
        iff(num->balls[16]," 17", ""),
        iff(num->balls[17]," 18", ""),
        iff(num->balls[18]," 19", ""),
        iff(num->balls[19]," 20", ""),
        iff(num->balls[20]," 21", ""),
        iff(num->balls[21]," 22", ""),
        iff(num->balls[22]," 23", ""),
        iff(num->balls[23]," 24", ""),
        iff(num->balls[24]," 25", ""));
}

#endif
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
