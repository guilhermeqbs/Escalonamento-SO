#include <iostream>
//#include "fifo.cpp"
#include "srt.cpp"

using namespace std;

int main()
{
    int y [3] = {3,14,20};
    int s[3] = {33, 54, 42};

    //int p[3]; 0,1,2,3
    //int y[4] = {3,5,5,6};
    //int s[4] = {5,2,6,4};

    //fifo(y,s);
    
    srt(y,s);


    return 0;
}