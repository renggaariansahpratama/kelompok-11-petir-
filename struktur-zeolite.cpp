%%writefile struktur-zeolite.cpp

#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"


using namespace std;


void zeolit(){
    
}
void ep(){
    
}

int main (){
    
    zeolit();
    ep();
    
    // deklarasi variabel
    float pi = 3.14;
    int counter = 0;

// deklarasi struktur-zeolit
float Alx, Aly, Alz;
float Six, Siy, Siz;
float O1x[125], O1y[125], O1z[125]
float O2x[125], O2y[125], O2z[125]
float O3x[125], O3y[125], O3z[125]
float O4x[125], O4y[125], O4z[125]

 // masukkan nilai untuk setiap variabel [AlO4].[SiO4]
   
   float rB_Alx = 0.0;
   float rB_Aly = 0.0;
   float rB_Alz = 0.0;
   
   float rB_Six = sin(88.75*pi/180) * 177.5;
   float rB_Siy = 0.0;
   float rB_Siz = cos(88.75*pi/180) * 177.5;

    float rB_O1x = - rB_Alx;
    float rB_O1y = rB_Aly;
    float rB_O1z = rB_Alz;
    
    float rB_O2x = - rB_Alx;
    float rB_O2y = rB_Aly;
    float rB_O2z = rB_Alz;
    
    float rB_O3x = - rB_Alx;
    float rB_O3y = rB_Aly;
    float rB_O3z = rB_Alz;
   
    float rB_O4x = - rB_Alx;
    float rB_O4y = rB_Aly;
    float rB_O4z = rB_Alz;
    
    float rB_Alx ;counter;rB_Alx + (i*3,01)
    float rB_Aly ;counter;rB_Aly + (j*3,01)
    float rB_Alz ;counter;rB_Alz + (k*3,01)
    
    float rB_six ;counter;rB_six ;counter + rB_six;
    float rB_siy ;counter;rB_siy ;counter + rB_siy;
    float rB_siz ;counter;rB_siz ;counter + rB_siz;
    
    float rB_O1x ;counter;rB_six ;counter + rB_O1x;
    float rB_O1y ;counter;rB_siy ;counter + rB_O2y;
    float rB_O1z ;counter;rB_siz ;counter + rB_O1z;
    
    float rB_O2x ;counter;rB_six ;counter + rB_O2x;
    float rB_O2y ;counter;rB_siy ;counter + rB_O2y;
    float rB_O2z ;counter;rB_siz ;counter + rB_O2z;
    
    float rB_O3x ;counter;rB_six ;counter + rB_O3x;
    float rB_O3y ;counter;rB_siy ;counter + rB_O3y;
    float rB_O3z ;counter;rB_siz ;counter + rB_O3z;
    
    float rB_O4x ;counter;rB_six ;counter + rB_O4x;
    float rB_O4y ;counter;rB_siy ;counter + rB_O4y;
    float rB_O4z ;counter;rB_siz ;counter + rB_O4z;
    
    counter += 1;
   }
}

    
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
    
    
    
    
    
    
    
    
   
    
    


float densitas;          /* densitas ini memiliki satuan g cm^-3
                            dan ini harus diinput dari user */
// converter dari nilai cm^-3 ke A^3
float cm3_to_A3 = 1.0E-24;  
float numb_mol;
float Na = 6.022E23;            // bilangan avogadro    
float Mr_SiO2 = 60.08;          // massa relatif dari SiO2 
int numb_lat;                   // panjang sel simulasi    
int N;                          // jumlah molekul 
float volum;                    // volume dari molekul SiO2
float lx, ly, lz;               // panjang sel simulasi terhitung
float lat;                      // jarak antar molekul SiO2

// variabel perhitungan energi potensial 
float sigma = 2.725;            // satuan (A)
float epsilon = 3.725;          // satuan (kj/mol)
float rij, rcut, rcut2;
float Ep, Ep_LJ, A12, B6;
float rij6, rij12;
float dx, dy, dz;       


