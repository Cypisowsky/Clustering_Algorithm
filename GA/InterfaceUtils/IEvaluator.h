//
// Created by Michał on 18.01.2025.
//

#ifndef IEVALUATOR_H
#define IEVALUATOR_H


namespace NGroupingChallenge {
    class IEvaluator {
    public:

        IEvaluator() = default;

        virtual ~IEvaluator() = default;

        virtual double evaluateFitness(std::vector<int>& values) = 0;

        virtual double recalculateFitness(std::vector<int>& values, size_t index, size_t newGroup) = 0;
    };
}



#endif //IEVALUATOR_H
