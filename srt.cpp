#include <iostream>
//#include "ordenarPro.cpp"

using namespace std;

void srt(int n, int *y, int *s){
    
    //const int n = 4;

    int d=0;//Posição do decrementador
    int menorS = 0;//Menor valor de s[]
    int qtd = 0;//Quantidade que deve ser comparada -- Permite fazer as operações apenas dos processo que entraram. 

    int posicao=0;//Posição do processo
    int tam=0;//Tamanho do processo
    
    int wolf[n];
    
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
        wolf[p] = y[p]; //
        
        copiaS[p]= s[p];
        auxS[p] = s[p];
        
        espera[p] = 0;
        resposta[p] = 0;
    }
    
    //Cálculo do tamanho do processo
    for(int p=0; p<n; p++){
        tam += copiaS[p];
    }

    posicao = wolf[0];//Determina onde o processo comeca
    
    for(int u=0; u<tam; u++)//movimenta a variável da posição 
    {       
            //Permite que apenas os processos que entraram execute
            if(posicao <= wolf[n-1]){//Só executa nas entradas de processo
                qtd=-1;
                for(int k=0; k<n; k++){
                    if(posicao >= wolf[k])
                    {
                        qtd++;//contador do número de execuções da variável i      
                    }
                }
            }

        for(int i=0; i<=qtd; i++)//verificca se tem que inciar a verificao acada vez que a posicao anda
        {
            menorS = copiaS[d];//Reseta o menorS *
              
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
                            //if(posição == y[i]) //y={3,5,5,6}
                            {   menorS = copiaS[i];
                                d = i;// salva a posição quando tem q fazer a troca
                                                
                            }
                        }
                    }
                }
        }

        //registra os valores de s[] antes de andar a posição
        for(int i = 0; i<n; i++)
        {
                auxS[i] = copiaS[i];   
        }
        
        //cout <<d <<endl;
        copiaS[d]--;
        ++posicao;
      
    
    //vetor dos valores do tempo de espera
        for(int i = 0; i<=qtd; i++)
        {
            if(auxS[i] == copiaS[i] and copiaS[i] > 0)
            {
                ++espera[i];
            }
        }

   //vetor dos valores do tempo de resposta
        for(int i = 0; i<=qtd; i++)
        {
            if(auxS[i] == copiaS[i] and s[i] == copiaS[i])
            {
                ++resposta[i];
            }
        }
    }
    

    //Calculo da media
     for(int i=0; i<n; i++)
     {
        somaEspera += espera[i];

        somaResposta += resposta[i];
     }

    mediaEspera = somaEspera/n;
    mediaResposta = somaResposta/n;
    
    /*
    //Imprimi vetor
    cout <<Espera <<"\t " <<Resposta <<endl;
    for(int i=0; i<n; i++)
    {
        cout <<espera[i] <<"\t " <<resposta[i] <<endl;
    }
     */
     cout <<"SRT_: Media Espera: " <<mediaEspera <<endl;
    
     cout <<"SRT_: Media Resposta: " <<mediaResposta;
    
}