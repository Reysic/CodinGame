#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct User
{
    User() {}
    float longitudeInDegrees;
    float latitudeInDegrees;
};

struct Defibrillator
{
    Defibrillator() {}
    string name;
    float longitudeInDegrees;
    float latitudeInDegrees;
};

Defibrillator* ParseAndCreateDefibrillator( string defibrillatorDescription )
{
    Defibrillator* defibrillator = new Defibrillator();
    size_t posFirstSemicolon = defibrillatorDescription.find( ";" );
    size_t posSecondSemicolon = defibrillatorDescription.find( ";", posFirstSemicolon + 1 );
    defibrillator->name = defibrillatorDescription.substr( posFirstSemicolon + 1, ( posSecondSemicolon - 1 ) - posFirstSemicolon );
    size_t posThirdSemicolon = defibrillatorDescription.find( ";", posSecondSemicolon + 1 );
    size_t posFourthSemicolon = defibrillatorDescription.find( ";", posThirdSemicolon + 1 );
    size_t posFifthSemicolon = defibrillatorDescription.find( ";", posFourthSemicolon + 1 );
    string longitude = defibrillatorDescription.substr( posFourthSemicolon + 1, ( posFifthSemicolon - 1 ) - posFourthSemicolon );
    replace_if( longitude.begin() , longitude.end() , [] ( const char& c ) { return std::ispunct( c ) ;},'.');
    defibrillator->longitudeInDegrees = stof( longitude );
    string latitude = defibrillatorDescription.substr( posFifthSemicolon + 1 );
    replace_if( latitude.begin() , latitude.end() , [] ( const char& c ) { return std::ispunct( c ) ;},'.');
    defibrillator->latitudeInDegrees = stof( latitude );
    return defibrillator;
}

float ConvertDegreesToRadians( float radians )
{
    return ( radians * 3.14159265f / 180.0f );
}

float CalculateDistanceToDefibrillator( User* user, Defibrillator* defibrillator )
{
    float xPos = ( ConvertDegreesToRadians( defibrillator->longitudeInDegrees ) - ConvertDegreesToRadians ( user->longitudeInDegrees ) ) *
        cos ( ( ConvertDegreesToRadians( user->latitudeInDegrees ) + ConvertDegreesToRadians( defibrillator->latitudeInDegrees ) ) / 2.0f );
    float yPos = ConvertDegreesToRadians( defibrillator->latitudeInDegrees ) - ConvertDegreesToRadians( user->latitudeInDegrees );
    return ( sqrt( xPos * xPos + yPos * yPos ) * 6371.0f );
}

int main()
{
    User* user = new User();
    vector< Defibrillator* > defibrillators;
    
    string LON;
    cin >> LON; cin.ignore();
    replace_if( LON.begin() , LON.end() , [] ( const char& c ) { return std::ispunct( c ) ;},'.');
    user->longitudeInDegrees = stof( LON );
    string LAT;
    cin >> LAT; cin.ignore();
    replace_if( LAT.begin() , LAT.end() , [] ( const char& c ) { return std::ispunct( c ) ;},'.');
    user->latitudeInDegrees = stof( LAT );
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        Defibrillator* defibrillator = ParseAndCreateDefibrillator( DEFIB );
        defibrillators.push_back( defibrillator );
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    float closestDefibrillatorDistance = numeric_limits< float >::max();
    string nameOfClosestDefibrillator;
    for ( Defibrillator* defibrillator : defibrillators )
    {
        if ( CalculateDistanceToDefibrillator( user, defibrillator ) < closestDefibrillatorDistance )
        {
            closestDefibrillatorDistance = CalculateDistanceToDefibrillator( user, defibrillator );
            nameOfClosestDefibrillator = defibrillator->name;
        }
    }
    
    cout << nameOfClosestDefibrillator << endl;
}