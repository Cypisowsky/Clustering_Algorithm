cmake_minimum_required(VERSION 3.29)
project(Clustering_GA)

set(CMAKE_CXX_STANDARD 20)

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
        GA/BasicResultHolder.cpp
        GA/BasicResultHolder.h
        GA/BasicMutationAlgorithm.cpp
        GA/BasicMutationAlgorithm.h
        GA/BasicCrossoverAlgorithm.cpp
        GA/BasicCrossoverAlgorithm.h
        GA/InterfaceUtils/IGeneticAlgorithm.h
        GA/BasicGeneticAlgorithm.cpp
        GA/BasicGeneticAlgorithm.h
        GA/RandomIndividualsCreator.cpp
        GA/RandomIndividualsCreator.h
        GA/InterfaceUtils/IEvaluator.h
        GA/SmartEvaluator.cpp
        GA/SmartEvaluator.h)
