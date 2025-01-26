//
// Created by Michal on 25.01.2025.
//

#ifndef WIDESEARCHPARENTCHOOSER_H
#define WIDESEARCHPARENTCHOOSER_H
#include "../InterfaceUtils/IParentChooser.h"


class WideSearchParentChooser : public IParentChooser {

public:

    using IParentChooser::IParentChooser;

    ~WideSearchParentChooser() override = default;

    std::vector<std::pair<Individual*,Individual*>> chooseParents(std::vector<Individual*> individuals) override;

private:

    size_t generateRandomIndex(const size_t low, const size_t high);

    std::mt19937 randomEngine;

};



#endif //WIDESEARCHPARENTCHOOSER_H
