//
// Created by Michal on 25.01.2025.
//

#ifndef WIDESEARCHMUTATIONALGORITHM_H
#define WIDESEARCHMUTATIONALGORITHM_H
#include "../InterfaceUtils/IMutationFinder.h"


class WideSearchMutationAlgorithm : public IMutationFinder {

    public:

    explicit WideSearchMutationAlgorithm(int iterationLimit) : IMutationFinder() {this->iterationLimit = iterationLimit;}

    ~WideSearchMutationAlgorithm() override = default;

    void mutate(Individual *individual, double chance) override;

    private:

    int iterationLimit;
};



#endif //WIDESEARCHMUTATIONALGORITHM_H
