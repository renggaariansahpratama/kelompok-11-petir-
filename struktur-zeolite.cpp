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

    Six = - Alx;
    Siy = Aly;
    Siz = Alz;

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


%%writefile ep-SiO2.cpp

#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

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


int main(){
    
    rcut = 3 * sigma;
    rcut2 = pow(rcut,2);

    cout << "program menghitung energi potensial dari SiO2" << endl;
    cout << "Masukkan nilai densitas dari SiO2 (eg. 1.0): ";
    cin >> densitas;

    numb_mol = densitas * (Na / Mr_SiO2) * cm3_to_A3;
    cout << "Masukkan panjang sel simulasi (eg.5):";
    cin >> numb_lat;
    N = (pow(numb_lat,3)) * 3;
    volum = (float)N / numb_mol;

    // panjang sel simulasi secara perhitungan
    lx = pow(volum,(1.0/3.0));
    ly = lx;
    lz = lx;
    if(lx < (2*rcut)){
        cout << "sorry pak, sel simulasi kamu terlalu besar";
        exit(0);
    } else{
        cout << "panjang sel simulasi baru: " << lx << endl;
    }
    lat = lx / (float)numb_lat;
    
    // deklarasi molekul SiO2
    float Six[N], Siy[N], Siz[N];
    float O1x[N], O1y[N], O1z[N];
    float O2x[N], O2y[N], O2z[N];

    /* O    O
        \  /
         Si
      molekul SiO2 itu bentuk 
    */

    float rB_Six = 0.0;
    float rB_Siy = 0.0;
    float rB_Siz = 0.0;

    float rB_O1x = sin((104.52/2.0)*pi/180.0) * 1.0;
    float rB_O1y = 0.0;
    float rB_O1z = cos((104.52/2.0)*pi/180.0) * 1.0;

    float rB_O2x = - rB_O1x;
    float rB_O2y = rB_O1y;
    float rB_O2z = rB_O1z;

    int counter = 0;
    for(int i = 0; i < numb_lat; i++){ //x
        for(int j = 0; j < numb_lat; j++){ //y
            for(int k = 0; k < numb_lat; k++){ //z
                
                Six[counter] = rB_Six + (i*lat);
                Siy[counter] = rB_Siy + (j*lat);
                Siz[counter] = rB_Siz + (k*lat);

                O1x[counter] = Six[counter] + rB_O1x;
                O1y[counter] = Siy[counter] + rB_O1y;
                O1z[counter] = Siz[counter] + rB_O1z;

                O2x[counter] = Six[counter] + rB_O2x;
                O2y[counter] = Siy[counter] + rB_O2y;Ep = 0.0;
    for(int a = 0; a < (N-1); a++){
        for(int b = (0+1); b < N; b++){
            dx = Six[a] - Six[b];
            dy = Siy[a] - Siy[b];
            dz = Siz[a] - Siz[b];

            dx = dx - round(dx/lx) * lx;
            dy = dy - round(dy/ly) * ly;
            dz = dz - round(dz/lz) * lz;

            rij = pow(dx,2) + pow(dy,2) + pow(dz,2);
            if(rij < rcut2){
                rij6 = pow(rij,3);
                rij12 = pow(rij6,2);
                Ep = (A12/rij12) - (B6/rij6);
                Ep_LJ = (A12/rij12) - (B6/rij6);
                Ep += Ep_LJ;
            }

        }
    }

    cout << "Energi potensial dari molekul SiO2 ruah: " \
         << Ep/(float)N << "kj/mol";

    // hasil iterasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("SiO2-hitung_ep.xyz");
    file << N << "\n" << endl;

    int Nw = N/3;

    // iterasi dalam output array 
    for(int m = 0; m < Nw; m++){
        file << setw(3) << "Si" << setw(3) << " " \
             << fixed << setprecision(3) << Six[m] << setw(3) << " " \
             << fixed << setprecision(3) << Siy[m] << setw(3) << " " \
             << fixed << setprecision(3) << Siz[m] << "\n";

        file << setw(3) << "Ol" << setw(3) << " " \
             << fixed << setprecision(3) << O1x[m] << setw(3) << " " \
             << fixed << setprecision(3) << O1y[m] << setw(3) << " " \
             << fixed << setprecision(3) << O1z[m] << "\n";

        file << setw(3) << "O2" << setw(3) << " " \
             << fixed << setprecision(3) << O2x[m] << setw(3) << " " \
             << fixed << setprecision(3) << O2y[m] << setw(3) << " " \
             << fixed << setprecision(3) << O2z[m] << "\n";
    }

    file.close();

    return 0;
}
                Cl2z[counter] = Mgz[counter] + rB_Cl2z;

                counter += 1;
            }
        }
    }
    // main hitung energi potensial
    A12 = 4.0 * epsilon * pow(sigma,12);
    B6 = 4.0 * epsilon * pow(sigma, 6);

    Ep = 0.0;
    for(int a = 0; a < (N-1); a++){
        for(int b = (0+1); b < N; b++){
            dx = Six[a] - SiMgx[b];
            dy = Siy[a] - Siy[b];
            dz = Siz[a] - Siz[b];

            dx = dx - round(dx/lx) * lx;
            dy = dy - round(dy/ly) * ly;
            dz = dz - round(dz/lz) * lz;

            rij = pow(dx,2) + pow(dy,2) + pow(dz,2);
            if(rij < rcut2){
                rij6 = pow(rij,3);
                rij12 = pow(rij6,2);
                Ep = (A12/rij12) - (B6/rij6);
                Ep_LJ = (A12/rij12) - (B6/rij6);
                Ep += Ep_LJ;
            }

        }
    }

    cout << "Energi potensial dari molekul SiO2 ruah: " \
         << Ep/(float)N << "kj/mol";

    // hasil iterasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("SiO2-hitung_ep.xyz");
    file << N << "\n" << endl;

    int Nw = N/3;

    // iterasi dalam output array 
    for(int m = 0; m < Nw; m++){
        file << setw(3) << "Mg" << setw(3) << " " \
             << fixed << setprecision(3) << Six[m] << setw(3) << " " \
             << fixed << setprecision(3) << Siy[m] << setw(3) << " " \
             << fixed << setprecision(3) << Siz[m] << "\n";

        file << setw(3) << "Cl" << setw(3) << " " \
             << fixed << setprecision(3) << O1x[m] << setw(3) << " " \
             << fixed << setprecision(3) << O1y[m] << setw(3) << " " \
             << fixed << setprecision(3) << O1z[m] << "\n";

        file << setw(3) << "Cl" << setw(3) << " " \
             << fixed << setprecision(3) << O2x[m] << setw(3) << " " \
             << fixed << setprecision(3) << O2y[m] << setw(3) << " " \
             << fixed << setprecision(3) << O2z[m] << "\n";
    }

    file.close();

    return 0;
}

