//
// Created by Michał on 18.01.2025.
//

#ifndef SMARTEVALUATOR_H
#define SMARTEVALUATOR_H
#include <utility>

#include "../Point.h"
#include "InterfaceUtils/IEvaluator.h"


namespace NGroupingChallenge {
    class SmartEvaluator : public IEvaluator {

    public:
        explicit SmartEvaluator(const std::vector<CPoint>& points): points(points) {};

        //SmartEvaluator() = default;

        double evaluateFitness(std::vector<int>& values) override;

        double recalculateFitness(std::vector<int>& values, size_t index, size_t newGroup) override;

    private:
        std::vector<CPoint> points;
    };
}



#endif //SMARTEVALUATOR_H
