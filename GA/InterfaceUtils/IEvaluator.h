//
// Created by Michał on 18.01.2025.
//

#ifndef IEVALUATOR_H
#define IEVALUATOR_H



    class IEvaluator {

        /** @brief Interface for evaluating the fitness of the result
         *
         *  Interface for evaluating the fitness of the result. It takes the values of the result and calculates the fitness
         *  based on the points from the GroupingChallenge
         */
    public:

        explicit IEvaluator(const std::vector<NGroupingChallenge::CPoint>& points) : points(points) {}

        virtual ~IEvaluator() = default;

        virtual double evaluateFitness(std::vector<int>& values) = 0;

        virtual double recalculateFitness(std::vector<int>& values, size_t index, int newGroup, double currentFitness) = 0;

    protected:
        std::vector<NGroupingChallenge::CPoint> points;
    };




#endif //IEVALUATOR_H
