#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 string GetExtension( const string& fileNameWithExtension )
 {
    size_t pos = fileNameWithExtension.find_last_of( "." );
    
    if ( pos == string::npos )
    {
        return "UNKNOWN";
    }
    else
    {
        string extension = fileNameWithExtension.substr( pos + 1, string::npos );
        transform( extension.begin(), extension.end(), extension.begin(), ::tolower );
        return extension;
    }
    
    return "UNKNOWN";
}

int main()
{
    map< string, string > mimeTypes;
    vector< string > fileNames;
    
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        //cerr << EXT << " " << MT << endl;
        transform( EXT.begin(), EXT.end(), EXT.begin(), ::tolower );
        mimeTypes.insert( pair< string, string >( EXT, MT ) );
        //cerr << mimeTypes.find( "html" )->second << endl;
    }
    // cerr << mimeTypes.find( "gif" )->second << endl;
    //cerr << mimeTypes.find( "png")->second << endl;
    //cerr << mimeTypes.find( "html")->second << endl;
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        fileNames.push_back( FNAME );
    }
    
    for ( int fileNameIndex = 0; fileNameIndex < Q; ++fileNameIndex )
    {
        cerr << fileNames[ fileNameIndex ] << endl;
        string extension = GetExtension( fileNames[ fileNameIndex ] );
        cerr << extension << endl;
        map< string, string >::iterator it = mimeTypes.find( extension );
        if ( it == mimeTypes.end() )
        {
            cout << "UNKNOWN" << endl;
        }
        else
        {
            string mime = it->second;
            cout << mime << endl;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    for ( auto elem : mimeTypes )
    {
        cerr << elem.first << " " << elem.second << endl;
    }
    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    //cout << "UNKNOWN" << endl;
}