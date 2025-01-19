//
// Created by Michal on 17.01.2025.
//

#include "BasicGeneticAlgorithm.h"

void NGroupingChallenge::BasicGeneticAlgorithm::initialize() {



}

void NGroupingChallenge::BasicGeneticAlgorithm::runIteration() {

        auto parents = std::move(chooseParents());
        int ind=0;

        //add children
        for(int i=0; i<parents.size(); i++) {
                auto children =std::move(parents[i]->getParent1()->crossover(*parents[i]->getParent2(), crossoverChance));
                children.first.mutate(mutationChance);
                children.second.mutate(mutationChance);
                *individuals[ind++]=std::move(children.first);
                *individuals[ind++]=std::move(children.second);
                delete parents[i];
        }


        

}

double NGroupingChallenge::BasicGeneticAlgorithm::generateRandomChance(const double low, const double high) {

        std::random_device rd;
        randomEngine.seed(rd());
        std::uniform_real_distribution<> dis(low, high);

        return dis(randomEngine);
}

std::vector<NGroupingChallenge::BasicGeneticAlgorithm::ParentsHolder*> NGroupingChallenge::BasicGeneticAlgorithm::chooseParents() {

        std::vector<ParentsHolder*> parents;
        for(int i=0; i<individuals.size()/2; i++) {
                auto ind1 = individuals[(int) generateRandomChance(0, individuals.size()-1)];
                auto ind2 = individuals[(int) generateRandomChance(0, individuals.size()-1)];
                auto p1 = ind1->getFitness()>ind2->getFitness()? ind1:ind2;
                ind1 = individuals[(int) generateRandomChance(0, individuals.size()-1)];
                ind2 = individuals[(int) generateRandomChance(0, individuals.size()-1)];
                auto p2 = ind1->getFitness()>ind2->getFitness()? ind1:ind2;
                parents[i] = new ParentsHolder(p1,p2);
        }
        return parents;
}






