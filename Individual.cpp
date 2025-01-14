//
// Created by Michał on 13.01.2025.
//

#include "Individual.h"

#include <stdexcept>
#include <bits/random.h>


void NGrouppingChallenge::Individual::mutate(double chance) const {

    if(!result->mutate(chance)) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> chanceDist(0.0, 1.0);
        std::uniform_int_distribution<> groupDist(0, result->groupCount() - 1);

        for (int i = 0; i < result->size(); i++) {
            if (chanceDist(gen) < chance) {
                result->set(i, groupDist(gen));
            }
        }
    }
}

NGrouppingChallenge::Individual NGrouppingChallenge::Individual::crossover(NGrouppingChallenge::Individual &individual) {

    if(result->size() != individual.result->size() || result->groupCount() != individual.result->groupCount()) {
        throw std::invalid_argument("Individuals must have the same size and group count");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> elementDist(0, result->size()-1);
    Individual newIndividual(result);
    int position = elementDist(gen);

    for(int i=position; i<result->size(); i++) {
        newIndividual.result->set(i, individual.result->get(i));
    }

    return newIndividual;
}


