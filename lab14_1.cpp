#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

double findAmean(const double a[], int N)
{
    double sum =0;
    for (int i = 0; i < N; i++) sum+= a[i];
    return sum/N;
}

double findx(const double a[], int N, double mean, double &sum)
{
    if (N >0) findx(a,N-1,mean,sum);

    sum += pow((a[N]-mean), 2);

    return sum;

}

double StandardDeviation(double mean, int N, const double A[])
{
    double sum = 0;
    return sqrt((findx(A,N-1,mean,sum)/N));
}

double Geo(const double a[], int N)
{
    double sum = a[0];

    for(int i = 1; i < N; i++)
    {
        sum *= a[i];
    }

    return pow(sum, 1.0/N);

}

double Harmonic_Mean(const double a[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum +=(1/a[i]);
    }
    return n/sum;
    
}


void stat(const double a[], int N, double b[])
{
    b[0] = findAmean(a, N);
    b[1] = StandardDeviation(b[0], N, a);
    b[2] = Geo(a, N);
    b[3] = Harmonic_Mean(a,N);

    double Max,Min;
    bool Setmax = false ,Setmin = false; 

    for (int i = 0; i<N; i++)
    {
        if (Setmax == false) Max = a[0];
        if (Setmin == false) Min = a[0];

        for (int j = 0; j < N; j++)
        {
            if (Max < a[j]) Max = a[j];
            if (Min > a[j]) Min = a[j];
        }

    }

    b[4] = Max;
    b[5] = Min;
}
