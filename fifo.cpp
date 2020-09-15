#include <iostream>

#include "leitura.cpp"

using namespace std;


int main()
{
    int p[3];
    int y[3];
    int s[3];

    fifo(p,y,s);

    return 0;
}
        
void fifo(int *p, int *y, int *s){
    
    int start;//onde comeca a contagem
    int aux, somaEspera = 0;
    
    int T = 3;

    //Busca o menr valor do vetor 
    start = y[0];
    for(int i=0; i<T; i++)
    {
        if(y[i] < start)
        {
            start = y[i];
        }
    }

     
}