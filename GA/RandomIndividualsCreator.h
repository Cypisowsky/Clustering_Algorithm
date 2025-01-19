//
// Created by Michał on 18.01.2025.
//

#ifndef RANDOMINDIVIDUALSCREATOR_H
#define RANDOMINDIVIDUALSCREATOR_H
#include "Individual.h"
#include "BasicResultHolder.h"
#include "InterfaceUtils/IEvaluator.h"


namespace NGroupingChallenge {
    class RandomIndividualsCreator {

    public:
        static std::vector<NGrouppingChallenge::Individual*>& createRandomIndividuals(
            int popSize,
            int groupCount,
            int pointCount,
            ICrossoverFinder* crossoverFinder,
            IMutationFinder* mutationFinder,
            IResultEncoder<int>& resultEncoder);
    };
}



#endif //RANDOMINDIVIDUALSCREATOR_H
