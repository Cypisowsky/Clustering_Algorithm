//
// Created by Michal on 25.01.2025.
//

#include "WideSearchParentChooser.h"

std::vector<std::pair<Individual*,Individual*>> WideSearchParentChooser::chooseParents(std::vector<Individual*> individuals) {
    std::vector<std::pair<Individual*,Individual*>> parents;
    for(int i=0; i<individuals.size()/2; i++) {
        auto ind1 = individuals[generateRandomIndex(0, individuals.size()-1)];
        auto ind2 = individuals[generateRandomIndex(0, individuals.size()-1)];

        parents.emplace_back(new Individual(*ind1), new Individual(*ind2));
    }
    return parents;
}

size_t WideSearchParentChooser::generateRandomIndex(const size_t low, const size_t high) {
    std::random_device rd;
    randomEngine.seed(rd());
    std::uniform_int_distribution<> dis(low, high);

    return dis(randomEngine);
}
