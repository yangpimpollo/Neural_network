#include "Neuron.h"


	Neuron::Neuron(int inputsNum, Tools random) {
		this->inputsNum = inputsNum;

		

		w = new double[inputsNum];
		b = random.random();
		for (int i = 0; i < inputsNum; i++) {
			w[i] = random.random();
		}

	}

	double* Neuron::getWeights() { return w; }
	double Neuron::getBias() { return b; }