#include <boost/lexical_cast.hpp>
#include <iostream>
int main()
{
    using std::string;
    const double d = 123.12;
    string s = boost::lexical_cast<string>(d);
    std::cout<<s<<std::endl;
    return 0;
    return 0;
}
