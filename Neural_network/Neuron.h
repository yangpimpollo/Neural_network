#pragma once
#ifndef _NEURON_H_
#define _NEURON_H_

#include <iostream>
#include "Tools.h"

using namespace std;

class Neuron {
	private:
		int inputsNum;
		double *w;
		double b;

	public:
		Neuron(int inputsNum, Tools random);
		double *getWeights();
		double getBias();
};

#endif
