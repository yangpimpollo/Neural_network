#include <iostream>
#include "hello.h"
#include "application.h"

#include "Neuron.h"
#include "Layer.h"
#include "Neural_network.h"

using namespace std;

double data_in[][2] = { { 1, 2 }, { 1, 0 }, { 0, 1 }, { 0, 0 } };
double data_out[][1] = { { 1 }, { 0 }, { 0 }, { 1 } };

double data_in3[][2] = { { 1, 1 }, { 1, 0 }, { 0, 1 }, { 0, 0 } };
double data_out3[][2] = { { 0, 0 }, { 0, 1 }, { 0, 1 }, { 0, 0 } };

int main()
{
    int neuronsNum[] = { 2, 3, 2 };

    Neural_network nn(2, 2, neuronsNum, 0.3);

    //nn.forwardNeuralNetwork(data_in[0]);
    //nn.backwardNeuralNetwork(data_out[0]);

    double err = 999;
    int count = 0;
    while (err > 0.01) {
        double en = 0;
        for (int i = 0; i < 4; i++) {
            en += nn.trainNeuralNetwork(data_in3[i], data_out3[i]);
            
        }
        err = en / 4;/// 4;
        cout << endl << (err);
        count++;
    }
    cout << "\n";
    cout << "\n veces: " << count;










    /*Application app;

    hello();
    app.start();*/
    //Application bb;
    //Neuron no(5);
    //cout << "-- " << no.getWeights()[0] << endl;

    /*for (int i = 0; i < 5; i++) {
        cout << "-- " << no.getWeights()[i]<< endl;
    }

    cout << "-- bias" << no.getBias() << endl;*/

    /*double input[] = { 2, 1 };
    Layer ll(2, 2); ll.forwardLayer(input); ll.getInfo();*/
}