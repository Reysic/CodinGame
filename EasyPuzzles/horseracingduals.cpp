#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    vector< int > horseStrengths;
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        horseStrengths.push_back( Pi );
    }

    sort( horseStrengths.begin(), horseStrengths.end() );
    
    int smallestDifference = 9999;
    for ( int strengthIndex = 0; strengthIndex < N - 1; ++strengthIndex )
    {
        if ( abs( horseStrengths[ strengthIndex ] - horseStrengths[ strengthIndex + 1 ] ) < smallestDifference )
        {
            smallestDifference = abs( horseStrengths[ strengthIndex ] - horseStrengths[ strengthIndex + 1 ] );
        }
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << smallestDifference << endl;
}