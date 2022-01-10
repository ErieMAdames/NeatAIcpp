#include "neuron.h"

Neuron::Neuron(int id, NEURONTYPE type, std::map<int, Neuron*>* neurons)
    : _id(id), neuronType(type), _neurons(neurons) {
    if (type == NEURONTYPE::nBIAS) {
        _value = 1;
    }
}

std::string Neuron::getNeuronTypeDesc() const {
    switch (neuronType) {
        case NEURONTYPE::nINPUT:
            return "input";
            break;
        case NEURONTYPE::nHIDDEN:
            return "hidden";
            break;
        case NEURONTYPE::nOUTPUT:
            return "output";
            break;
        default:
            return "bias";
    }
}
NEURONTYPE Neuron::getNeuronType() const { return neuronType; }

void Neuron::setWeight(int neuronId, double weight) {
    if (neuronType != NEURONTYPE::nINPUT && neuronType != NEURONTYPE::nBIAS) {
        _weights[neuronId] = weight;
    }
}

void Neuron::setWeights(std::map<int, double> weights) {
    if (neuronType != NEURONTYPE::nINPUT && neuronType != NEURONTYPE::nBIAS) {
        _weights = weights;
    }
}

const int Neuron::getNeuronID() const { return _id; }
void Neuron::setLayer(int layer) { _layer = layer; }

const std::map<int, double> Neuron::getWeights() const { return _weights; }

void Neuron::computeOutput() {
    if (neuronType != NEURONTYPE::nINPUT && neuronType != NEURONTYPE::nBIAS) {
        double acc = 0;
        for (const auto& [nodeID, weight] : _weights) {
            acc += (*_neurons)[nodeID]->getOutput() * weight;
        }
        _value = tanh(acc);
    }
}
void Neuron::setValue(double value) {
    if (neuronType == NEURONTYPE::nINPUT) {
        _value = value;
    }
}
double Neuron::getOutput() { return _value; }