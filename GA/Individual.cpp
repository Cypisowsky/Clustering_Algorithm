//
// Created by Michał on 13.01.2025.
//

#include "Individual.h"

#include <stdexcept>
#include <bits/random.h>



Individual::Individual(IResultEncoder<int> *result_encoder, IMutationFinder *mutation_finder, ICrossoverFinder *crossover_finder) {
    this->result = result_encoder;
    this->mutationFinder = mutation_finder;
    this->crossoverFinder = crossover_finder;
}


std::pair<Individual*, Individual*> Individual::crossover(Individual &individual, const double chance) {
    return crossoverFinder->crossover(*this, individual, chance);
}

void Individual::mutate(double chance) {
    mutationFinder->mutate(*this, chance);
}

Individual &Individual::operator=(Individual &&individual) noexcept {
    delete result;
    this->result = std::move(individual.result);
    individual.result = nullptr;
    this->mutationFinder = individual.getMutationFinder();
    individual.mutationFinder = nullptr;
    this->crossoverFinder = individual.getCrossoverFinder();
    individual.crossoverFinder = nullptr;
    return *this;
}
