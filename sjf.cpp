#include <iostream>
#include "ordenarPro.cpp"

using namespace std;

void sjf(int *y, int *s){
    
    int n = 3;

    int espera[n]; //vetor que armazena o valor de espera de cada processo
    int posicao = 0,tempoRes = 0;
    float mediaEspera = 0, somaEspera = 0;
    int x=18;
   
    //x = soma do valor s[] de todos + (primero y[0]).
   
    posicao = y[0];
    //tempoRes = s[];
    
    int d=0;

    for(int u=0; u<x; u++)//anda com a posicao 
    {
        for(int i=0; i<n; i++)//verificca se tem que inciar a verificao acada vez que a posicao anda
        {
            if(posicao == y[i])
            {   
                for(int j=0; j<i+1; j++)//comparar os valores de s dos processos na fila de espera
                {
                    if(s[i] < s[j])
                    {
                        d = i;
                    }
                }
            }
        }

       s[d]--;
        posicao++;
    }

    

    /*
    //Imprimi vetor
     for(int i=0; i<n; i++)
     {
         cout <<espera[i]<<endl;
     }
     */
}