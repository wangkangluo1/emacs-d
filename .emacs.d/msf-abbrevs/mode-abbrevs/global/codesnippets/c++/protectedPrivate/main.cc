/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/22/2011 09:41:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kangle.wang (mn), wangkangluo1@gmail.com
 *        Company:  APE-TECH
 *
 * =====================================================================================
 */


#include	<cstdlib>
#include	<fstream>
#include	<iomanip>   
#include	<iostream>  

using namespace std;

class Base
{
    public:
        Base(int a, int b = 0);
    protected:
        int m_b;
    private:
        int m_a;
};

class Derive : public Base
{
    public:
        Derive(int a, int b = 0) : Base(a, b) {}
        int GetA();
        int GetB();
};

Base::Base(int a, int b)
{
    m_a = a;
    m_b = b;
}
int Derive::GetA()
{
    return 1;
    //return m_a;//派生类不能访问基类的私有变量, 错误
}
int Derive::GetB()
{
    return m_b;//派生类可以访问基类的保护变量, 正确
}

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] )
{
    int num = 0;
    Base b(10, 20);

    //num = b.m_a; //类的外部不能访问私有变量, 错误
    //num = b.m_b; //类的外部不能访问保护变量, 错误
    cout	<< "\nProgram " << argv[0] << endl << endl;

    return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

