//
// Created by Michał on 18.01.2025.
//

#include "SmartEvaluator.h"

double NGroupingChallenge::SmartEvaluator::evaluateFitness(std::vector<int>& values) {
    double distance;
    double distanceSum = 0;

    for (size_t i = 0; i + 1 < points.size(); i++)
    {

        for (size_t j = i + 1; j < points.size(); j++)
        {
            if (values[i] == values[j])
            {
                distance = points[i].dCalculateDistance(points[j]);

                if (distance >= 0)
                {
                    distanceSum += 2.0 * points[i].dCalculateDistance(points[j]);
                }
            }
        }
    }

    return distanceSum;
}

double NGroupingChallenge::SmartEvaluator::recalculateFitness(std::vector<int> &values, const size_t index, const size_t newGroup) {

    double distance;
    double distanceSum = 0;

    for (size_t i = 0; i + 1 < points.size(); i++)
    {
        if (newGroup==values[i])
        {
            distance = points[index].dCalculateDistance(points[i]);

            if (distance >= 0)
            {
                distanceSum += 2.0 * distance;
            }else {

                return -1;
            }
        }
        if (values[index]==values[i])
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
