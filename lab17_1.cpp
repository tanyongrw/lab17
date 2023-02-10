#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *a,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if((i+1)%M == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *b,int N,int M){
    for(int i = 0; i < N*M; i++){
        b[i] = (rand()%101)/100.00;
    }
}

void findRowSum(const double *c,double *a,int d,int e){
    int N = 0;
    for (int j = 0; j < e ; j++) a[j] = 0;
    if ( e == 1 ) for (int i = 0;  i < d*e; i++) a[i] = c[i];
    else{
            for (int i = 0; i < d*e; i++){
                a[N] += c[i];
                if((i+1)%e == 0){
                    N++;
                }
            }
        }
}

void findColSum(const double *f,double *g,int h,int t){
    if(h == 1){
        for (int i = 0; i < t; i++){
        g[i] = f[i];
        }
    }
    else{
        for (int j = 0; j < h*t; j++){
            g[j%t] += f[j];
        }
        for (int k = 0; k < t; k++){
            g[k] = 0;
        }
            for (int n = 0; n < h*t; n++){
                g[n%t] += f[n];
            }
    }
}