#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main(){

  // Example how to declare a single complex variable:
  complex<double> zn;
  complex<double> znp1;
  complex<double> z0;
  int itmax = 400;
  int iter;
  double err;
  
  // d = 1 + 2i 
  // complex<double> d = complex<double>(1.0, 2.0); 
  
  for(double re = -2; re <= 2; re+=0.1){
      for(double im = -2; im <= 2; im+=0.1){
	  z0 = complex<double>(re,im);
	  iter = 0;
	  zn = z0;
	  err = 1;
	  while((iter < itmax) & (err > 1e-8)){
		iter++;
		znp1 = zn-(pow(zn,3)-complex<double>(1,0))/(3.0*pow(zn,2));
		err = abs(zn-znp1);
		zn = znp1;
	  }
	  cout << re << "\t" << im << "\t" << iter << endl;
      }
  }

  return 0;
}
