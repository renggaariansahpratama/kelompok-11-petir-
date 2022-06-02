
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"


using namespace std;

int main(){
   // deklarasi variabel
   float pi = 3.14;

   // deklarasi molekul air
   float Ox, Oy, Oz;
   float H1x, H1y, H1z;
   float H2x, H2y, H2z;

   //masukkan nilai untuk setiap variabel H2O
   Ox = Oy = Oz = 0.0;

   H1x = sin(52.25*pi/180) * 1.05;
   H1y = 0.0;
   H1z = cos(52.25*pi/180) * 1.05;

   H2x = - H1x;
   H2y = H1y;
   H2z = H1z;

   // memasukkan nilai tersebut ke dalam file
   fstream file;
   file.open("air.hyz");
   file << "3\n" << endl;
   file << setw(3) << "O" << setw(3) <<" " \
   << fixed << setprecision(3) << Ox << setw(3) << " "\
   << fixed << setprecision(3) << Oy << setw(3) << " "\
   << fixed << setprecision(3) << Oz << "\n";

   file << setw(3) << "H" << setw(3) << " " \
   << fixed << setprecision(3) << H1x << setw(3) << " "\
   << fixed << setprecision(3) << H1y << setw(3) << " "\
   << fixed << setprecision(3) << H1z << "\n";

   file << setw(3) << "H" << setw(3) << " " \
   << fixed << setprecision(3) << H2x << setw(3) << " "\
   << fixed << setprecision(3) << H2y << setw(3) << " "\
   << fixed << setprecision(3) << H2z << "\n";

   file.close();

   cout << "program selesai!";

   return 0;
}