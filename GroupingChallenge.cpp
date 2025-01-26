#include "GaussianGroupingEvaluatorFactory.h"
#include "GroupingEvaluator.h"
#include "Optimizer.h"
#include "GA/ResultToCSVWriter.h"
#include "GA/StrictComparisonImplementation//StrictCompCrossoverAlgorithm.h"
#include "GA/BasicImplementation/BasicCrossoverAlgorithm.h"
#include "GA/BasicImplementation/BasicGeneticAlgorithm.h"
#include "GA/BasicImplementation/BasicMutationAlgorithm.h"
#include "GA/BasicImplementation/BasicResultHolder.h"
#include "GA/BasicImplementation/SmartEvaluator.h"
#include "GA/StrictComparisonImplementation/StrictCompCrossoverAlgorithm.h"
#include "GA/StrictComparisonImplementation/StrictCompMutationAlgorithm.h"
#include "GA/WideSearchImplementation/WideSearchMutationAlgorithm.h"
#include "GA/WideSearchImplementation/WideSearchParentChooser.h"

using namespace NGroupingChallenge;



int main(){

	CGaussianGroupingEvaluatorFactory c_evaluator_factory(5, 100, 5);

		c_evaluator_factory
			.cAddDimension(-100, 100, 1.0, 1.0)
			.cAddDimension(-100, 100, 1.0, 1.0);
			//.cAddDimension(-100, 100, 1.0, 1.0);
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0)
			// .cAddDimension(-100, 100, 1.0, 1.0);

		CGroupingEvaluator* pc_evaluator = c_evaluator_factory.pcCreateEvaluator(0);

		IEvaluator* resultEvaluator = new SmartEvaluator(pc_evaluator->vGetPoints());
		ICrossoverFinder* crossoverFinder = new StrictCompCrossoverAlgorithm(100);
		IMutationFinder* mutationFinder = new WideSearchMutationAlgorithm(100);
		IResultEncoder<int>* resultEncoder = new BasicResultHolder(pc_evaluator->iGetUpperBound()-1, resultEvaluator);
		IParentChooser* parentChooser = new WideSearchParentChooser;

		IGeneticAlgorithm* geneticAlgorithm = new BasicGeneticAlgorithm(50, 0.2, 0.7, parentChooser);

		COptimizer c_optimizer(*pc_evaluator, *geneticAlgorithm, resultEncoder, mutationFinder, crossoverFinder);

		c_optimizer.vInitialize();

		std::cout<<"Starting optimization:"<<std::endl;
		int iterCout = 1000;
		int percent=0;
		for (int i = 0; i < iterCout; i++){
			c_optimizer.vRunIteration();
			int temppercent = (i*100)/iterCout;
			if(temppercent%10==0 && percent!=temppercent) {
				percent=temppercent;
				cout<<"Percent done: "<<percent<<endl;
			}
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