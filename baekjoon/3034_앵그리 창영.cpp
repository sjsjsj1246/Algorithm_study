#include <iostream>
using namespace std;

int main()
{
    int n, w, h;
    cin >> n >> w >> h;
    double dia = w*w+h*h;
    double input;
    for(int i=0;i<n;i++)
    {
        cin >> input;
        if(input <= w || input <= h || input*input <= dia)
            cout << "DA\n";
        else 
            cout << "NE\n";
    }
}