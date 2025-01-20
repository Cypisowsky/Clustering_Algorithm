#include "GaussianGroupingEvaluatorFactory.h"
#include "GroupingEvaluator.h"
#include "Optimizer.h"
#include "GA/ResultToCSVWriter.h"
#include "GA/BasicImplementation/BasicCrossoverAlgorithm.h"
#include "GA/BasicImplementation/BasicGeneticAlgorithm.h"
#include "GA/BasicImplementation/BasicMutationAlgorithm.h"
#include "GA/BasicImplementation/BasicResultHolder.h"
#include "GA/BasicImplementation/SmartEvaluator.h"

using namespace NGroupingChallenge;



int main(){

	CGaussianGroupingEvaluatorFactory c_evaluator_factory(5, 100, 5);

		c_evaluator_factory
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0);
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0);

		CGroupingEvaluator* pc_evaluator = c_evaluator_factory.pcCreateEvaluator(0);

		IEvaluator* resultEvaluator = new SmartEvaluator(pc_evaluator->vGetPoints());
		ICrossoverFinder* crossoverFinder = new BasicCrossoverAlgorithm();
		IMutationFinder* mutationFinder = new BasicMutationAlgorithm();
		IResultEncoder<int>* resultEncoder = new BasicResultHolder(pc_evaluator->iGetUpperBound()-1, resultEvaluator);

		IGeneticAlgorithm* geneticAlgorithm = new BasicGeneticAlgorithm(10, 0.2, 0.6);

		COptimizer c_optimizer(*pc_evaluator, *geneticAlgorithm, resultEncoder, mutationFinder, crossoverFinder);

		c_optimizer.vInitialize();

		std::cout<<"Starting optimization:"<<std::endl;
		for (int i = 0; i < 1000; i++)
		{
			c_optimizer.vRunIteration();
		}

		c_optimizer.printResult();
		std::string filename = "result.csv";
		ResultToCSVWriter::writeCoordinatesToCSV(*c_optimizer.getBestIndividual().getResult(), pc_evaluator->vGetPoints(), filename);


		delete resultEvaluator;
		delete resultEncoder;
		delete mutationFinder;
		delete crossoverFinder;
		delete geneticAlgorithm;


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