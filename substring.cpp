#include <iostream>
#include <string>
#include <stdio.h>

class substring {
    friend std::ostream& operator<<(std::ostream& output, substring const& sub);

private:
	    char *str;
    int length;
public:


    substring();
    ~substring();
    substring(std::string);
    substring(const substring &);

    substring& operator=(substring const& other);
    substring& operator=(std::string const& strz);

    substring& operator+=(substring const& other);

    bool operator>(substring const& other) const;
    bool operator<(substring const& other) const;

    char& operator[](size_t idx);
    char operator[](size_t idx) const;

};

std::ostream& operator<<(std::ostream& output, substring const& sub);
std::istream& operator >> (std::istream& input, substring const& sub);


bool operator==(substring const& one, substring const& another); 
bool operator!=(substring const& one, substring const& another); 

bool operator==(std::string const& str, substring const& sub); 
bool operator==(substring const& sub, std::string const& str);
bool operator!=(std::string const& str, substring const& sub);
bool operator!=(substring const& sub, std::string const& str); 


substring::substring()
{
    length = 0;
}

substring::~substring()
{
    delete str;
}

substring::substring(std::string)
{
}

substring::substring(const substring & sub)
{
    str = new char[length];
}

std::ostream & operator<<(std::ostream & output, substring const & sub)
{
    output << sub;
    return output;
}

std::istream & operator >> (std::istream & input, substring const & sub)
{
    std::cout << "Enter  sub:";
    input >> sub;
    return input;
}

bool operator==(substring const & one, substring const & another)
{
    if (one.length != another.length)
        return false;
    else
    {
        for (int i = 0; i < substring::length(); i++)
            if (one[i] != another[i])
            {
                return false;
                break;
            }
    }
    return true;
}

bool operator!=(substring const & one, substring const & another)
{
    if (one.length != another.length)
        return true;
    else
    {
        for (int i = 0; i < another.length; i++)
            if (one[i] != another[i])
            {
                return true;
                break;
            }
    }
    return false;
}

bool operator==(std::string const & str, substring const & sub)
{

    if (sub.length != str.length())
        return false;
    else
    {
        for (int i = 0; i < sub.length; i++)
            if (str[i] != sub[i])
            {
                return false;
                break;
            }
    }
    return true;
}

bool operator==(substring const & sub, std::string const & str)
{
    if (str.length() != sub.length)
        return false;
    else
    {
        for (unsigned int i = 0; i < str.length(); i++)
            if (sub[i] != str[i])
            {
                return false;
                break;
            }
    }
    return true;
}

bool operator!=(std::string const & str, substring const & sub)
{
    if (sub.length != str.length())
        return true;
    else
    {
        for (int i = 0; i < sub.length; i++)
            if (str[i] != sub[i])
            {
                return true;
                break;
            }
    }
    return false;
}

bool operator!=(substring const & sub, std::string const & str)
{
    if (sub.length != str.length())
        return true;
    else
    {
        for (int i = 0; i < sub.length; i++)
            if (str[i] != sub[i])
            {
                return true;
                break;
            }
    }
    return false;
}

substring & substring::operator=(substring const & other)
{
    delete str;
    length = other.length;
    str = new char[length];
    for (int i = 0; i<length; i++)
    {
        str[i] = other.str[i];
    }
    return *this;
}

substring & substring::operator=(std::string const & strz)
{
    length = strz.length();
    str = new char[length];
    for (int i = 0; i<length; i++)
    {
        str[i] = strz[i];
    }
    return *this;
}

substring & substring::operator+=(substring const & other)
{
    char* new_str = new char[length + other.length];
    for (int i = 0; i<length; i++)
    {
        new_str[i] = str[i];
    }
    for (int i = length; i<other.length; i++)
    {
        new_str[i] = other.str[i];
    }
    delete str;
    str = new_str;
    return *this;
}

bool substring::operator>(substring const & other) const
{
        return true;
}

bool substring::operator<(substring const & other) const
{
        return true;
}

char & substring::operator[](size_t idx)
{
    return str[idx];
}

char substring::operator[](size_t idx) const
{
    return str[idx];
}

int main()
{
    std::string str = "abc";
    substring sub = str;

    std::cout << sub;

    return 0;
}