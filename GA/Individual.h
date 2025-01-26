//
// Created by Michał on 13.01.2025.
//

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <utility>

#include "InterfaceUtils/ICrossoverFinder.h"
#include "InterfaceUtils/IMutationFinder.h"
#include "InterfaceUtils/IResultEncoder.h"


class IMutationFinder;
class ICrossoverFinder;


class Individual {

    public:
        Individual(IResultEncoder<int>* result_encoder, IMutationFinder* mutation_finder , ICrossoverFinder* crossover_finder);

        ~Individual() {delete result;};

        Individual(const Individual& individual): mutationFinder(individual.getMutationFinder()), crossoverFinder(individual.getCrossoverFinder()) {
            this->result = individual.result->clone();
        }

        Individual(Individual&& individual) noexcept: mutationFinder(individual.getMutationFinder()), crossoverFinder(individual.getCrossoverFinder()) {
            this->result = std::move(individual.result); individual.result = nullptr;
        };

        std::pair<Individual*, Individual*> crossover(Individual *individual, double chance);

        void mutate(double chance);

        double getFitness() const {return result->getFitness();};

        IResultEncoder<int>* getResult() const {return result;};

        void setResult(IResultEncoder<int>* result) {this->result=result;};

        IMutationFinder* getMutationFinder() const {return mutationFinder;};

        ICrossoverFinder* getCrossoverFinder() const {return crossoverFinder;};

        Individual& operator=(Individual&& individual) noexcept;

    private:
        IResultEncoder<int>* result;
        IMutationFinder* mutationFinder;
        ICrossoverFinder* crossoverFinder;


    };




#endif //INDIVIDUAL_H
