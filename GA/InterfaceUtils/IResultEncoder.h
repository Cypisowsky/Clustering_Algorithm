//
// Created by Michał on 13.01.2025.
//

#ifndef IRESULTENCODER_H
#define IRESULTENCODER_H
#include <vector>


namespace NGroupingChallenge {
    //class IEvaluator;

    template<typename T>
    class IResultEncoder {

    public:
        IResultEncoder() = default;

        //IResultEncoder(const int groupCount, std::vector<int>& values, IEvaluator* evaluator){};

        IResultEncoder(IResultEncoder& result_encoder) = default;

        virtual ~IResultEncoder() = default;

        virtual IResultEncoder* clone() { return new IResultEncoder(*this); };

        virtual std::vector<T> getValues();

        virtual double getFitness() { return 0; }

        virtual T get(size_t index) { return T(); }

        virtual void set(size_t index, T value) { }

        virtual void set(std::vector<T>& values) { }

        virtual size_t size() { return 0; }

        virtual int groupCount() { return 0; }

        virtual bool mutate(double chance) { return false; }

        //IResultEncoder& operator=(IResultEncoder&& result_encoder) noexcept { return *this; } ;

    };
}



#endif //IRESULTENCODER_H
