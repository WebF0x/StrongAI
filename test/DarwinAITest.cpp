#include "UnitTest++/UnitTest++.h"

#include "AI/DarwinAI/DarwinAI.hpp"

class MyDarwinAI : public DarwinAI
{
    public:
        MyDarwinAI( const unsigned int populationSize = 2 ) :
            DarwinAI( 0, 1, 0, 1, populationSize )
        {
        }

    private:
        //Select for highest output
        double fitnessEval( NeuralNetAI& ai )
        {
            auto output = ai.output();
            auto fitness = output.front();
            return fitness;
        };

        friend cereal::access;
        template < class Archive >
        void serialize( Archive & ar )
        {
            ar( cereal::virtual_base_class< DarwinAI >( this ) );
        }
};

SUITE( DarwinAITest )
{
    TEST( smokeTest )
    {
        std::unique_ptr< DarwinAI > ai( new MyDarwinAI() );

        auto output = ai->output();
        CHECK_EQUAL( 1, output.size() );

        ai->learn( 1 );
    }

    TEST( saveAndLoad )
    {
        const std::string saveFileName = "MyDarwinAI.save";

        MyDarwinAI originalAI;
        MyDarwinAI cloneAI;

        GeneralAI::save< MyDarwinAI >( originalAI, saveFileName );
        GeneralAI::load< MyDarwinAI >( cloneAI,    saveFileName );

        const auto expectedOutput = originalAI.output();
        const auto actualOutput   = cloneAI.output();
        const double tolerance    = 0.01;
        CHECK_ARRAY_CLOSE( expectedOutput, actualOutput, 1, tolerance );

        // Delete save file
        CHECK( !remove( saveFileName.data() ) ) ;
    }

    TEST( seeksGoodOutcome )
    {
        MyDarwinAI ai;

        const std::vector< double > input;
        const std::vector< double > expectedOutput( { 1 } );
        ai.learn( input, expectedOutput, 1 );

        const auto actualOutput = ai.output( input );
        const auto outputSize   = expectedOutput.size();
        const double tolerance  = 0.1;
        CHECK_ARRAY_CLOSE( expectedOutput, actualOutput, outputSize, tolerance );
    }

    TEST( evolvesToDesiredFitness )
    {
        const double desiredFitness = 0.95;

        MyDarwinAI ai;
        ai.evolveToFitness( desiredFitness );

        CHECK( ai.fitness() >= desiredFitness );
    }

    TEST( populationOfNextGenerationKeepsSameSizeWhenEven )
    {
        const unsigned int initialPopulationSize = 2;
        MyDarwinAI ai( initialPopulationSize );
        ai.evolve();
        CHECK( ai.getPopulationSize() == initialPopulationSize );
    }

    TEST( populationOfNextGenerationKeepsSameSizeWhenOdd )
    {
        const unsigned int initialPopulationSize = 3;
        MyDarwinAI ai( initialPopulationSize );
        ai.evolve();
        CHECK( ai.getPopulationSize() == initialPopulationSize );
    }
}
