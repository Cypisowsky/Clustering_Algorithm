//
// Created by Michał on 16.01.2025.
//

#ifndef BASICCROSSOVERALGORITHM_H
#define BASICCROSSOVERALGORITHM_H
#include "InterfaceUtils/ICrossoverFinder.h"

namespace NGroupingChallenge {
    class BasicCrossoverAlgorithm : public NGroupingChallenge::ICrossoverFinder {

        using ICrossoverFinder::ICrossoverFinder;

        std::pair<NGroupingChallenge::Individual, NGroupingChallenge::Individual> crossover(const NGroupingChallenge::Individual &individual1, const NGroupingChallenge::Individual &individual2, double chance) override;
    };
}



#endif //BASICCROSSOVERALGORITHM_H
