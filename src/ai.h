/** \file ai.h
 * 
 * \brief This file uses Genann project to train Artificial Neural Network
 * @author Edgard Leal <edgardleal@gmail.com> 
 *
 **/
#ifndef AI_C
#define AI_C

#include "genann/genann.h"
#include "num.h"

/*  Not shown, loading your training and test data. */
double **training_data_input, **training_data_output, **test_data_input;

genann ai_load_from_file(char*);
void ai_save_to_file(char*, genann);
void ai_learn();

/**  New network with 2 inputs,
 * 1 hidden layer of 3 neurons each,
 * and 2 outputs. 
genann *ann = genann_init(25, 5, 35, 25);

Learn on the training set. 
for (i = 0; i < 300; ++i) {
    for (j = 0; j < 100; ++j)
        genann_train(ann, training_data_input[j], training_data_output[j], 0.1);
}

Run the network and see what it predicts. 
double const *prediction = genann_run(ann, test_data_input[0]);
printf("Output for the first test data point is: %f, %f\n", prediction[0], prediction[1]);

genann_free(ann);
*/

#endif
