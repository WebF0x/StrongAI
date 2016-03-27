#include "UnitTest++/UnitTest++.h"

#include "StrongAI/AI/RandomAI/RandomAI.hpp"

SUITE( RandomAITest )
{
    TEST( constructor )
    {
        RandomAI randomAI( 1, 2, 3, 4 );

        CHECK_EQUAL( 1, randomAI.INPUT_SIZE );
        CHECK_EQUAL( 2, randomAI.OUTPUT_SIZE );
        CHECK_EQUAL( 3, randomAI.INPUT_AMPLITUDE );
        CHECK_EQUAL( 4, randomAI.OUTPUT_AMPLITUDE );
    }

    TEST( output )
    {
        RandomAI randomAI( 0, 10, 0, 1 );

        auto output1 = randomAI.output();
        auto output2 = randomAI.output();

        CHECK_EQUAL( output1.size(), 10 );
    }

    TEST( learn )
    {
        RandomAI randomAI( 1, 1, 1, 1 );
        const std::vector<float> dummyInput( 1, 0 );
        const std::vector<float> dummyOutput( 1, 0 );
        const float dummyOutcome = 1;

        randomAI.learn( dummyInput, dummyOutput, dummyOutcome );
    }
}