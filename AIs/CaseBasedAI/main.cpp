#include <iostream>
#include "CaseBasedAI.h"

using namespace std;

int main()
{
    const unsigned int inputSize(1), outputSize(1);
    const int maxInput(1), maxOutput(2);
    const string fileName = "Fox.txt";

    //Create GeneralAI
    GeneralAI *ai = new CaseBasedAI(inputSize,outputSize,maxInput,maxOutput);

    //load
    try
    {
        ai->load(fileName);
    }
    catch(exception& e)
    {
        cout<<e.what()<<endl;
    }

    vector<int> aiOutput;

    //output
    try
    {
        vector<int> v(inputSize);
        aiOutput = ai->output(v);

        cout<<"Output:\n";
        for(unsigned int i=0; i<outputSize; ++i)
        {
            cout<<aiOutput[i]<<endl;
        }
    }
    catch(exception& e)
    {
        cout<<e.what()<<endl;
    }

    //learn
    try
    {
        vector<int> input(inputSize);
        float outcome = .5f;
        ai->learn(input, aiOutput, outcome);
    }
    catch(exception& e)
    {
        cout<<e.what()<<endl;
    }

    //save
    try
    {
        ai->save(fileName);
    }
    catch(exception& e)
    {
        cout<<e.what()<<endl;
    }

    //Delete GeneralAI
    delete ai;

    return 0;
}
