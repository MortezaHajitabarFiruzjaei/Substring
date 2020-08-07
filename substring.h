// @topic W040503 substring class with overloaded operators
// @brief class substring declaration

// CIS-255 substring class

#ifndef _CIS62_SUBSTRING_H_INCLUDED_
#define _CIS62_SUBSTRING_H_INCLUDED_

#include <string>

class substring {
private:
    std::string& m_str;
	size_t m_begin;
	size_t m_end;
public:
    // Constructor that takes a reference to a string:
    substring( std::string& str );

    // Constructor that takes string reference, beginning, and ending positions
    substring( std::string& str, size_t pos_begin, size_t pos_end );

    // Return copy of the substring as std::string object
    std::string str() const;

    // Return substring size
    size_t size() const;

    // Return beginning position 
    size_t begin() const;

    // Return ending position
    size_t end() const;

    // Set beginning position 
    void begin( size_t pos );

    // Set ending position
    void end( size_t pos );

    // The string content is set to an empty string
    void clear();

    // Replace substring with str
    substring& replace( std::string const& str );

    // Fill substring with a particular character
    substring& fill( char ch );

    // Insert str at the specified position:
    substring& insert( std::string const& str, size_t pos );

    // Convert substring to UPPER CASE
    substring& toupper();

    // Convert substring to lower case
    substring& tolower();

    // Search for a new substring starting at the specified position:
    size_t search( const std::string& str, size_t pos );

    // The string content is set to the size of entire string
    void expand();

    // Equality test between two substrings
    bool equals_to( substring const& other ) const;

    // Equality test between substring and std::string
    bool equals_to( std::string const& str ) const;

    // Merge with another substring
    substring& merge( substring const& other );

    // Swap with another substring
    void swap( substring& other );

    // Prepare substring for parsing
    substring& parse();

    // Test if substring is alphabetic
    substring& isalpha();

    // Test if substring is upper case
    substring& isupper();

    // Test if substring is lower case
    substring& islower();

    // Test if substring is digit
    substring& isdigit();

    // Test if substring is alphabetic or digit
    substring& isalnum();

    // Test if substring is blank, tab, newline, return, formfeed, or vertical tab 
    substring& isspace();

    // Test if substring is matches text specified by str 
    substring& isstr( const std::string& str );

    // Test if substring is empty
    substring& isempty();

    // Return true if parsing succeeded, false otherwise
    bool succeeded() const;

    // Return matching substring
    substring match() const;

    // Undo changes caused by parsing
    substring& unparse();

	// PART 2 -- overloaded operators
public:
    friend std::ostream& operator<<( std::ostream& os, substring const& sub );
	friend bool operator==( substring const& one, substring const& another );
	friend bool operator==( std::string const& str, substring const& sub );
	friend bool operator==( substring const& sub, char const* cstr );
    // Operators overloaded as members functions:

    // Assignments:
    substring& operator=( substring const& other );
    substring& operator=( std::string const& str );

    // Merge with another substring:
    substring& operator+=( substring const& other );

    // Compare with another substring:
    bool operator>( substring const& other ) const;
    bool operator<( substring const& other ) const;

    // Subscript access to individual characters within substring:
    char& operator[]( size_t idx );
    char operator[]( size_t idx ) const;
};//class substring

// Operators overloaded as non-member functions:
std::ostream& operator<<( std::ostream& os, substring const& sub );

// Equality/Inequality tests between two substrings:
bool operator==( substring const& one, substring const& another );
bool operator!=( substring const& one, substring const& another );

// Equality/Inequality tests between substring and std::string:
bool operator==( std::string const& str, substring const& sub );
bool operator==( substring const& sub, std::string const& str );
bool operator!=( std::string const& str, substring const& sub );
bool operator!=( substring const& sub, std::string const& str );

// Equality/Inequality tests between substring and zero-terminated string:
bool operator==( substring const& sub, char const* cstr );
bool operator!=( substring const& sub, char const* cstr );
bool operator==( char const* cstr, substring const& sub );
bool operator!=( char const* cstr, substring const& sub );

#endif // _CIS62_SUBSTRING_H_INCLUDED_
