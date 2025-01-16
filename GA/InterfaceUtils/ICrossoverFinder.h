//
// Created by Michał on 13.01.2025.
//

#ifndef CROSSOVERALGORITHM_H
#define CROSSOVERALGORITHM_H
#include <random>

#include "../Individual.h"


namespace NGroupingChallenge {
    class ICrossoverFinder {
    public:
        explicit ICrossoverFinder(int chance) {this->chance = chance;};

        virtual ~ICrossoverFinder() = default;

        //virtual void findToCrossover(std::vector<NGrouppingChallenge::Individual>& individuals) {};

        virtual NGrouppingChallenge::Individual crossover(const NGrouppingChallenge::Individual &individual1, const NGrouppingChallenge::Individual &individual2) {
            return individual1;
        };


    private:
        int chance;
        std::mt19937 c_random_engine;

    };


}




#endif //CROSSOVERALGORITHM_H
