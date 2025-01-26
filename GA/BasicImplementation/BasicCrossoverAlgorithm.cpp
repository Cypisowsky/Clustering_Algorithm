//
// Created by Michał on 16.01.2025.
//

#include "BasicCrossoverAlgorithm.h"

#include <stdexcept>

#include "BasicMutationAlgorithm.h"
#include "../Individual.h"

std::pair<Individual*, Individual*> BasicCrossoverAlgorithm::crossover(Individual *individual1, Individual *individual2, double chance) {

    auto result = individual1->getResult();
    auto result2 = individual2->getResult();

    if(result->size() != result2->size() || result->groupCount() != result2->groupCount() || individual1->getMutationFinder() != individual2->getMutationFinder()) {
        throw std::invalid_argument("Individuals must have the same size and group count");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> chanceDist(0.0, 1.0);

    if(chanceDist(gen) > chance) {
        // Individual* newIndividual = new Individual(individual1);
        // Individual* newIndividual2 = new Individual(individual2);
        return std::make_pair(individual1, individual2);
    }

    std::uniform_int_distribution<> elementDist(0, (int) result->size()-1);
    // Individual* newIndividual = new Individual(individual1);
    // Individual* newIndividual2 = new Individual(individual2);
    int position = elementDist(gen);

    for(int i=position; i<result->size(); i++) {
        auto temp = result->get(i);
        individual1->getResult()->set(i, result2->get(i));
        individual2->getResult()->set(i, temp);
    }

    return std::make_pair(individual1, individual2);
}

