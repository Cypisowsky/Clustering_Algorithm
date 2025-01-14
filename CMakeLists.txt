cmake_minimum_required(VERSION 3.29)
project(Clustering_GA)

set(CMAKE_CXX_STANDARD 11)

add_executable(Clustering_GA
        GaussianGroupingEvaluatorFactory.cpp
        GroupingChallenge.cpp
        GroupingEvaluator.cpp
        Optimizer.cpp
        Point.cpp
        IMutationFinder.h
        ICrossoverFinder.h
        Individual.cpp
        Individual.h
        IResultEncoder.h
        SEResultHolder.cpp
        SEResultHolder.h)
