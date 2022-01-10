#include "neuralNet.h"
NeuralNet::NeuralNet() { unif = std::uniform_real_distribution<double>(1, -1); }

void NeuralNet::initNeuralNet(int numInputs, int numOutputs) {
    Layer inputLayer(layerIdCounter, LAYERTYPE::INPUT);
    layerIdCounter++;
    for (int i = 0; i < numInputs; i++) {
        Neuron *in = new Neuron(neuronIdCounter, NEURONTYPE::nINPUT, &_neurons);
        in->setLayer(0);
        inputLayer.insertNeuron(neuronIdCounter);
        _neurons[neuronIdCounter] = in;
        neuronIdCounter++;
    }
    Neuron *inputBiasNeuron = new Neuron(neuronIdCounter, NEURONTYPE::nBIAS, &_neurons);
    inputBiasNeuron->setLayer(0);
    inputLayer.insertNeuron(neuronIdCounter);
    _neurons[neuronIdCounter] = inputBiasNeuron;
    neuronIdCounter++;

    Layer outputLayer(layerIdCounter, LAYERTYPE::OUTPUT);
    layerIdCounter++;
    for (int i = 1; i <= numOutputs; i++) {
        Neuron *in =
            new Neuron(neuronIdCounter, NEURONTYPE::nOUTPUT, &_neurons);
        for (int j = 0; j <= numInputs; j++) {
            in->setWeight(j, getRandomWeight());
        }
        outputLayer.insertNeuron(neuronIdCounter);
        _neurons[neuronIdCounter] = in;
        neuronIdCounter++;
    }
    _layers[0] = inputLayer;
    _layers[1] = outputLayer;
}

std::map<int, Layer> NeuralNet::getLayers() const { return _layers; }
std::map<int, Neuron *> NeuralNet::getNeurons() const { return _neurons; }

double NeuralNet::getRandomWeight() { return unif(re); }

std::map<int, double> NeuralNet::getOutputs(std::map<int, double> inputs) {
    for (const auto &[nodeID, input] : inputs) {
        _neurons[nodeID]->setValue(input);
    }
    for (int layer = 1; layer < layerIdCounter; layer++) {
        Layer currentLayer = _layers[layer];
        for (int nodeID : currentLayer.getNeuronIDs()) {
            _neurons[nodeID]->computeOutput();
        }
    }
    Layer outputLayer = _layers[layerIdCounter - 1];
    std::map<int, double> outputs;
    for (int nodeID : outputLayer.getNeuronIDs()) {
        outputs[nodeID] = _neurons[nodeID]->getOutput();
    }
    return outputs;
}