/*! \file csv.h
 * =====================================================================================
 *
 *       Filename:  csv.h
 *       \brief     Load contents to csv files 
 *
 *    Description:  Define functions for csv file proccess
 *
 *        Version:  1.0
 *        Created:  01-03-2017 18:53:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Edgard Leal
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef CSV_H
#define CSV_H
#include <stdio.h>
#include <stdlib.h>

extern void split_csv(char *, char**);
extern void csv_start_columns(char**, int);
/* 
 * \fn Load results from a csv file using this format: 
 * `"ID","Concurso","Data.Sorteio","Bola1","Bola2","Bola3","Bola4","Bola5","Bola6","Bola7","Bola8","Bola9","Bola10","Bola11","Bola12","Bola13","Bola14","Bola15","Arrecadacao_Total","Ganhadores_15_N_meros","Cidade","Ganhadores_14_N_meros","Ganhadores_13_N_meros","Ganhadores_12_N_meros","Ganhadores_11_N_meros","Valor_Rateio_15_N_meros","Valor_Rateio_14_N_meros","Valor_Rateio_13_N_meros","Valor_Rateio_12_N_meros","Valor_Rateio_11_N_meros","Acumulado_15_N_meros","Estimativa_Premio","Valor_Acumulado_Especial"`
 *
 */
extern void csv_load_from_file(char *, struct Node *);

/* \fn Create a new struct Num based on csv data 
 * in the string parameter. 
 */
extern struct Num * csv_new_num_from_string(char *);

#endif
/* vim: set expandtab tabstop=4 :*/
