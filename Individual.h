//
// Created by Michał on 13.01.2025.
//

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "IResultEncoder.h"


namespace NGrouppingChallenge {
class Individual {

    public:
        explicit Individual(NGroupingChallenge::IResultEncoder<int>* result_encoder) {this->result = result_encoder;};

        ~Individual() {delete result;};

        Individual(const Individual& individual) {this->result = new NGroupingChallenge::IResultEncoder<int>(*individual.result);}

        Individual(Individual&& individual) noexcept {this->result = individual.result; individual.result = nullptr;};

        Individual crossover(NGrouppingChallenge::Individual &individual);

        void mutate(double chance) const;

        int getFitness() const {return result->getFitness();};

    private:
        NGroupingChallenge::IResultEncoder<int>* result;


    };
}



#endif //INDIVIDUAL_H
