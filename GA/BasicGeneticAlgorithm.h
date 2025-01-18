//
// Created by Michal on 17.01.2025.
//

#ifndef BASICGENETICALGORITHM_H
#define BASICGENETICALGORITHM_H
#include "InterfaceUtils/IGeneticAlgorithm.h"


namespace NGroupingChallenge {
    class BasicGeneticAlgorithm : public IGeneticAlgorithm {

        public:
        using IGeneticAlgorithm::IGeneticAlgorithm;

        void initialize() override;

        void runIteration() override;

        private:

        class ParentsHolder {

            public:
            ParentsHolder(NGrouppingChallenge::Individual* parent1, NGrouppingChallenge::Individual* parent2):
            parent1(parent1), parent2(parent2){}

            ~ParentsHolder()= default;

            NGrouppingChallenge::Individual* getParent1() const { return parent1; }

            NGrouppingChallenge::Individual* getParent2() const { return parent2; }


            private:
            NGrouppingChallenge::Individual* parent1;
            NGrouppingChallenge::Individual* parent2;
        };

        double generateRandomNumber(double low, double high);

        std::mt19937 randomEngine;

        //std::vector<ParentsHolder*> parents;

        std::vector<ParentsHolder*> chooseParents();



    };
}


#endif //BASICGENETICALGORITHM_H
