//
// Created by Michal on 17.01.2025.
//

#include "BasicGeneticAlgorithm.h"

void NGroupingChallenge::BasicGeneticAlgorithm::initialize() {



}

void NGroupingChallenge::BasicGeneticAlgorithm::runIteration() {

        auto parents = std::move(chooseParents());
        

}

double NGroupingChallenge::BasicGeneticAlgorithm::generateRandomNumber(const double low, const double high) {

        std::random_device rd;
        randomEngine.seed(rd());
        std::uniform_real_distribution<> dis(low, high);

        return dis(randomEngine);
}

std::vector<NGroupingChallenge::BasicGeneticAlgorithm::ParentsHolder *> NGroupingChallenge::BasicGeneticAlgorithm::chooseParents() {

        std::vector<ParentsHolder*> parents;
        for(int i=0; i<individuals.size()/2; i++) {
                auto ind1 = individuals[(int) generateRandomNumber(0, individuals.size()-1)];
                auto ind2 = individuals[(int) generateRandomNumber(0, individuals.size()-1)];
                parents[i] = new ParentsHolder(ind1, ind2);
        }
        return parents;
}






