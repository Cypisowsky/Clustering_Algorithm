//
// Created by Michał on 13.01.2025.
//

#ifndef MUTATIONALGORITHM_H
#define MUTATIONALGORITHM_H
#include <random>

#include "../Individual.h"
#include "../Individual.h"


class Individual;

    class IMutationFinder {

        /** @brief Interface for mutation algorithms
         *
         *  Interface for mutation algorithms. It takes an individual and with a given chance modifies it
         *  by changing the genes of the individual
         */
    public:
        //explicit IMutationFinder(double chance) {this->chance = chance;};

        IMutationFinder() = default;

        virtual ~IMutationFinder() = default;

        virtual void mutate(Individual& individual, double chance) = 0;

        //void setChance(const double chance) {this->chance = chance;};


    protected:
        //double chance;
        //std::mt19937 c_random_engine;

    };





#endif //MUTATIONALGORITHM_H
