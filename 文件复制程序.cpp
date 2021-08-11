#include <iostream>
#include <fstream>

using namespace std;

int main ( int argc, char* argv[] ) {
    if ( argc != 3 ) {
        cerr << "输入形式：test 源文件名 目标文件名\n";
        return ( 1 );
    }

    ifstream in;
    in.open ( argv[1], ios::in | ios::binary );

    ofstream out;
    out.open ( argv[2], ios::out | ios::binary );

    char ch;

    while ( in.get ( ch ) ) {
        out << ch;
    }

    in.close();
    out.close();
    return 0;
}