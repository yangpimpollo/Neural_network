#include "Neural_network.h"


    Neural_network::Neural_network(int input0_Num, int layersNum, int neuronsNum[], double n) {
        this->input0_Num = input0_Num;
        this->layersNum = layersNum;
        this->neuronsNum = neuronsNum;
        this->n = n;

        initNeural_network();
	}

    void Neural_network::initNeural_network() {
        for (int i = 0; i < layersNum; i++) {
            int in0 = (i == 0) ? input0_Num : neuronsNum[i - 1];
            Neural_network::all_Layers.push_back(Layer(in0, neuronsNum[i]));
        }
        output1_Num = neuronsNum[layersNum - 1];
    }

    double Neural_network::trainNeuralNetwork(double input[], double data[]) {
        forwardNeuralNetwork(input);
        backwardNeuralNetwork(data);
        updateParameters();
        return total_Error;
    }

    void Neural_network::forwardNeuralNetwork(double input0[]) {
        for (int i = 0; i < layersNum; i++) {
            double *preInputs = (i == 0) ? input0 : all_Layers[i - 1].getAMatrix();
            all_Layers[i].forwardLayer(preInputs);
        }
    }

    void Neural_network::backwardNeuralNetwork(double data[]) {
        computeError(data);
        double *Error = errorMatrix;
        for (int i = layersNum - 1; i >= 0; i--) {
            all_Layers[i].backwardLayer(Error);
            Error = all_Layers[i].getError();
        }
    }

    void Neural_network::updateParameters() {
        for (int i = 0; i < layersNum; i++) {
            all_Layers[i].updateLayerParameters(n);
        }
    }

    void Neural_network::computeError(double data[]) {
        total_Error = 0;
        outputMatrix = new double[output1_Num];
        errorMatrix = new double[output1_Num];
        outputMatrix = all_Layers[layersNum - 1].getAMatrix();

        for (int i = 0; i < output1_Num; i++) {
            errorMatrix[i] = outputMatrix[i] - data[i];
            total_Error += 0.5 * pow(errorMatrix[i], 2);
        }
    }