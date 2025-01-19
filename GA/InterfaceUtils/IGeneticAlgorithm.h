//
// Created by Michał on 16.01.2025.
//

#ifndef IGENETICALGORITHM_H
#define IGENETICALGORITHM_H
#include <vector>

#include "../Individual.h"


namespace NGroupingChallenge {
    class IGeneticAlgorithm {

    public:
        IGeneticAlgorithm(const int popSize, const double mutationChance, const double crossoverChance, const std::vector<NGrouppingChallenge::Individual*>& individuals):
        popSize(popSize), mutationChance(mutationChance), crossoverChance(crossoverChance), individuals(individuals) {};

        IGeneticAlgorithm(IGeneticAlgorithm& geneticAlgorithm) {};

        virtual ~IGeneticAlgorithm(){
            for (const auto ind : individuals) {
            delete ind;
            }
        }

        virtual void runIteration();

        virtual void initialize();

        virtual double getBestFitness();


    protected:
        double mutationChance;
        double crossoverChance;
        int popSize;
        std::vector<NGrouppingChallenge::Individual*> individuals;
        // IMutationFinder* mutation_finder;
        // ICrossoverFinder* crossover_finder;
    };

}



#endif //IGENETICALGORITHM_H
