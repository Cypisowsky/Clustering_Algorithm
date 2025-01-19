//
// Created by Michał on 13.01.2025.
//

#ifndef CROSSOVERALGORITHM_H
#define CROSSOVERALGORITHM_H
#include <random>

#include "../Individual.h"




namespace NGroupingChallenge {
    class Individual;
    class ICrossoverFinder {
    public:
        //explicit ICrossoverFinder(double chance) {this->chance = chance;};

        ICrossoverFinder() = default;

        virtual ~ICrossoverFinder() = default;

        //virtual void findToCrossover(std::vector<NGrouppingChallenge::Individual>& individuals) {};

        virtual std::pair<NGroupingChallenge::Individual, NGroupingChallenge::Individual> crossover(const NGroupingChallenge::Individual &individual1, const NGroupingChallenge::Individual &individual2, double chance);;


    protected:
        //double chance;
        //std::mt19937 randomEngine;

    };


}




#endif //CROSSOVERALGORITHM_H
