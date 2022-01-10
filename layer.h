#ifndef LAYER
#define LAYER

#include <vector>

#include "neuron.h"

enum LAYERTYPE { INPUT, HIDDEN, OUTPUT };

class Layer {
   public:
    Layer();
    Layer(int id, LAYERTYPE type);
    void insertNeuron(int neuronID);
    const std::vector<int> getNeuronIDs() const;
    const int getId() const;
    LAYERTYPE getLayerType() const;

   private:
    std::vector<int> _neuronIDs;
    int _id;
    LAYERTYPE layerType;
};

#endif