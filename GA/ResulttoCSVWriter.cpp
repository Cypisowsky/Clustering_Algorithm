//
// Created by Michał on 20.01.2025.
//

#include "ResultToCSVWriter.h"


void ResultToCSVWriter::writeCoordinatesToCSV(IResultEncoder<int> &result, const std::vector<NGroupingChallenge::CPoint> &points, std::string &filename) {
        std::ios_base::openmode mode =  std::ofstream::out;
        std::ofstream file(filename, mode);

        if (!file.is_open()) {
            throw std::ios_base::failure("Failed to open file: " + filename);
        }

        try {
            for (int i = 0; i <= result.groupCount(); i++) {
                for (int j = 0; j < result.size(); j++) {
                    if (result.get(j) == i) {
                        const auto &coordinates = points[j].getCoordinates();
                        for (size_t k = 0; k < coordinates.size(); k++) {
                            file << coordinates[k];
                            if (k < coordinates.size() - 1) {
                                file << ",";
                            }
                        }

                        file << " ; ";
                    }

                }
                file << " | " << std::endl;
            }
        } catch (const std::exception &e) {
            file.close();
            throw;
        }

        file.close();


}

