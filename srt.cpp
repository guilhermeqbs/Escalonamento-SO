#include <iostream>
#include "ordenarPro.cpp"

using namespace std;

void sjf(int *y, int *s){
    
    int n = 4;

    int espera[n]; //vetor que armazena o valor de espera de cada processo
    int posicao = 0,tempoRes = 0;
    float mediaEspera = 0, somaEspera = 0;
    int x=17;
   
    //x = soma do valor s[] de todos *+ (primero y[0]).*
   
    posicao = y[0];
    //tempoRes = s[];
    
    int d=0 , menorS = 0;

    for(int u=0; u<x; u++)//anda com a posicao 
    {
        for(int i=0; i<n; i++)//verificca se tem que inciar a verificao acada vez que a posicao anda
        {
            menorS = 0;//Reseta o menorS *

            if(posicao == y[i]) //y={3,5,5,6}
            {   
                for(int j=0; j<=i; j++)//comparar os valores de s dos processos na fila de espera
                {
                    //Trava s[i] e anda por todos s[j]. MenorS registra o primeiro s[] menor encontrado
                    if( menorS < s[i] and s[i] < s[j] and s[i] > 0 and s[j] > 0)// Nao deixa o s[] ser menor do q 0.
                    {   
                        menorS = s[i];
                        d = i;// salva a posicao quando tem q fazer a troca
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