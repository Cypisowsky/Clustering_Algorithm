//
// Created by Michał on 13.01.2025.
//

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "InterfaceUtils/ICrossoverFinder.h"
#include "InterfaceUtils/IMutationFinder.h"
#include "InterfaceUtils/IResultEncoder.h"


namespace NGroupingChallenge {

class Individual {

    public:
        explicit Individual(NGroupingChallenge::IResultEncoder<int>* result_encoder, NGroupingChallenge::IMutationFinder* mutation_finder , NGroupingChallenge::ICrossoverFinder* crossover_finder) {
            this->result = result_encoder;
            this->mutationFinder = mutation_finder;
            this->crossoverFinder = crossover_finder;
        };

        ~Individual() {delete result;};

        Individual(const Individual& individual): mutationFinder(individual.getMutationFinder()), crossoverFinder(individual.getCrossoverFinder()) {
            this->result = new NGroupingChallenge::IResultEncoder<int>(*individual.result);
        }

        Individual(Individual&& individual) noexcept: mutationFinder(individual.getMutationFinder()), crossoverFinder(individual.getCrossoverFinder()) {this->result = std::move(individual.result); individual.result = nullptr;};

        std::pair<Individual, Individual> crossover(NGroupingChallenge::Individual &individual, const double chance) {return crossoverFinder->crossover(*this, individual, chance);};

        void mutate(double chance) {mutationFinder->mutate(*this, chance);};

        double getFitness() const {return result->getFitness();};

        NGroupingChallenge::IResultEncoder<int>* getResult() const {return result;};

        NGroupingChallenge::IMutationFinder* getMutationFinder() const {return mutationFinder;};

        NGroupingChallenge::ICrossoverFinder* getCrossoverFinder() const {return crossoverFinder;};

        Individual& operator=(Individual&& individual)  noexcept {
            delete result;
            delete mutationFinder;
            delete crossoverFinder;
            this->result = std::move(individual.result);
            individual.result = nullptr;
            this->mutationFinder = individual.getMutationFinder();
            individual.mutationFinder = nullptr;
            this->crossoverFinder = individual.getCrossoverFinder();
            individual.crossoverFinder = nullptr;
            return *this;
        }

    private:
        NGroupingChallenge::IResultEncoder<int>* result;
        NGroupingChallenge::IMutationFinder* mutationFinder;
        NGroupingChallenge::ICrossoverFinder* crossoverFinder;


    };
}



#endif //INDIVIDUAL_H
