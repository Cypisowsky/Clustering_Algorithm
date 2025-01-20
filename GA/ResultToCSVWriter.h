//
// Created by Michał on 20.01.2025.
//

#ifndef RESULTTOCSVWRITER_H
#define RESULTTOCSVWRITER_H
#include <fstream>

#include "Individual.h"
#include "../Point.h"


class ResultToCSVWriter {
public:
    static void writeCoordinatesToCSV(IResultEncoder<int>& result, const std::vector<NGroupingChallenge::CPoint>& points, std::string& filename);
};



#endif //INDIVIDUALTOCSVWRITER_H
