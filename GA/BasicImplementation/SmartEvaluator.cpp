//
// Created by Michał on 18.01.2025.
//

#include "SmartEvaluator.h"

#include <vector>

double SmartEvaluator::evaluateFitness(std::vector<int>& values) {

    if(values.empty())
        return -1;

    double distance;
    double distanceSum = 0;

    for (size_t i = 0; i + 1 < points.size(); i++)
    {

        for (size_t j = i + 1; j < points.size(); j++)
        {
            if (values[i] == values[j])
            {
                distance = points[i].dCalculateDistance(points[j]);

                if (distance > 0)
                {
                    distanceSum += 2.0 * points[i].dCalculateDistance(points[j]);
                }
            }
        }
    }

    return distanceSum;
}

double SmartEvaluator::recalculateFitness(std::vector<int> &values, const size_t index, const int newGroup, const double currentFitness) {

    double distance;
    double distanceSum = currentFitness;

    for (size_t i = 0; i  < points.size(); i++)
    {
        auto t1 = values[i];
        if (newGroup==values[i])
        {
            distance = points[index].dCalculateDistance(points[i]);

            if (distance > 0)
            {
                distanceSum += 2.0 * distance;
            }else {

                return -1;
            }
        }
        auto t2 = values[index];
        if (values[index]==values[i] && i!=index)
        {
            distance = points[index].dCalculateDistance(points[i]);

            if (distance >= 0)
            {
                distanceSum -= 2.0 * distance;
            }else {

                return -1;
            }
        }

    }

    return distanceSum;
}
