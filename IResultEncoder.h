//
// Created by Michał on 13.01.2025.
//

#ifndef IRESULTENCODER_H
#define IRESULTENCODER_H
#include <vector>


namespace NGroupingChallenge {
    template<typename T>
    class IResultEncoder<T> {

    public:
        IResultEncoder() = default;

        IResultEncoder(IResultEncoder& result_encoder) = default;

        virtual ~IResultEncoder() = default;

        virtual std::vector<T> getValues() { return T(); }

        virtual double getFitness() { return 0; }

        virtual T get(size_t index) { return T(); }

        virtual void set(size_t index, T value) { }

        virtual size_t size() { return 0; }

        virtual int groupCount() { return 0; }

        virtual bool mutate(double chance) { return false; }

    };
}



#endif //IRESULTENCODER_H
