// @topic W040508 substring class with overloaded operators
// @brief main() -- test for overloaded substring operators

// main.cpp

#include <cassert>
#include <iostream>
#include "substring.h"

int main()
{
    using std::string;
    using std::cout;
    //------------------------------
    string str = "Hello";
    //            012345...
    substring sub( str );
    cout << sub.str() << '\n';
    sub.clear();
    cout << sub.str() << '\n';

    //------------------------------
    string str2 = "Goodbye";
    //             012345678901234567890123456789
    //             0         1         2
    substring sub2( str2, 4, 7 );
    cout << sub2.str() << '\n';
    sub2.replace( " job" );
    cout << sub2.str() << '\n';
    sub2.fill( '@' );
    cout << str2 << '\n';


    cout << "operator<< test: " << sub2 << '\n';

    if ( sub2 == sub2 ) {
        cout << '\n' << __FILE__ << ":" << __LINE__ << '\n';
        cout << "operator== test: sub2 == sub2 is true: " << sub2 << '\n';
    }

    string str3 = "hello";
    substring sub3( str3 );

    if ( str3 == sub3 ) {
        cout << '\n' << __FILE__ << ":" << __LINE__ << '\n';
        cout << "operator== test: str == sub is true: " << sub3 << '\n';
    }

    if ( sub3 == str3 ) {
        cout << '\n' << __FILE__ << ":" << __LINE__ << '\n';
        cout << "operator== test: str == sub is true: " << sub3 << '\n';
    }

    if ( sub3 == "hello" ) {
        cout << '\n' << __FILE__ << ":" << __LINE__ << '\n';
        cout << "operator== test: str == sub is true: " << sub3 << '\n';
    }

    sub3 = "bye";
    cout << '\n' << __FILE__ << ":" << __LINE__ << '\n';
    cout << "operator= test: sub3 is: " << sub3 << '\n';

    sub3 = sub2;
    cout << '\n' << __FILE__ << ":" << __LINE__ << '\n';
    cout << "operator= test: sub3 is: " << sub3 << '\n';

    sub3 = sub3;

    sub2 = "abc";
    sub3 = "xyz";
    if ( sub3 > sub2 ) {
        cout << '\n' << __FILE__ << ":" << __LINE__ << '\n';
        cout << "operator>: " << sub3 << ">" << sub2 << '\n';
    }

    sub2 = "x";
    sub3 = "xyz";
    if ( sub3 > sub2 ) {
        cout << '\n' << __FILE__ << ":" << __LINE__ << '\n';
        cout << "operator>: " << sub3 << ">" << sub2 << '\n';
    }

    sub3[ 0 ] = toupper( sub3[ 0 ] );
    sub3[ 1 ] = toupper( sub3[ 1 ] );
    sub3[ 2 ] = toupper( sub3[ 2 ] );
    cout << '\n' << __FILE__ << ":" << __LINE__ << '\n';
    cout << "operator[] test: " << sub3 << '\n';

    return 0;
}
