 
#include	<cstdlib>
#include	<fstream>
#include	<iomanip>   
#include	<iostream>  
#include        "a.h"

using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] )
{
    Tdate s;
    s.Set(2,15,1988);
    s.Print();
	cout	<< "\nProgram " << argv[0] << endl << endl;

	return EXIT_SUCCESS;
}		// ----------  end of function main  ---------- 

