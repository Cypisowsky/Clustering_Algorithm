cmake_minimum_required(VERSION 3.29)
project(Clustering_GA)

set(CMAKE_CXX_STANDARD 11)

add_executable(Clustering_GA
        GaussianGroupingEvaluatorFactory.cpp
        GroupingChallenge.cpp
        GroupingEvaluator.cpp
        Optimizer.cpp
        Point.cpp
        GA/InterfaceUtils/IMutationFinder.h
        GA/InterfaceUtils/ICrossoverFinder.h
        GA/Individual.cpp
        GA/Individual.h
        GA/InterfaceUtils/IResultEncoder.h
        GA/BasicImplementation/BasicResultHolder.cpp
        GA/BasicImplementation/BasicResultHolder.h
        GA/BasicImplementation/BasicMutationAlgorithm.cpp
        GA/BasicImplementation/BasicMutationAlgorithm.h
        GA/BasicImplementation/BasicCrossoverAlgorithm.cpp
        GA/BasicImplementation/BasicCrossoverAlgorithm.h
        GA/InterfaceUtils/IGeneticAlgorithm.h
        GA/BasicImplementation/BasicGeneticAlgorithm.cpp
        GA/BasicImplementation/BasicGeneticAlgorithm.h
        GA/InterfaceUtils/IEvaluator.h
        GA/BasicImplementation/SmartEvaluator.cpp
        GA/BasicImplementation/SmartEvaluator.h
        GA/ResulttoCSVWriter.cpp
        GA/ResulttoCSVWriter.h)
