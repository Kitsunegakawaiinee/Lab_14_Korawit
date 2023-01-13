#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void updateImage(bool AR [][M], int brush, int X, int Y)
{
    bool a;
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 70;j++)
        {
            a = sqrt(pow((i-X),2) + pow((j-Y),2)) <= brush-1;
            if (a) AR[i][j] = 1;
        }
    }
}

void showImage(const bool AR [][M])
{
    cout << "------------------------------------------------------------------------\n";

    for (int i = 0; i < 30; i++)
    {
        cout << "|";

        for(int j = 0; j< 70; j++)
        {
            if(AR[i][j] == 0) cout << " ";
            else cout << "*";
        }

        cout << "|" <<endl;
    }

    cout << "------------------------------------------------------------------------\n";
}