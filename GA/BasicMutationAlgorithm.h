//
// Created by Michał on 16.01.2025.
//

#ifndef BASICMUTATIONALGORITHM_H
#define BASICMUTATIONALGORITHM_H
#include "InterfaceUtils/IMutationFinder.h"
#include "InterfaceUtils/IResultEncoder.h"


namespace NGrouppingChallenge {
    class BasicMutationAlgorithm : public NGroupingChallenge::IMutationFinder {

    public:
        using IMutationFinder::IMutationFinder;

        ~BasicMutationAlgorithm() override = default;

        void mutate(NGrouppingChallenge::Individual &individual) override;
    };
}


#endif //BASICMUTATIONALGORITHM_H
