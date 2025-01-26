//
// Created by Michal on 24.01.2025.
//

#ifndef STRICTCOMPCROSSOVERALGORITHM_H
#define STRICTCOMPCROSSOVERALGORITHM_H
#pragma once
#include "../InterfaceUtils/ICrossoverFinder.h"


class StrictCompCrossoverAlgorithm : public ICrossoverFinder {

    public:

    explicit StrictCompCrossoverAlgorithm(int iterationLimit) : ICrossoverFinder() {this->iterationLimit = iterationLimit;};

    ~StrictCompCrossoverAlgorithm() override = default;

    std::pair<Individual *, Individual *> crossover(Individual *individual1, Individual *individual2, double chance) override;

    private:

    int iterationLimit;
};



#endif //STRICTCOMPCROSSOVERALGORITHM_H
