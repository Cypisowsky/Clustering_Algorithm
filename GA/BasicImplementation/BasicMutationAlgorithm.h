//
// Created by Michał on 16.01.2025.
//

#ifndef BASICMUTATIONALGORITHM_H
#define BASICMUTATIONALGORITHM_H
#include "../InterfaceUtils/IMutationFinder.h"
#include "../InterfaceUtils/IResultEncoder.h"



    class BasicMutationAlgorithm : public IMutationFinder {

        /** @brief Basic Implementation of mutation algorithm
         *  It takes an individual and with a given chance modifies it
         *  by changing the genes of the individual
         */

    public:
        using IMutationFinder::IMutationFinder;


        void mutate(Individual &individual, double chance) override;
    };


#endif //BASICMUTATIONALGORITHM_H
