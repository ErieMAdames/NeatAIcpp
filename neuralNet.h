#ifndef NEURALNET
#define NEURALNET
#include <map>
#include <random>

#include "layer.h"
#include "neuron.h"

class NeuralNet {
   public:
    NeuralNet();
    void initNeuralNet(int numInputs, int numOutputs);
    std::map<int, Layer> getLayers() const;
    std::map<int, Neuron *> getNeurons() const;
    std::map<int, double> getOutputs(std::map<int, double> inputs);
    double getRandomWeight();

   private:
    std::map<int, Layer> _layers;
    std::map<int, Neuron *> _neurons;
    int layerIdCounter = 0;
    int neuronIdCounter = 0;

    std::uniform_real_distribution<double> unif;
    std::default_random_engine re;
};

#endif