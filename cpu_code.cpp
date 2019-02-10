#include <iostream>
#include <cstdio>

using namespace std;

struct C_Num {
  float R;
  float I;
};
const float w = 0.7071067;

int main ()
{
  C_Num X[8], tmp[8];
  int n;
  float my[8] = {1.0, 9.0, 5.0,13.0, 3.0, 11.0, 7.0, 15.0};
  float a_r, a_i;

  for (n=0; n<8; n++){
    X[n].I =0.0;
    tmp[n].I =0.0;
    tmp[n].R = my[n]; // input x signal values
  }
// begin FFT first step
  for(n=0; n<4; n++){
    X[2*n].R = tmp[2*n].R + tmp[2*n+1].R;
    X[2*n+1].R = tmp[2*n].R - tmp [2*n+1].R;
  }
cout << "first step" << endl;
  for(n=0; n<8; n++){
    tmp[n].R = X[n].R;
    tmp[n].I = X[n].I;
    cout << "tmp[" << n << "].R = " << tmp[n].R << "    ";
    cout << "tmp[" << n << "].I = " << tmp[n].I << endl << endl;
  }
// end FFT first step

//Begin FFT second step
cout << "second step" << endl;
tmp[3].I = - tmp[3].R; tmp[3].R = 0;
tmp[7].I = - tmp[7].R; tmp[7].R = 0;

  for(n=0; n<2; n++){
    X[4*n].R = tmp[4*n].R + tmp[4*n+2].R;
    X[4*n+2].R = tmp[4*n].R - tmp [4*n+2].R;
    X[4*n+1].R = tmp[4*n+1].R + tmp[4*n+3].R;
    X[4*n+1].I = tmp[4*n+1].I + tmp[4*n+3].I;
    X[4*n+3].R = tmp[4*n+1].R - tmp[4*n+3].R;
    X[4*n+3].I = tmp[4*n+1].I - tmp[4*n+3].I;
  }

  for(n=0; n<8; n++){
    tmp[n].R = X[n].R;
    tmp[n].I = X[n].I;
  }
  for(n=0; n<8; n++){
   cout << "tmp[" << n << "].R = " << tmp[n].R << "    ";
   cout << "tmp[" << n << "].I = " << tmp[n].I << endl << endl;
  }
// end FFT second step

cout << "FFT third step" << endl;
    // turn X[6].R into I
  tmp[6].I = - tmp[6].R; tmp[6].R = 0;
  getchar();
// compute X[5]*W1 and X[7]*W3 complex
  a_r = w*(tmp[5].R - tmp[7].I);
  a_i = -w*(tmp[5].R + tmp[7].I);
  tmp[5].R=a_r; tmp[5].I=a_i;
  tmp[7].R=a_i; tmp[7].I=a_i;
  cout << "tmp[5].R = " << tmp[5].R << "  tmp[5].I = " << tmp[5].I << endl;
  cout << "tmp[7].R = " << tmp[7].R << "  tmp[7].I = " << tmp[7].I << endl;
  getchar();

  for(n=0; n<4; n++){
    X[n].R = tmp[n].R + tmp[n+4].R;
    X[n].I = tmp[n].I + tmp[n+4].I;
    X[n+4].R = tmp[n].R - tmp [n+4].R;
    X[n+4].I = tmp[n].I - tmp[n+4].I;
  }

for(n=0; n<8; n++){
    cout << "X[" << n << "].R = " << X[n].R << "    ";
    cout << "X[" << n << "].I = " << X[n].I << endl << endl;}

  return 0;
}



