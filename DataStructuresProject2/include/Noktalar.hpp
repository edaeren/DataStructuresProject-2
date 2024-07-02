#ifndef NOKTALAR_HPP
#define NOKTALAR_HPP
#include <iostream>
#include <math.h>
using namespace std;
class Noktalar{
	public:
		int x,y,z;
		int orijineUzaklik;
		Noktalar();
		Noktalar(int,int,int);
		friend ostream& operator<<(ostream&, Noktalar&);
};
#endif