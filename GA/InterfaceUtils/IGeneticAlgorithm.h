//
// Created by Michał on 16.01.2025.
//

#ifndef IGENETICALGORITHM_H
#define IGENETICALGORITHM_H


namespace NGroupingChallenge {
    class IGeneticAlgorithm {

    public:
        IGeneticAlgorithm(int popSize, double mutationChance, double crossoverChance): popSize(popSize), mutationChance(mutationChance), crossoverChance(crossoverChance) {};

        IGeneticAlgorithm(IGeneticAlgorithm& geneticAlgorithm) = default;

        virtual ~IGeneticAlgorithm() = default;

        virtual void run();

        virtual void initialize();


    protected:
        double mutationChance;
        double crossoverChance;
        double bestFitness;
        int popSize;
    };

}



#endif //IGENETICALGORITHM_H
