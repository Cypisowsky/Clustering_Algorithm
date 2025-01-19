//
// Created by Michał on 18.01.2025.
//

#include "RandomIndividualsCreator.h"

std::vector<NGrouppingChallenge::Individual *> &NGroupingChallenge::RandomIndividualsCreator::createRandomIndividuals(const int popSize, const int groupCount, const int pointCount, ICrossoverFinder *crossoverFinder, IMutationFinder *mutationFinder, IResultEncoder<int>& resultEncoder) {

    std::vector<NGrouppingChallenge::Individual*> individuals;

    std::random_device rd;
    std::mt19937 rand(rd());
    std::uniform_int_distribution<> dis(0, groupCount);
    for(int i=0; i<popSize; i++) {
        std::vector<int> values;
        for(int j=0; j<pointCount; j++)
            values.push_back(dis(rand));

        auto result = resultEncoder.clone();
        result->set(values);
        auto individual = new NGrouppingChallenge::Individual(result, mutationFinder, crossoverFinder);
        individuals.push_back(individual);
    }
    return individuals;
}
