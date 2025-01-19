//
// Created by Michał on 16.01.2025.
//

#include "BasicMutationAlgorithm.h"

#include "BasicGeneticAlgorithm.h"

void NGrouppingChallenge::BasicMutationAlgorithm::mutate(NGrouppingChallenge::Individual &individual, double chance) {
    auto result = individual.getResult();
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

double NGroupingChallenge::BasicGeneticAlgorithm::getBestFitness() {

    double bestFitness = individuals[0]->getFitness();
    for(int i=1; i<individuals.size(); i++) {
        if(individuals[i]->getFitness() > bestFitness) {
            bestFitness = individuals[i]->getFitness();
        }
    }
    return bestFitness;
}

