//
// Created by Michał on 13.01.2025.
//

#ifndef IRESULTENCODER_H
#define IRESULTENCODER_H
#include <vector>



    //class IEvaluator;

    template<typename T>
    class IResultEncoder {

        /** @brief Interface for encoding the result
         *
         *  Interface for encoding the result. It takes the values of the result and calculates the fitness
         *  based on the points from the GroupingChallenge
         */

    public:
        IResultEncoder() = default;

        //IResultEncoder(const int groupCount, std::vector<int>& values, IEvaluator* evaluator){};

        IResultEncoder(IResultEncoder& result_encoder) { *this = *result_encoder.clone(); };

        virtual ~IResultEncoder() = default;

        virtual IResultEncoder* clone() = 0;

        virtual std::vector<T> getValues() = 0;

        virtual double getFitness() = 0;

        virtual T get(size_t index) = 0;

        virtual void set(size_t index, T value) = 0;

        virtual void set(std::vector<T>& values) = 0;

        virtual size_t size() = 0;

        virtual int groupCount() = 0;

        virtual bool mutate(double chance) = 0;

        virtual void fillWithRandomValues(int size) = 0;

        //IResultEncoder& operator=(IResultEncoder&& result_encoder) noexcept { return *this; } ;

    };




#endif //IRESULTENCODER_H
