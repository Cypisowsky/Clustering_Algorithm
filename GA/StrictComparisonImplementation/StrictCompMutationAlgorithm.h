//
// Created by Michal on 24.01.2025.
//

#ifndef STRICTCOMPMUTATIONALGORITHM_H
#define STRICTCOMPMUTATIONALGORITHM_H
#include "../InterfaceUtils/ICrossoverFinder.h"


class StrictCompMutationAlgorithm : public IMutationFinder {

    public:
    explicit StrictCompMutationAlgorithm(int iterationLimit) : IMutationFinder() {this->iterationLimit = iterationLimit;}

    ~StrictCompMutationAlgorithm() override = default;

    void mutate(Individual *individual, double chance) override;

    private:
    int iterationLimit;
};



#endif //STRICTCOMPMUTATIONALGORITHM_H
