#include <iostream>
#include <map>
#include <vector>

#include "layer.cpp"
#include "neuralNet.cpp"
#include "neuron.cpp"

void print_mapconst(std::map<int, double> m) {
    for (const auto &[key, value] : m) {
        std::cout << key << " = " << value << "; ";
    }
    std::cout << "\n";
}

void print_neurons(std::map<int, Neuron *> neurons) {
    for (const auto &[key, value] : neurons) {
        NEURONTYPE nt = value->getNeuronType();
        if (nt == NEURONTYPE::nINPUT) {
            std::cout << value->getNeuronTypeDesc()
                      << "\nid : " << value->getNeuronID() << "\n";
            std::cout << "value : " << value->getOutput() << "\n";
        } else if (nt == NEURONTYPE::nHIDDEN) {
            std::cout << value->getNeuronTypeDesc()
                      << "\nid : " << value->getNeuronID() << "\n";
            std::cout << "value : " << value->getOutput() << "\n";
            print_mapconst(value->getWeights());
        } else if (nt == NEURONTYPE::nOUTPUT) {
            std::cout << value->getNeuronTypeDesc()
                      << "\nid : " << value->getNeuronID() << "\n";
            std::cout << "value : " << value->getOutput() << "\n";
            print_mapconst(value->getWeights());
        } else {
            std::cout << value->getNeuronTypeDesc()
                      << "\nid : " << value->getNeuronID() << "\n";
            std::cout << "value : " << value->getOutput() << "\n";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void print_output(std::map<int, Neuron *> neurons) {
    for (const auto &[key, value] : neurons) {
        NEURONTYPE nt = value->getNeuronType();
        if (nt == NEURONTYPE::nOUTPUT) {
            std::cout << value->getNeuronTypeDesc()
                      << "\nid : " << value->getNeuronID() << "\n";
            std::cout << "value : " << value->getOutput() << "\n";
        }
        std::cout << "\n";
    }
}

int main() {
    NeuralNet nn;
    nn.initNeuralNet(3, 5);
    std::map<int, double> inputs;
    inputs[0] = .5;
    inputs[1] = -.5;
    inputs[3] = 0;
    nn.getOutputs(inputs);
    std::cout << "1";
    print_output(nn.getNeurons());
    inputs[0] = nn.getRandomWeight();
    inputs[1] = nn.getRandomWeight();
    inputs[3] = nn.getRandomWeight();
    nn.getOutputs(inputs);
    std::cout << "2";
    print_output(nn.getNeurons());
    inputs[0] = nn.getRandomWeight();
    inputs[1] = nn.getRandomWeight();
    inputs[3] = nn.getRandomWeight();
    nn.getOutputs(inputs);
    std::cout << "3";
    print_output(nn.getNeurons());
    inputs[0] = nn.getRandomWeight();
    inputs[1] = nn.getRandomWeight();
    inputs[3] = nn.getRandomWeight();
    nn.getOutputs(inputs);
    std::cout << "4";
    print_output(nn.getNeurons());
}