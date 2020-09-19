#include <iostream>
#include"quickSort.cpp"

//Coloca os processos na ordem de chegada
void ordenacaoProcessos(int *a, int *b){
    
    /*//Busca o menr valor do vetor 
    start = y[0];
    for(int i=0; i<n; i++)
    {
        if(y[i] < start)
        {
            start = y[i];
        }
    }*/

    int n = 3;

    long long int cont=0 ,mov = 0;

    
    //ordernar vetor obtendo a fila de exucacao na ordem correta
    quickSort(a,0,n,cont,mov);//(vetor,inicio,tamanho,cont,mov)
    
    /*
    //Imprimi vetor
     for(int i=0; i<n; i++)
     {
         cout <<y[i]<<endl;
     }
    */
    //*Falta colocar o vetor 's' em ordem.
}