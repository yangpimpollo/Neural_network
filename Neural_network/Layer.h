#pragma once
#ifndef _LAYER_H_
#define _LAYER_H_

#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Tools.h"

using namespace std;

class Layer {
	private:
		Tools operative;
		vector<Neuron> layerNeuron;
		int inputsNum;
		int neuronNum;
		double **w;
		double **wT;
		double *b;
		double *inputs;
		double *z;
		double *a;
		double *da;
		double *delta;
		double *error;

		void initLayer();


	public:
		Layer(int inputsNum, int neuronNum);
	
		void forwardLayer(double inputs[]);
		void backwardLayer(double error[]);
		void updateLayerParameters(double n);
		void computeLayerError(); 
		
		void getInfo();

		int getInputsNum();
		int getNeuronNum();
		double** getWeightsMatrix();
		double** getWeightsT_Matrix();
		double* getBiasMatrix();
		double* getZMatrix();
		double* getAMatrix();
		double* getA_derivative();
		double* getDelta();
		double* getError();

		vector<Neuron> getLayerNeuron();

};


#endif
