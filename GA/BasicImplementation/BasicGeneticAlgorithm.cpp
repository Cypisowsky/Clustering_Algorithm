//
// Created by Michal on 17.01.2025.
//

#include "BasicGeneticAlgorithm.h"

#include <stdexcept>

#include "BasicCrossoverAlgorithm.h"
#include "../Individual.h"

void BasicGeneticAlgorithm::initialize() {

        if(individuals.empty()) {
                throw std::invalid_argument("Individuals vector is empty");
        }

}

void BasicGeneticAlgorithm::runIteration() {

        auto parents = std::move(chooseParents());
        int ind=0;

        //add children
        for(int i=0; i<parents.size(); i++) {

                auto children =(parents[i].first->crossover(parents[i].second, crossoverChance));

                children.first->mutate(mutationChance);
                children.second->mutate(mutationChance);
                delete individuals[ind];
                individuals[ind++]=(children.first);
                delete individuals[ind];
                individuals[ind++]=(children.second);
                // delete parents[i];
        }
        

}

double BasicGeneticAlgorithm::generateRandomChance(const double low, const double high) {

        std::random_device rd;
        randomEngine.seed(rd());
        std::uniform_real_distribution<> dis(low, high);

        return dis(randomEngine);
}

size_t BasicGeneticAlgorithm::generateRandomIndex(const size_t low, const size_t high) {

        std::random_device rd;
        randomEngine.seed(rd());
        std::uniform_int_distribution<> dis(low, high);

        return dis(randomEngine);
}

std::vector<std::pair<Individual *, Individual *>> BasicGeneticAlgorithm::chooseParents() {

        return parentChooser->chooseParents(individuals);
        // std::vector<ParentsHolder*> parents;
        // for(int i=0; i<individuals.size()/2; i++) {
        //         auto ind1 = individuals[generateRandomIndex(0, individuals.size()-1)];
        //         auto ind2 = individuals[generateRandomIndex(0, individuals.size()-1)];
        //         auto p1 = ind1->getFitness()>ind2->getFitness()? ind1:ind2;
        //         ind1 = individuals[generateRandomIndex(0, individuals.size()-1)];
        //         ind2 = individuals[generateRandomIndex(0, individuals.size()-1)];
        //         auto p2 = ind1->getFitness()>ind2->getFitness()? ind1:ind2;
        //         parents.push_back(new ParentsHolder(new Individual(*p1), new Individual(*p2)));
        // }
        // return parents;
}

double BasicGeneticAlgorithm::getBestFitness() {

        double bestFitness = individuals[0]->getFitness();
        for(int i=1; i<individuals.size(); i++) {
                if(individuals[i]->getFitness() < bestFitness) {
                        bestFitness = individuals[i]->getFitness();
                }
        }
        return bestFitness;
}

Individual &BasicGeneticAlgorithm::getBestIndividual() {

        Individual* bestIndividual = individuals[0];
        for(int i=1; i<individuals.size(); i++) {
                if(individuals[i]->getFitness() < bestIndividual->getFitness()) {
                        bestIndividual = individuals[i];
                }
        }
        return *bestIndividual;
}








