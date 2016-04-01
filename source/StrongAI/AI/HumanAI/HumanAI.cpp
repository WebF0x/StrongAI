#include "StrongAI/AI/HumanAI/HumanAI.hpp"

HumanAI::HumanAI( int inputSize, int outputSize, int maxInput, int maxOutput )
    : GeneralAI( inputSize, outputSize, maxInput, maxOutput )
{

}

std::vector< float > HumanAI::coreOutput( const std::vector< float >& input )
{
    std::cout << "What is your Output?" << std::endl
         << "====================" << std::endl;

    // Display inputs
    std::cout << "Input" << std::endl
         << "-----" << std::endl;

    visualizeInput( input );
    std::cout << std::endl;

    // Ask outputs
    std::cout << "Output" << std::endl
         << "------" << std::endl
         << "( Between " << -OUTPUT_AMPLITUDE << " and " << OUTPUT_AMPLITUDE << " )" << std::endl;

    std::vector< float > output;
    for( int i = 0; i < OUTPUT_SIZE; i++ )
    {
        std::cout << "Output " << i << "/" << OUTPUT_SIZE - 1 << ": " << std::endl;

        float userInput;

        do
        {
            std::cout << "";
            std::cin >> userInput;
        }while( userInput < -OUTPUT_AMPLITUDE || userInput > OUTPUT_AMPLITUDE );
        std::cout << std::endl;

        output.push_back( userInput );
    }

    return output;
}

void HumanAI::coreLearn( const std::vector< float >& input, const std::vector< float >& output, float outcome )
{
    std::cout << "Learn this" << std::endl
         << "==========" << std::endl;

    std::cout << "Input: ";
    visualizeInput( input );
    std::cout << std::endl
         << std::endl;

    std::cout << "Output: ";
    printVector( output );
    std::cout << std::endl
         << std::endl;

    std::cout << "Outcome: " << outcome << std::endl
         << std::endl;
}

void HumanAI::printVector( const std::vector< float >& vect ) const
{
    std::cout << '[';

    if( !vect.empty() )
    {
        std::cout << vect[ 0 ];
        for( unsigned int i = 1; i < vect.size(); i++ )
        {
            std::cout << ", " << vect[ i ];
        }
    }

    std::cout << ']' << std::endl;
}

void HumanAI::visualizeInput( const std::vector< float >& input )
{
    printVector( input );
}
