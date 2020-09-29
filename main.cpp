#include <iostream>
//#include "fifo.cpp"
#include "srt.cpp"

using namespace std;

int main()
{   
    int n = 3;

    int y [n] = {3,14,20};
    int s[n] = {33, 54, 42};

    //int p[3]; 0,1,2,3
    //int y[n] = {3,5,5,6};
    //int s[n] = {5,6,2,4};

    //fifo(n, y,s);
    
    srt(n,y,s);

    return 0;
}