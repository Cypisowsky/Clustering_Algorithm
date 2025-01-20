//
// Created by Michał on 18.01.2025.
//

#ifndef SMARTEVALUATOR_H
#define SMARTEVALUATOR_H
#include <utility>

#include "../../Point.h"
#include "../InterfaceUtils/IEvaluator.h"



    class SmartEvaluator : public IEvaluator {

        /** @brief Class that evaluates the fitness of the result using the points from the GroupingChallenge
         *
         *  It uses the points to calculate the distance between the points and the groups
         *  and returns the sum of the distances. Recalculations in O(n) time.
         */
    public:

        using IEvaluator::IEvaluator;

        //SmartEvaluator() = default;

        double evaluateFitness(std::vector<int>& values) override;

        double recalculateFitness(std::vector<int>& values, size_t index, int newGroup, double currentFitness) override;

    };




#endif //SMARTEVALUATOR_H
