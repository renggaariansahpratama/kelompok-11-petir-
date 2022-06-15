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
    
    // memasukkan nilai tersebut ke dalam file
    ofstream file;
    file.open("struktur-zeolite.xyz");
    file<<"3\n"<< endl;
    file<<setw(3)<<"Al"<<setw(3)<< " "\
    <<fixed<<setprecision(3)<<Alx<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<Aly<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<Alz<<setw(3)<<" "\n;
    
    file<<setw(3)<<"Si"<<setw(3)<< " "\
    <<fixed<<setprecision(3)<<Six<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<Siy<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<Siz<<setw(3)<<" "\n;
    
    file<<setw(3)<<"O1"<<setw(3)<< " "\
    <<fixed<<setprecision(3)<<Olx<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<O1y<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<O1z<<setw(3)<<" "\n;
    
    file<<setw(3)<<"O2"<<setw(3)<< " "\
    <<fixed<<setprecision(3)<<O2x<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<O2y<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<O2z<<setw(3)<<" "\n;
    
    file<<setw(3)<<"O3"<<setw(3)<< " "\
    <<fixed<<setprecision(3)<<O3x<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<O3y<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<O3z<<setw(3)<<" "\n;
   
    file<<setw(3)<<"O4"<<setw(3)<< " "\
    <<fixed<<setprecision(3)<<O4x<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<O4y<<setw(3)<<" "\
    <<fixed<<setprecision(3)<<O4z<<setw(3)<<" "\n;
    file << "3\n" << endl;
    
    file.close();
    
    cout<<"program selesai";
    
    return 0;
  }


float densitas;          /* densitas ini memiliki satuan g cm^-3
                            dan ini harus diinput dari user */
// converter dari nilai cm^-3 ke A^3
float cm3_to_A3 = 1.0E-24;  
float numb_mol;
float Na = 6.022E23;            // bilangan avogadro    
float Mr_SiO2 = 101,96;         // massa relatif dari SiO2 
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


