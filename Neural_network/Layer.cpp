#include "Layer.h"


	Layer::Layer(int inputsNum, int neuronNum) {
		this->inputsNum = inputsNum;
		this->neuronNum = neuronNum;
		
		initLayer();
	}

	void Layer::initLayer() {
		w = new double*[neuronNum];
		for (int i = 0; i < neuronNum; i++) w[i] = new double[inputsNum];

		wT = new double*[inputsNum];
		for (int i = 0; i < inputsNum; i++) wT[i] = new double[neuronNum];

		b = new double[neuronNum];

		for (int i = 0; i < neuronNum; i++) {
			Layer::layerNeuron.push_back(Neuron(inputsNum, operative));
			w[i] = layerNeuron[i].getWeights();
			b[i] = layerNeuron[i].getBias();
		}
		wT = operative.Transpose(Layer::w, neuronNum, inputsNum);
		cout << "\n -- layer created";
	}

	void Layer::forwardLayer(double inputs[]) {
		this->inputs = inputs;

		z = new double[neuronNum];
		a = new double[neuronNum];
		da = new double[neuronNum];

		z = operative.z_calulate(inputs, w, b, inputsNum, neuronNum);
		a = operative.sigmoid(z, neuronNum);
		da = operative.sigmoid_Derivative(a, neuronNum);
	}

	void Layer::backwardLayer(double error[]) {
		delta = new double[neuronNum];
		for (int i = 0; i < neuronNum; i++) {
			delta[i] = error[i] * da[i];
		}
		computeLayerError();
	}

	void Layer::updateLayerParameters(double n) {
		for (int j = 0; j < neuronNum; j++) {
			b[j] -= n * delta[j];
			for (int i = 0; i < inputsNum; i++) {
				w[j][i] -= n * delta[j] * inputs[i];
			}
		}
	}

	void Layer::computeLayerError() {
		error = new double[inputsNum];
		for (int j = 0; j < inputsNum; j++) {
			for (int i = 0; i < neuronNum; i++) {
				error[j] += delta[i] * wT[j][i];
			}
		}
	}

	void Layer::getInfo() {
		for (int j = 0; j < neuronNum; j++) {
			cout << "\n";
			for (int i = 0; i < inputsNum; i++) {
				cout << "  -" << w[j][i];
			}
		}
		cout << "\n -- -------------------wt";
		for (int j = 0; j < inputsNum; j++) {
			cout << "\n";
			for (int i = 0; i < neuronNum; i++) {
				cout << "  -" << wT[j][i];
			}
		}
		cout << "\n -- -------------------bias";
		for (int i = 0; i < neuronNum; i++) {
			cout << "  -" << b[i];
		}
		cout << "\n -- -------------------z";
		for (int i = 0; i < neuronNum; i++) {
			cout << "  -" << z[i];
		}
		cout << "\n -- -------------------a";
		for (int i = 0; i < neuronNum; i++) {
			cout << "  -" << a[i];
		}
		cout << "\n -- -------------------da";
		for (int i = 0; i < neuronNum; i++) {
			cout << "  -" << da[i];
		}

		cout << "\n\n\n\n";
	}

	int Layer::getInputsNum() { return inputsNum; }
	int Layer::getNeuronNum() { return neuronNum; }

	double** Layer::getWeightsMatrix() { return w; }
	double** Layer::getWeightsT_Matrix() { return wT; }
	double* Layer::getBiasMatrix() { return b; }

	double* Layer::getZMatrix() { return z; }
	double* Layer::getAMatrix() { return a; }

	double* Layer::getA_derivative() { return da; }
	double* Layer::getDelta() { return delta; }
	double* Layer::getError() { return error; }

	vector<Neuron> Layer::getLayerNeuron() { return layerNeuron; }