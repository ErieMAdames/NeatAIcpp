#include "layer.h"

Layer::Layer() {}
Layer::Layer(int id, LAYERTYPE type) : _id(id), layerType(type) {}

void Layer::insertNeuron(int neuronID) {
    _neuronIDs.push_back(neuronID);
}

const std::vector<int> Layer::getNeuronIDs() const {
    return _neuronIDs;
}

const int Layer::getId() const {
    return _id;
}

LAYERTYPE Layer::getLayerType() const {
    return layerType;
}