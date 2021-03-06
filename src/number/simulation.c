/** \file simulation.c
 * 
 * \brief Gera uma simulacao dos seus numeros em cada sorteio registrado no historico
 * @author Edgard Leal <edgardleal@gmail.com> 
 *
 **/
#ifndef simulation_c
#define  simulation_c
#include "../args.h"
#include "../list.h"
#include "../app.h"
#include "../num.h"
#include "../csv.h"

static float reward_values[15] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    4,     /* 11 */
    8,     /* 12 */
    20,    /* 13 */
    1500,  /* 14 */
    500000 /* 15 */
};

void
simulation_report(void)
{
    struct Node *history = newTree();
    csv_load_from_file(config.RESULT_PATH, history);

    debug("Loading numbers from file...");
    struct Node *my_numbers = list_loadFromFile(config.MY_NUMBERS_FILE_NAME);
    struct Node *my_first = my_numbers;
    struct Node *history_walker = history, 
               *my_walker = my_numbers;

    int points_array[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int points = 0, index = 0, my_index = 0;
    float total = 0;
    do
    {
        index++;
        my_index = 0;
        do
        {
            my_index++;
            points = my_walker->current->compare(my_walker->current, history_walker->current);
            points_array[points - 1] = points_array[points - 1] + 1;
            total = reward_values[points - 1] + total - 2000;
            out("%4d - %2d - %d\n", index, my_index, points);
            my_walker = my_walker->next;
        } while(my_walker != NULL);
        my_walker = my_first;
        history_walker = history_walker->next;
    } while(history_walker != NULL);

    out("\n");
    out("+---------+------------+\n");
    out("| Acertos | Quantidade |\n");
    out("+---------+------------+\n");
    int i;
    for (i = 0; i < 15; i++)
    {
        out("| %7d | %10d |\n", i + 1, points_array[i]);

    }
    out("+---------+------------+\n");
    /*
    out("|---  %10.2f  -----|\n", total);
    out("+---------+------------+\n");
    */
    history->destroyAndClean(history);
    my_numbers->destroyAndClean(my_numbers);
}
#endif
/* vim: set expandtab tabstop=4 shiftwidth=4 :*/
