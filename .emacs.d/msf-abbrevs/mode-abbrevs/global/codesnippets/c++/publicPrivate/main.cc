

#include	<cstdlib>
#include	<fstream>
#include	<iomanip>   
#include	<iostream>  

using namespace std;

class Base
{
    public:
        Base(int a, int b = 0);
        int GetA();
        int m_b;
    private:
        int GetB();
        int m_a;
};

Base::Base(int a, int b)
{
    m_a = a;
    m_b = b;
}
int Base::GetA()
{
    return m_a;//类的内部可以访问私有变量, 正确
}
int Base::GetB()
{
    return m_b;//类的内部可以访问公有变量, 正确
}

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] )
{
    int num;
    Base b(10);

   // num = b.m_a; //类的外部不能访问私有变量, 错误
    num = b.m_b;//类的外部可以访问公有变量, 正确

    cout	<< "\nProgram " << argv[0] << endl << endl;

    return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

