//
// Created by Michał on 14.01.2025.
//

#ifndef SERESULTHOLDER_H
#define SERESULTHOLDER_H
#include <climits>
#include <utility>
#include <vector>

#include "../InterfaceUtils/IResultEncoder.h"
#include "../../Point.h"
#include "../InterfaceUtils/IEvaluator.h"





    class BasicResultHolder : public IResultEncoder<int> {
        /** @brief Class that holds the result of the GA and evaluates it's fitness using IEvaluator.
         *
         *  Fitness getter in O(1) time. Implemented with the use of a vector. No mutation algorithm.
         */

    public:
        BasicResultHolder(const int groupCount, std::vector<int>& values, IEvaluator* evaluator) : values(values), groupCounter(groupCount), fitness(INT_MAX), evaluator(evaluator)
        {fitness=evaluator->evaluateFitness(values);}

        BasicResultHolder(const int groupCount, IEvaluator* evaluator) : groupCounter(groupCount), fitness(INT_MAX), evaluator(evaluator){}

        BasicResultHolder(BasicResultHolder& resultHolder) : values(std::vector<int>(resultHolder.values)), groupCounter(resultHolder.groupCount()), fitness(resultHolder.fitness), evaluator(resultHolder.evaluator){}

        IResultEncoder<int>* clone() override { return new BasicResultHolder(*this); }

        ~BasicResultHolder() override = default;

        std::vector<int> getValues() override { return values; }

        double getFitness() override { return fitness; }

        int get(const size_t index) override { return index>=values.size()? -1 : values[index]; }

        void set(size_t index, int value) override;

        void set(vector<int> &values) override { this->values = values; fitness=evaluator->evaluateFitness(values); }

        size_t size() override { return values.size(); }

        int groupCount() override { return groupCounter; }

        bool mutate(double chance) override { return false; }

        void fillWithRandomValues(int size) override;



    private:
        std::vector<int> values;
        int groupCounter;
        double fitness;
        //std::vector<CPoint*> points;
        IEvaluator* evaluator;


    };




#endif //SERESULTHOLDER_H
