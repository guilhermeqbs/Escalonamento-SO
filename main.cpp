//#include "ordenarPro.cpp"
#include "fifo.cpp"
#include "prio.cpp"
#include "srt.cpp"
#include "rrq.cpp"


using namespace std;

int main()
{   
    const int n = 3;
    
    int p[n] = {2,1,0};
    int y[n] = {3,14,20};
    int s[n] = {33,54,42};
    int copiaP[n];
    int copiaY[n];
    int copiaS[n];

   /*
    //rrq
    int y[n] = {3,3,4,4,7};
    int s[n] = {5,3,4,4,3};
    */

    /*
    //srt
    int y[n] = {3,5,5,6};
    int s[n] = {5,6,2,4};  
    */

    /*
    //prio
    int p[n] ={3,4,0,1,2};
    int y[n] ={3,5,7,7,14};
    int s[n] ={6,6,2,4,2};
    */

    for(int i=0; i<n; i++)
    {
        copiaP[i] = p[i];
        copiaY[i] = y[i];
        copiaS[i] = s[i];
    }

    fifo(n,y,s);
    
    for(int i=0; i<n; i++)
    {
        p[i] = copiaP[i];
        y[i] = copiaY[i];
        s[i] = copiaS[i];
    }

    prio(n,p,y,s);

    for(int i=0; i<n; i++)
    {
        p[i] = copiaP[i];
        y[i] = copiaY[i];
        s[i] = copiaS[i];
    }

    srt(n,y,s);

    for(int i=0; i<n; i++)
    {
        p[i] = copiaP[i];
        y[i] = copiaY[i];
        s[i] = copiaS[i];
    }

    rrq(n,y,s);

    return 0;
}