#ifndef NEURON
#define NEURON

#include <math.h>

#include <map>
#include <string>

enum NEURONTYPE { nINPUT, nHIDDEN, nOUTPUT, nBIAS };

class Neuron {
   public:
    Neuron(int id, NEURONTYPE type, std::map<int, Neuron*>* neurons);
    std::string getNeuronTypeDesc() const;
    NEURONTYPE getNeuronType() const;
    const int getNeuronID() const;
    void setWeight(int neuronId, double weight);
    void setWeights(std::map<int, double> weights);
    void setLayer(int layer);
    const std::map<int, double> getWeights() const;
    void computeOutput();
    double getOutput();
    void setValue(double value);

   private:
    NEURONTYPE neuronType;
    int _layer;
    int _id;
    double _value = 1.0;
    std::map<int, double> _weights = std::map<int, double>();
    std::map<int, Neuron*>* _neurons;
};

#endif