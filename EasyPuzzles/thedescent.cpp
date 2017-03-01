#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/
int main()
{

    std::vector< int > mountainHeights;
    int tallestHeight = -1;
    int indexOfTallestHeight = -1;
    
    // game loop
    while (1) {
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain.
            cin >> mountainH; cin.ignore();
            mountainHeights.push_back( mountainH );
        }
        
        for ( int heightIndex = 0; heightIndex < mountainHeights.size(); heightIndex++ )
        {
            if ( mountainHeights[ heightIndex ] > tallestHeight )
            {
                tallestHeight = mountainHeights[ heightIndex ];
                indexOfTallestHeight = heightIndex;
            }
        }
        
        mountainHeights.clear();
        tallestHeight = -1;
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << indexOfTallestHeight << endl; // The index of the mountain to fire on.
    }
}