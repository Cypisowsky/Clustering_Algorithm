//
// Created by Michał on 16.01.2025.
//

#include "BasicCrossoverAlgorithm.h"

#include <stdexcept>

#include "BasicMutationAlgorithm.h"

std::pair<NGrouppingChallenge::Individual, NGrouppingChallenge::Individual> NGroupingChallenge::BasicCrossoverAlgorithm::crossover(const NGrouppingChallenge::Individual &individual1, const NGrouppingChallenge::Individual &individual2, double chance) {

    auto result = individual1.getResult();
    auto result2 = individual2.getResult();
    if(result->size() != result2->size() || result->groupCount() != result2->groupCount() || individual1.getMutationFinder() != individual2.getMutationFinder()) {
        throw std::invalid_argument("Individuals must have the same size and group count");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> chanceDist(0.0, 1.0);

    if(chanceDist(gen) > chance) {
        return auto (individual1, individual2);
    }

    std::uniform_int_distribution<> elementDist(0, (int) result->size()-1);
    NGrouppingChallenge::Individual newIndividual(result, individual1.getMutationFinder(), individual1.getCrossoverFinder());
    NGrouppingChallenge::Individual newIndividual2(result2, individual1.getMutationFinder(), individual1.getCrossoverFinder());
    int position = elementDist(gen);

    for(int i=position; i<result->size(); i++) {
        newIndividual.getResult()->set(i, result2->get(i));
        newIndividual2.getResult()->set(i, result->get(i));
    }

    return auto (newIndividual, newIndividual2);
}

