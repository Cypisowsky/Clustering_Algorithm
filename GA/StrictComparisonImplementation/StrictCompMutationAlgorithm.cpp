//
// Created by Michal on 24.01.2025.
//

#include "StrictCompMutationAlgorithm.h"

void StrictCompMutationAlgorithm::mutate(Individual *individual, double chance) {
        auto result = individual->getResult();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> chanceDist(0.0, 1.0);
        std::uniform_int_distribution<> groupDist(0, result->groupCount());
        auto newResult = individual->getResult()->clone();
        int iter = 0;
        bool done = false;

        while(!done && iter < iterationLimit) {
            for (int i = 0; i < result->size(); i++) {
                if (chanceDist(gen) < chance) {
                    newResult->set(i, groupDist(gen));
                }
            }

            if(newResult->getFitness()>=individual->getFitness()) {
                done = true;
            }
            iter++;
        }
        individual->setResult(newResult);
        delete result;


}
