%%writefile struktur-zeolite.cpp

#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"


using namespace std;
int main (){
    // deklarasi variabel
    float pi = 3.14;

// deklarasi struktur-zeolit
float Alx, Aly, Alz;
float Six, Siy, Siz;
float O1x[125], O1y[125], O1z[125]
float O2x[125], O2y[125], O2z[125]
float O3x[125], O3y[125], O3z[125]
float O4x[125], O4y[125], O4z[125]

 // masukkan nilai untuk setiap variabel [AlO4].[SiO4]
 Alx = Aly = Alz = 0.0;
    
    Alx = sin(88.75*pi/180) * 177.5;
    Aly = 0.0;
    Alz = cos(88.75*pi/180) * 177.5;

    Six = - Cl1x;
    Siy = Cl1y;
    Siz = Cl1z;

    // memasukkan nilai tersebut ke dalam file
    ofstream file;
    file.open("struktur-zeolite.xyz");
    file << "3\n" << endl;
