//
// Created by Michał on 13.01.2025.
//

#ifndef CROSSOVERALGORITHM_H
#define CROSSOVERALGORITHM_H
#pragma once
#include <random>

#include "../Individual.h"
#include "../Individual.h"
#include "../Individual.h"




    class Individual;

    class ICrossoverFinder {

        /** @brief Interface for crossover algorithms
         *
         *  Interface for crossover algorithms. It takes two individuals and with a given chance and modifies them
         *  by combining the genes of the parents
         */
    public:

        ICrossoverFinder() = default;

        virtual ~ICrossoverFinder() = default;

        virtual std::pair<Individual*, Individual*> crossover(Individual *individual1, Individual *individual2, double chance) = 0;


    protected:
        //double chance;
        //std::mt19937 randomEngine;

    };









#endif //CROSSOVERALGORITHM_H
