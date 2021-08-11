#include <iostream>
#include <fstream>

const char *filename = "out.txt";

int main () {
    long l, m;
    ifstream in ( filename, ios::in | ios::binary );
    l = in.tellg();
    in.seekg ( 0, ios::end );
    m = in.tellg();
    in.close();
    cout << "size of " << filename;
    cout << " is " << ( m - l ) << " bytes.\n";
    return 0;
}