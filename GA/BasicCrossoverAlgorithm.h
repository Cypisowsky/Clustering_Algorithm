//
// Created by Michał on 16.01.2025.
//

#ifndef BASICCROSSOVERALGORITHM_H
#define BASICCROSSOVERALGORITHM_H
#include "InterfaceUtils/ICrossoverFinder.h"


class BasicCrossoverAlgorithm : public NGroupingChallenge::ICrossoverFinder {

    using ICrossoverFinder::ICrossoverFinder;

    NGrouppingChallenge::Individual crossover(const NGrouppingChallenge::Individual &individual1, const NGrouppingChallenge::Individual &individual2) override;
};



#endif //BASICCROSSOVERALGORITHM_H
