//
// Created by Michał on 14.01.2025.
//

#ifndef SERESULTHOLDER_H
#define SERESULTHOLDER_H
#include <climits>
#include <utility>
#include <vector>

#include "IResultEncoder.h"


namespace NGroupingChallenge {
    class CPoint;

    class SEResultHolder : public IResultEncoder<int> {
        /** @brief (Smart Evaluation Result Holder) - Class that holds the result of the GA and evaluates it's fitness smartly.
         *
         *  Fitness evaluation after change in O(n) time, Fitness getter in O(1) time. Implemented with the use of a vector. No mutation algorithm.
         */

    public:
        SEResultHolder(const int groupCount, std::vector<int> values) : values(std::move(values)), groupCounter(groupCount), fitness(INT_MAX) {}

        ~SEResultHolder() override = default;

        std::vector<int> getValues() override { return values; }

        double getFitness() override { return fitness; }

        int get(const size_t index) override { return index<0||index>=values.size()? -1 : values[index]; }

        void set(const size_t index, const int value) override { if (index>0&&index<values.size()) values[index] = value; }

        size_t size() override { return values.size(); }

        int groupCount() override { return groupCounter; }

        bool mutate(double chance) override { return false; }



    private:
        std::vector<int> values;
        int groupCounter;
        double fitness;
        std::vector<CPoint> points;

        double calculateFitness();
        double recalculateFitness(size_t index);

    };
}



#endif //SERESULTHOLDER_H
