#include <iostream>
#include"quickSort.cpp"

using namespace std;

void fifo( int *y, int *s);
void ordenacaoProcessos(int *y, int *s);

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

//Coloca os processos na ordem de chegada
void ordenacaoProcessos(int *y, int *s){
    
    /*//Busca o menr valor do vetor 
    start = y[0];
    for(int i=0; i<T; i++)
    {
        if(y[i] < start)
        {
            start = y[i];
        }
    }*/

    int T = 3;

    long long int cont=0 ,mov = 0;

    
    //ordernar vetor obtendo a fila de exucacao na ordem correta
    quickSort(y,0,T,cont,mov);//(vetor,inicio,tamanho,cont,mov)
    
    /*
    //Imprimi vetor
     for(int i=0; i<T; i++)
     {
         cout <<y[i]<<endl;
     }
    */
    //*Falta colocar o vetor 's' em ordem.
}

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
    
    //Imprimi vetor
     for(int i=0; i<T; i++)
     {
         cout <<espera[i]<<endl;
     }

    //calculo da media de espera.
    for(int i=0; i<T; i++)
    {
        somaEspera += espera[i];
    }
    mediaEspera = somaEspera/T;

    cout <<"Media de espera: " <<mediaEspera <<endl;
}

