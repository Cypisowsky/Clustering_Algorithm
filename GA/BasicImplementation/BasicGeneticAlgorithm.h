//
// Created by Michal on 17.01.2025.
//

#ifndef BASICGENETICALGORITHM_H
#define BASICGENETICALGORITHM_H
#include "../InterfaceUtils/IGeneticAlgorithm.h"



    class BasicGeneticAlgorithm : public IGeneticAlgorithm {

        /** @brief  Basic Implementation of Genetic Algorithm
         * Follows straight-forward principles of Genetic Algorithm.
         */

        public:
        using IGeneticAlgorithm::IGeneticAlgorithm;

        void initialize() override;

        void runIteration() override;

        double getBestFitness() override;

        Individual& getBestIndividual() override;

        void setIndividuals(std::vector<Individual*>& individuals) override { this->individuals = individuals; };

        private:

        class ParentsHolder {

            public:
            ParentsHolder(Individual* parent1, Individual* parent2):
            parent1(parent1), parent2(parent2){}

            ~ParentsHolder() = default;

            Individual* getParent1() const { return parent1; }

            Individual* getParent2() const { return parent2; }


            private:
            Individual* parent1;
            Individual* parent2;
        };

        double generateRandomChance(double low, double high);

        size_t generateRandomIndex(size_t low, size_t high);

        std::mt19937 randomEngine;

        //std::vector<ParentsHolder*> parents;

        std::vector<std::pair<Individual *, Individual *>> chooseParents();



    };



#endif //BASICGENETICALGORITHM_H
