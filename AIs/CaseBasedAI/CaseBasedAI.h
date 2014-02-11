#ifndef CASEBASEDAI_H
#define CASEBASEDAI_H

#include "../GeneralAI/GeneralAI.h"
#include <map>
#include <chrono>
#include <random>
#include <limits>   //numeric_limits<int>::max()

class CaseBasedAI : public GeneralAI
{
    public:
        CaseBasedAI(int inputSize, int outputSize, int maxInput, int maxOutput);
        virtual ~CaseBasedAI();

    private:
        virtual void coreLearn(const std::vector<int>& input, const std::vector<int>& output, float outcome);
        virtual std::vector<int> coreOutput(const std::vector<int>& input);

        virtual std::vector<int> getMemory() const;
        virtual void setMemory(std::vector<int> memory);

        //             Input                     Output       Outcome
        std::map< std::vector<int>, std::map<std::vector<int>, float> > m_memory;

        std::default_random_engine randomGenerator;
        float randomProbability();
        std::vector<int> randomOutput();
        std::vector<int> randomNewOutput(const std::map<std::vector<int>, float>& reactions);

        std::vector<int> bestOutput(const std::map<std::vector<int>, float>& reactions);


};

#endif // CASEBASEDAI_H
