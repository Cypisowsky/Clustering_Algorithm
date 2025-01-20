#include "Optimizer.h"

using namespace NGroupingChallenge;

// COptimizer::COptimizer(CGroupingEvaluator& cEvaluator)
// 	: c_evaluator(cEvaluator)
// {
// 	random_device c_seed_generator;
// 	c_random_engine.seed(c_seed_generator());
// }



// void COptimizer::vInitialize()
// {
// 	numeric_limits<double> c_double_limits;
// 	d_current_best_fitness = c_double_limits.max();
//
// 	v_current_best.clear();
// 	v_current_best.resize(c_evaluator.iGetNumberOfPoints());
// }



void COptimizer::vInitialize(){

	for (auto individual: c_genetic_algorithm.get_individuals()) {
		individual->getResult()->fillWithRandomValues(c_evaluator.iGetNumberOfPoints());
	}
	c_genetic_algorithm.initialize();
	d_current_best_fitness = c_genetic_algorithm.getBestFitness();
	d_starting_fitness = d_current_best_fitness;
}

void COptimizer::vRunIteration() {

	c_genetic_algorithm.runIteration();

	double t = c_genetic_algorithm.getBestFitness();

	if(d_current_best_fitness>t)
		d_current_best_fitness = t;

	if(d_worst_fitness<t)
		d_worst_fitness = t;

	i_iterations++;

}

void COptimizer::printResult() {

	std::cout<<"Starting random fitness: "<<d_starting_fitness<<std::endl;
	std::cout<<"Best fitness: "<<d_current_best_fitness<<std::endl;
	std::cout<<"Worst fitness: "<<d_worst_fitness<<std::endl;
	std::cout<<"Iterations: "<<i_iterations<<std::endl;
	std::cout<<"Optimization: "<<(d_starting_fitness-d_current_best_fitness)*100/d_starting_fitness<<" %"<<std::endl;
	std::cout<<"Optimization per iteration: "<<((d_starting_fitness-d_current_best_fitness)*100/d_starting_fitness)/i_iterations<<" %"<<std::endl;
}


// void COptimizer::vRunIteration()
// {
// 	vector<int> v_candidate(c_evaluator.iGetNumberOfPoints());
//
// 	uniform_int_distribution<int> c_candidate_distribution(c_evaluator.iGetLowerBound(), c_evaluator.iGetUpperBound());
//
// 	for (size_t i = 0; i < v_candidate.size(); i++)
// 	{
// 		v_candidate[i] = c_candidate_distribution(c_random_engine);
// 	}
//
// 	double d_candidate_fitness = c_evaluator.dEvaluate(v_candidate);
//
// 	if (d_candidate_fitness < d_current_best_fitness)
// 	{
// 		v_current_best = v_candidate;
// 		d_current_best_fitness = d_candidate_fitness;
// 	}
//
// 	cout << d_current_best_fitness << endl;
// }