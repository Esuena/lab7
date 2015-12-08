#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


void writing(double* k, const double* const y, double eta){
 
 k[0] = y[1];
 k[1] = (eta-y[0]*y[0])*y[0];

}

int main(){
  double eta=0.5;
  double y[2];
  double y_temp[2];
  double k1[2];
  double k2[2];
  double k3[2];
  
  double x, dx;
  
  cout << "dx=";
  cin >> dx;
  
  ofstream myfile;
 
  myfile.open ("Rungekutta.txt");
  
  y[0] = 1e-5;
  y[1] = sqrt(eta) * y[0];
  
  for(x=0; x<=100; x+=dx){
 
  writing(k1, y, eta);
  
  y_temp[0] = y[0]+dx*0.5*k1[0];
  y_temp[1] = y[1]+dx*0.5*k1[1];
  
  writing(k2, y_temp, eta);
  
  y_temp[0] = y[0]+ dx*(-k1[0]+2*k2[0]);
  y_temp[1] = y[1]+ dx*(-k1[1]+2*k2[1]);
  
  writing(k3, y_temp, eta);
  
  y[0] += dx*(k1[0]+ 4*k2[0]+ k3[0])/6.;
  y[1] += dx*(k1[1]+ 4*k2[1]+ k3[1])/6.;
  
  myfile << x << "\t" << y[0] << "\t" << y[1] << endl;
  }
  
  myfile.close();
  
  return 0;
}