
#ifndef A_H_
#define A_H_
#include <iostream>                                                             

class Tdate{
public:
  void Set(int,int,int);
  int IsLeapYear();
  void Print();
private:
  int month;
  int day;
  int year;
};

#endif 

