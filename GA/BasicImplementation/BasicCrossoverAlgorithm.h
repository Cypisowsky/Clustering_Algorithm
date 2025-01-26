//
// Created by Michał on 16.01.2025.
//

#ifndef BASICCROSSOVERALGORITHM_H
#define BASICCROSSOVERALGORITHM_H
#include "../InterfaceUtils/ICrossoverFinder.h"


    class BasicCrossoverAlgorithm : public ICrossoverFinder {

        /** @brief Basic Implementation of crossover algorithm
         *  It takes two individuals and with a given chance and modifies them
         *  by combining the genes of the parents
         */

        using ICrossoverFinder::ICrossoverFinder;

        std::pair<Individual*, Individual*> crossover(Individual *individual1, Individual *individual2, double chance) override;
    };




#endif //BASICCROSSOVERALGORITHM_H
