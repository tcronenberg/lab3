#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

complex<double> calcz(double phi);

int main(){
  
  int N = 1000;

  // Example how to declare a single complex variable:
  complex<double> z[N];
  complex<double> f[N];

  // d = 1 + 2i 
  // complex<double> d = complex<double>(1.0, 2.0); 
  complex<double> ii = complex<double>(0.0, 1.0);
  
  double dphi = 2*M_PI/N;
  double phi;
  
  for(int i = 0; i < N; i++)
      z[i] = exp(i*dphi*ii);
  
  for(int i = 0; i < N; i++){
    phi = i*dphi-M_PI;
    f[i] = calcz(phi);
  }
  
  for(int i = 0; i < N; i++){
      //cout << i*dphi << "\t" << real(z[i]) << "\t" << imag(z[i]) << "\t" << abs(z[i]) << endl;
    cout << i*dphi << "\t" << real(f[i]) << "\t" << imag(f[i]) << "\t" << abs(f[i]) << endl;
  }

  return 0;
}

complex<double> calcz(double phi){
  complex<double> ii = complex<double>(0.0, 1.0);
  
 return tan(phi*(1.+ii)); 
}
