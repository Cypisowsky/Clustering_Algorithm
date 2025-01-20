#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include "GroupingEvaluator.h"

#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "GA/InterfaceUtils/IGeneticAlgorithm.h"

using namespace std;

namespace NGroupingChallenge
{
	class COptimizer
	{
	public:
		//COptimizer(CGroupingEvaluator& cEvaluator);

		COptimizer(CGroupingEvaluator& cEvaluator,
			IGeneticAlgorithm& cGeneticAlgorithm,
			IResultEncoder<int> *resultEncoder,
			IMutationFinder* mutationFinder,
			ICrossoverFinder* crossoverFinder):
			c_genetic_algorithm(cGeneticAlgorithm), c_evaluator(cEvaluator) {

			std::vector<Individual *> individuals;

			for (int i = 0; i < c_genetic_algorithm.getPopSize(); i++) {
				auto result = resultEncoder->clone();
				result->fillWithRandomValues(c_evaluator.iGetNumberOfPoints());
				individuals.push_back(new Individual(result, mutationFinder, crossoverFinder));
			}

			c_genetic_algorithm.setIndividuals(individuals);
		}

		void vInitialize();
		void vRunIteration();

		vector<int>* pvGetCurrentBest() { return &v_current_best; }

		// added

		void printResult();

		Individual& getBestIndividual() { return c_genetic_algorithm.getBestIndividual(); }

	private:
		CGroupingEvaluator& c_evaluator;
		IGeneticAlgorithm& c_genetic_algorithm;

		double d_current_best_fitness;
		vector<int> v_current_best;

		mt19937 c_random_engine;

		//added:

		double d_starting_fitness;
		double d_worst_fitness;
		int i_iterations;

	};
}

#endif