#include <iostream>
//#include "ordenarPro.cpp"

using namespace std;

void srt(int *y, int *s){
    
    const int n = 4;

    int wolf[n];

    int copiaS[n];

   // int auxS[n];
   // int espera[n]; //vetor que armazena o valor de espera de cada processo

    for(int p=0; p<n; p++)
    {   
        copiaS[p]= s[p];
    }

    for(int p=0; p<n; p++)
    {   
        wolf[p] = y[p];
    }

    

    
    int posicao = 0,tempoRes = 0;
    float mediaEspera = 0, somaEspera = 0;
    //int x=17;
    int x=0;
    //x = soma do valor s[] de todos *+ (primero y[0]).*
    for(int p=0; p<n; p++){
        x += copiaS[p];
    }


    posicao = wolf[0];
    //tempoRes = s[];
    
    int d=0 , menorS = 0, qtd = 0, qtdPassado = 0;

    for(int u=0; u<x; u++)//anda com a posicao 
    {       
            //Subistui o "if(posicao == wolf[i])" la de baixo.
            if(posicao <= wolf[n-1]){//So faz nas entradas de processo
                qtd=-1;
                for(int k=0; k<n; k++){
                    if(posicao >= wolf[k])// n sei se precisa
                    {
                        qtd++;//contar quantas vezes o i deve executar        
                    }
                }
            }

        for(int i=0; i<=qtd; i++)//verificca se tem que inciar a verificao acada vez que a posicao anda
        {
            menorS = copiaS[d];//Reseta o menorS *
            
            //if(posicao == wolf[i]) //y={3,5,5,6}
            //{   
                for(int j=0; j<=i; j++)//comparar os valores de s dos processos na fila de espera
                {   

                    // Temos que voltar para o S[0]=3* e nao pular como abaixo: FEITO!
                    if(menorS < 1)
                    {   
                        for (int g = 0; g <qtd; g++)
                        {
                            if(copiaS[g] > 0)
                            {
                               d=g; 
                               break;//Isso tudo pra o caso de quando o s[] chegar em zero e verificar se tem algum processo na espera
                            }
                        }
                        
                    }
                    else{
                        //Trava s[i] e anda por todos s[j]. MenorS registra o primeiro s[] menor encontrado
                        if( menorS > copiaS[i] and copiaS[i] < copiaS[j] and copiaS[i] > 0)// Nao deixa o s[] ser menor do q 0.
                        {                   
                            //if(posicao == y[i]) //y={3,5,5,6}
                            {   menorS = copiaS[i];
                                d = i;// salva a posicao quando tem q fazer a troca
                                                
                            }
                        }
                    }
                }
           // }
        }
    
        
        
        //cout <<d <<endl;
        copiaS[d]--;
        posicao++;
      
    /*
        //registra os valores de s[] antes de andar a posicao
        for(int i = 0; i<n; i++)
        {
            if(copiaS[i] > 0){
                auxS[i] = copiaS[i];
            }
        }
    
        //para calcular o valor da espera: comparar o s[i] com o s[i] anterior if(s[i]==s[i]-1) espera++
        for(int i = 0; i<n; i++)
        {
            //Calcula a posicao do vetor

            if(auxS[i] == copiaS[i])
            {
                espera[i]++;
            }
        }
    */
    }

    /*
    //Imprimi vetor
     for(int i=0; i<n; i++)
     {
         cout <<espera[i]<<endl;
     }
    */ 
}