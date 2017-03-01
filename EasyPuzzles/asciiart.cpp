#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    
    cerr << "L = " + to_string( L ) << endl;
    cerr << "H = " + to_string( H ) << endl;
    
    char capitalLetters [] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '?' };
    char lowerLetters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '?' };
    char asciiData [ H ][ L * 26 + L ];

    cerr << "Provided ASCII data:" << endl;
    
    string T;
    getline(cin, T);
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        
        for ( int charIndex = 0; charIndex < ROW.length(); charIndex++ )
        {
            // Loop through each character in the row
            // and store it in asciiData
            asciiData[ i ][ charIndex ] = ROW.at( charIndex );
        }
        
        cerr << ROW << endl;
    }
    
    cerr << "ASCII data in array:" << endl;
    for ( int row = 0; row < H; row++ )
    {
        string thisRow;
        for ( int column = 0; column < ( L * 26 + L ); column++ )
        {
            thisRow += asciiData[ row ][ column ];
        }
        cerr << thisRow + to_string( thisRow.length() ) << endl;
    }
    cerr << "Done printing ASCII data in array." << endl;
    
    cerr << "T = " + T << endl;
    for ( int rowAgain = 0; rowAgain < H; rowAgain++ )
    {
        string line;
        for ( int charIndex = 0; charIndex < T.length(); charIndex++ )
        {
            char thisChar = T.at( charIndex );
            int indexOfCharInArray = 26;
            for ( int capitalLetterArrayIndex = 0; capitalLetterArrayIndex < 26; capitalLetterArrayIndex++ )
            {
                if ( thisChar == capitalLetters[ capitalLetterArrayIndex ] )
                {
                    indexOfCharInArray = capitalLetterArrayIndex;
                    break;
                }
            }
            
            if ( indexOfCharInArray == 26 )
            {
                for ( int lowerLetterArrayIndex = 0; lowerLetterArrayIndex < 26; lowerLetterArrayIndex++ )
                {
                    if ( thisChar == lowerLetters[ lowerLetterArrayIndex ] )
                    {
                        indexOfCharInArray = lowerLetterArrayIndex;
                        break;
                    }
                }
            }
            for ( int loopIteration = 0; loopIteration < L; loopIteration++ )
            {
                //cerr << "currentCharIndex = " + to_string( indexOfCharInArray ) << endl;
                //cerr << asciiData[ rowAgain ][ currentCharIndex * L ] << endl;
                line += asciiData[ rowAgain ][ indexOfCharInArray * L + loopIteration ];
            }
        }
        cout << line << endl;
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "answer" << endl;
}