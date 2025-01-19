//
// Created by Michał on 13.01.2025.
//

#ifndef MUTATIONALGORITHM_H
#define MUTATIONALGORITHM_H
#include <random>

#include "../Individual.h"
#include "../Individual.h"




namespace NGroupingChallenge {
    class Individual;

    class IMutationFinder {
    public:
        //explicit IMutationFinder(double chance) {this->chance = chance;};

        IMutationFinder() = default;

        virtual ~IMutationFinder() = default;

        virtual void mutate(NGroupingChallenge::Individual& individual, double chance){};

        //void setChance(const double chance) {this->chance = chance;};


    protected:
        //double chance;
        //std::mt19937 c_random_engine;

    };


}


#endif //MUTATIONALGORITHM_H
