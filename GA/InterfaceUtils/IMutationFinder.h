//
// Created by Michał on 13.01.2025.
//

#ifndef MUTATIONALGORITHM_H
#define MUTATIONALGORITHM_H
#include <random>

#include "../Individual.h"
#include "../Individual.h"
#include "InterfaceUtils/IResultEncoder.h"


namespace NGrouppingChallenge {
    class Individual;
}

namespace NGroupingChallenge {
    class IMutationFinder {
    public:
        explicit IMutationFinder(int chance) {this->chance = chance;};

        virtual ~IMutationFinder() = default;

        virtual void mutate(NGrouppingChallenge::Individual& individual){};


    protected:
        int chance;
        //std::mt19937 c_random_engine;

    };


}


#endif //MUTATIONALGORITHM_H
