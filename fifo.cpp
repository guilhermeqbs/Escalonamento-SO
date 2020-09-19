#include <iostream>
#include "ordenarPro.cpp"

using namespace std;

void fifo( int *y, int *s)
{   
    int T = 3;

    int espera[T]; //vetor que armazena o valor de espera de cada processo
    int  posicao = 0;
    float mediaEspera = 0, somaEspera = 0;
  
    posicao = y[0];// set a posicaao no inico do primeiro processo

    for(int i=0; i<T; i++)
    {
        espera[i] =  posicao - y[i];
        posicao += s[i];
    }
    /*
    //Imprimi vetor
     for(int i=0; i<T; i++)
     {
         cout <<espera[i]<<endl;
     }
    */
    //calculo da media de espera.
    for(int i=0; i<T; i++)
    {
        somaEspera += espera[i];
    }
    mediaEspera = somaEspera/T;

    cout <<"Media de espera: " <<mediaEspera <<endl;
}

