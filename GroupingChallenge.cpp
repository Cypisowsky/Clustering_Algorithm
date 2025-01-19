#include "GaussianGroupingEvaluatorFactory.h"
#include "GroupingEvaluator.h"
#include "Optimizer.h"
#include "GA/BasicCrossoverAlgorithm.h"
#include "GA/BasicGeneticAlgorithm.h"
#include "GA/BasicMutationAlgorithm.h"
#include "GA/RandomIndividualsCreator.h"
#include "GA/SmartEvaluator.h"

using namespace NGroupingChallenge;



int main(){

	CGaussianGroupingEvaluatorFactory c_evaluator_factory(5, 100, 5);

		c_evaluator_factory
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0);

		CGroupingEvaluator* pc_evaluator = c_evaluator_factory.pcCreateEvaluator(0);

		IEvaluator* resultEvaluator = new SmartEvaluator(pc_evaluator->vGetPoints());
		ICrossoverFinder* crossoverFinder = new NGroupingChallenge::BasicCrossoverAlgorithm();
		IMutationFinder* mutationFinder = new NGrouppingChallenge::BasicMutationAlgorithm();
		IResultEncoder<int> resultEncoder = BasicResultHolder<int>();

		IGeneticAlgorithm* geneticAlgorithm = new BasicGeneticAlgorithm(10,
			0.1,
			0.6,
			RandomIndividualsCreator::createRandomIndividuals(10, pc_evaluator->iGetUpperBound(), pc_evaluator->iGetNumberOfPoints(), crossoverFinder, mutationFinder, resultEncoder )
			);
		COptimizer c_optimizer(*pc_evaluator, *geneticAlgorithm);

		c_optimizer.vInitialize();

		for (int i = 0; i < 10; i++)
		{
			c_optimizer.vRunIteration();
		}

		delete pc_evaluator;

		return 0;


}


// int main()
// {
// 	CGaussianGroupingEvaluatorFactory c_evaluator_factory(5, 100, 5);
//
// 	c_evaluator_factory
// 		.cAddDimension(-100, 100, 1.0, 1.0)
// 		.cAddDimension(-100, 100, 1.0, 1.0)
// 		.cAddDimension(-100, 100, 1.0, 1.0)
// 		.cAddDimension(-100, 100, 1.0, 1.0)
// 		.cAddDimension(-100, 100, 1.0, 1.0)
// 		.cAddDimension(-100, 100, 1.0, 1.0)
// 		.cAddDimension(-100, 100, 1.0, 1.0)
// 		.cAddDimension(-100, 100, 1.0, 1.0)
// 		.cAddDimension(-100, 100, 1.0, 1.0)
// 		.cAddDimension(-100, 100, 1.0, 1.0);
//
// 	CGroupingEvaluator* pc_evaluator = c_evaluator_factory.pcCreateEvaluator(0);
//
// 	COptimizer c_optimizer(*pc_evaluator);
//
// 	c_optimizer.vInitialize();
//
// 	for (int i = 0; i < 10; i++)
// 	{
// 		c_optimizer.vRunIteration();
// 	}
//
// 	delete pc_evaluator;
//
// 	return 0;
// }