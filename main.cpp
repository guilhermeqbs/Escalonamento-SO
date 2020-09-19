#include <iostream>
#include "fifo.cpp"

using namespace std;


int main()
{   
    int y [3] = {3,14,20};
    int s[3] = {33, 54, 42};


    //int p[3];
    //int y[3] = {3,5,6};
    //int s[3] = {5,6,4};

    fifo(y,s);

    return 0;
}