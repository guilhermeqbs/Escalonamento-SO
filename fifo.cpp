#include <iostream>
#include"quickSort.cpp"

using namespace std;

void fifo( int *y, int *s);


int main()
{   
    //int p[3];
    int y[3] = {20,3,14};
    int s[3];

    fifo(y,s);

    return 0;
}
        
void fifo(int *y, int *s){
    
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
    int start;//onde comeca a contagem
    int aux, somaEspera = 0;
    

    //ordernar vetor obtendo a fila de exucacao na ordem correta
    quickSort(y,0,T,cont,mov);//(vetor,inicio,tamanho,cont,mov)

    //Imprimi vetor
     for(int i=0; i<T; i++)
     {
         cout <<y[i]<<endl;
     }

    

}