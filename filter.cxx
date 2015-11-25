#include <iostream>
#include <fstream> 

using namespace std;

double* read(int&);
void filter(double*, const int);
void print(double*, const int);


int main(){
 int N;
 double* f;
 f= read(N);

 int iterations=1; 
 for(int i=0; i<iterations; i++)
 filter(f, N);

 print(f, N);

 delete[] f; //hier geben wir den Speicher wieder frei
 return 0;
}

double* read(int& N){
 //liest in noisy.dat
 ifstream lines("noisy.txt"); 

 double temp;
 N=0;
 while(lines>>temp)
    N++;
 lines.close();


 ifstream noisy("noisy.txt");

 double* f=new double[N];

 for(int i=0; i<N; i++)
 noisy>>f[i];

 noisy.close();

 return f;
 }

void filter(double* f, const int N){
 double f0=f[N-1];
 double flast=f[0];
 for (int i=0; i<(N-1); i++){ 
 double ftemp=f[i];
 f[i]=(f0+f[i]+f[i+1])/3;
 f0=ftemp;
 }

 f[N-1]=(f0+f[N-1]+flast)/3;

}

void print(double* f, const int N){
 ofstream filtered("filtered.txt");
 for(int i=0; i<N; i++)
 filtered<<f[i]<<endl;

 filtered.close();
}