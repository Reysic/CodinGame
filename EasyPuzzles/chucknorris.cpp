#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    string BINARY;
    for ( size_t charIndex = 0; charIndex < MESSAGE.size(); ++charIndex )
    {
        BINARY += ( bitset< 7 >( MESSAGE.c_str()[ charIndex ] ) ).to_string();
        cerr << BINARY << endl;
    }
        
    string UNARY;
    char currentBit = BINARY.at( 0 );
    string nextSeriesIndicator;
    if ( currentBit == '0' )
    {
        UNARY += "00 ";
        nextSeriesIndicator = " 0 ";
    }
    else
    {
        UNARY += "0 ";
        nextSeriesIndicator = " 00 ";
    }
    size_t countForCurrentBit = 1;

    for ( size_t charIndex = 1; charIndex < BINARY.size(); ++charIndex )
    {
        if ( currentBit == BINARY.at( charIndex ) )
        {
            ++countForCurrentBit;
        }
        else
        {
            for ( size_t bitCount = 0; bitCount < countForCurrentBit; ++bitCount )
            {
                UNARY += "0";
            }
            UNARY += nextSeriesIndicator;
            if ( nextSeriesIndicator.compare( " 00 " ) == 0 )
            {
                nextSeriesIndicator = " 0 ";
            }
            else
            {
                nextSeriesIndicator = " 00 ";
            }
            currentBit = BINARY.at( charIndex );
            countForCurrentBit = 1;
        }
    }
    for ( size_t bitCount = 0; bitCount < countForCurrentBit; ++bitCount )
    {
        UNARY += "0";
    }
    
    cout << UNARY << endl;
}