#pragma once
#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_

#include <iostream>
#include <vector>
#include <math.h>
#include "Layer.h"

using namespace std;

class Neural_network {
	private:
		vector<Layer> all_Layers;
		double n;
		int input0_Num;
		int output1_Num;
		int layersNum;
		int *neuronsNum;

		double *outputMatrix;
		double *errorMatrix;
		double total_Error;

		void initNeural_network();

	public:
		Neural_network(int input0_Num, int layersNum, int neuronsNum[], double n);
		double trainNeuralNetwork(double input[], double data[]);
		void forwardNeuralNetwork(double input0[]);
		void backwardNeuralNetwork(double data[]);
		void updateParameters();
		void computeError(double data[]);


};

#endif