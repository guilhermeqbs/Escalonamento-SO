#include <iostream>
//#include "ordenarPro.cpp"
#include "fifo.cpp"
#include "prio.cpp"
#include "srt.cpp"


using namespace std;

int main()
{   
    const int n = 3;
    
    int p[n] = {2,1,0};
    int y[n] = {3,14,20};
    int s[n] = {33,54,42};
    

    /*
    //srt
    int y[n] = {3,5,5,6};
    int s[n] = {5,6,2,2};
    */
   
    /*
    //prio
    int p[n] ={3,4,0,1,2};
    int y[n] ={3,5,7,7,14};
    int s[n] ={6,6,2,4,2};
    */
    //fifo(n, y,s);
    
    //srt(n,y,s);
    
    prio(n,p,y,s);

    return 0;
}