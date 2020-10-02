#include <iostream>

using namespace std;

int menorNum(int *v, int n);

void srt(int n, int *y, int *s){

    int d=0;//Posição do decrementador
    int menorS = 0;//Menor valor de s[]
    int qtd = 0;//Quantidade que deve ser comparada -- Permite fazer as operações apenas dos processo que entraram. 

    int posicao=0;//Posição do processo
    int tam=0;//Tamanho do processo
    
    int copiaS[n];//Copia do vetor s[]
    int auxS[n];//Copia do vetor s[]
    

    int resposta[n];//Vetor que armazena o valor de resposta de cada posição
    int espera[n]; //Vetor que armazena o valor de espera de cada processo

    //Respostas
    float somaEspera=0;
    float mediaEspera; 
    float somaResposta=0;
    float mediaResposta; 
    
    //Copia vetores
    for(int p=0; p<n; p++)
    {   
        copiaS[p]= s[p];
        auxS[p] = s[p];
       
        
        espera[p] = 0;
        resposta[p] = 0;
    }
    
    //Cálculo do tamanho do processo
    for(int p=0; p<n; p++){
        tam += s[p];
    }

    posicao = y[0];//Determina onde o processo começa

    for(int i=0; i<tam; i++)
    {
        //Permite que apenas os processos que entraram execute
            if(posicao <= y[n-1])//Só executa nas entradas de processo
            {
                qtd=-1;

                for(int k=0; k<n; k++){
                    
                    if(posicao >= y[k])
                    {
                        qtd++;//Contador do número de execuções da variável i      
                    }
                }
            }
    }
}

int menorNum(int *v, int qtd)
{   
    int menor=99999999;

    for(int i=0;i<=qtd;i++)
    {  
        if (v[i] < menor and v[i] > 0)
        {
            menor = v[i];
        }
    }
    //Subtrair o s[d] aqui??
    return menor;
}