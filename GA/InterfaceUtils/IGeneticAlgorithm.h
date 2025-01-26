//
// Created by Michał on 16.01.2025.
//

#ifndef IGENETICALGORITHM_H
#define IGENETICALGORITHM_H
#include <vector>

#include "IParentChooser.h"
#include "../Individual.h"


    class IGeneticAlgorithm {

        /** @brief Interface for Genetic Algorithm
         *
         *  Interface for Genetic Algorithm. It takes a population of individuals and runs the algorithm
         *  to find the best individual.
         */

    public:
        IGeneticAlgorithm(const int popSize, const double mutationChance, const double crossoverChance, IParentChooser* parentChooser, const std::vector<Individual*>& individuals):
        popSize(popSize), mutationChance(mutationChance), crossoverChance(crossoverChance), parentChooser(parentChooser),individuals(individuals) {};

        IGeneticAlgorithm(const int popSize, const double mutationChance, const double crossoverChance, IParentChooser* parentChooser):
        mutationChance(mutationChance), crossoverChance(crossoverChance),parentChooser(parentChooser), popSize(popSize) {};

        IGeneticAlgorithm(const IGeneticAlgorithm& other):
        mutationChance(other.mutationChance), crossoverChance(other.crossoverChance), popSize(other.popSize), parentChooser(other.parentChooser) {
            for(int i = 0; i < other.popSize; i++) {
                this->individuals.push_back(new Individual(*other.individuals[i]));
            }
        };

        virtual void setIndividuals(std::vector<Individual*>& individuals) {this->individuals = individuals;}

        virtual ~IGeneticAlgorithm(){
            for (const auto ind : individuals) {
            delete ind;
            }
        }

        virtual void runIteration(){};

        virtual void initialize(){};

        virtual double getBestFitness()=0;

        virtual Individual& getBestIndividual()=0;

        std::vector<Individual*>& get_individuals() {return individuals;}

        int getPopSize() const {return popSize;}


    protected:
        double mutationChance;
        double crossoverChance;
        int popSize;
        std::vector<Individual*> individuals;
        IParentChooser* parentChooser{};
        // IMutationFinder* mutation_finder;
        // ICrossoverFinder* crossover_finder;
    };





#endif //IGENETICALGORITHM_H
