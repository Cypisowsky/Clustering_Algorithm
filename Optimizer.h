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

		COptimizer(CGroupingEvaluator& cEvaluator, IGeneticAlgorithm& cGeneticAlgorithm);

		void vInitialize();
		void vRunIteration();

		vector<int>* pvGetCurrentBest() { return &v_current_best; }

	private:
		CGroupingEvaluator& c_evaluator;
		IGeneticAlgorithm& c_genetic_algorithm;

		double d_current_best_fitness;
		vector<int> v_current_best;

		mt19937 c_random_engine;
	};
}

#endif