//
// Created by Michal on 24.01.2025.
//

#include "StrictCompCrossoverAlgorithm.h"

#include <stdexcept>

std::pair<Individual *, Individual *> StrictCompCrossoverAlgorithm::crossover(Individual *individual1, Individual *individual2, double chance) {
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
    Individual* newIndividual = new Individual(*individual1);
    Individual* newIndividual2 = new Individual(*individual2);

    double limit = individual1->getFitness() + individual2->getFitness();

    bool done = false;

    int iter = 0;
    while(!done && iter < iterationLimit) {
        int position = elementDist(gen);

        for(int i=position; i<result->size(); i++) {
            auto temp = result->get(i);
            newIndividual->getResult()->set(i, result2->get(i));
            newIndividual2->getResult()->set(i, temp);
        }


        auto t = newIndividual->getFitness();
        auto t2 = newIndividual2->getFitness();
        if(newIndividual->getFitness()+newIndividual2->getFitness()<limit) {
            done = true;
        }
        iter++;
    }
    delete individual1;
    delete individual2;
    individual1 = newIndividual;
    individual2 = newIndividual2;

    return std::make_pair(individual1, individual2);
}
