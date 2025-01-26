//
// Created by Michal on 25.01.2025.
//

#ifndef IPARENTCHOOSER_H
#define IPARENTCHOOSER_H
#include "../Individual.h"

class IParentChooser {

    public:
    IParentChooser()= default;
    virtual ~IParentChooser() = default;

    virtual std::vector<std::pair<Individual*,Individual*>> chooseParents(std::vector<Individual*> individuals) = 0;
};

#endif //IPARENTCHOOSER_H
