#include <iostream>
//#include "ordenarPro.cpp"

using namespace std;
int menorNum(int *v, int qtd);
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
    
    for(int u=0; u<tam; u++)//Movimenta a variável da posição 
    {       
            //Permite que apenas os processos que entraram execute
            if(posicao <= y[n-1]){//Só executa nas entradas de processo
                
                qtd=-1;

                for(int k=0; k<n; k++){
                    
                    if(posicao >= y[k])
                    {
                        qtd++;//Contador do número de execuções da variável i      
                    }
                }
            }

        for(int i=0; i<=qtd; i++)//verifica se tem que inciar a verificação acada vez que a posição anda
        {
            menorS = s[d];//Reseta o menorS
              
            for(int j=0; j<=i; j++)//comparar os valores de S dos processos na fila de espera
            {   
                //Quando o valor de s[] chegar em zero, verifica se tem algum processo anterior na espera
                if(menorS < 1)
                {   
                    for (int g = 0; g <qtd; g++)
                    {
                        if(s[g] > 0)
                        {
                            d=g; //salva a posicao do processo que esta em espera
                            break;
                        }
                    }  
                }
                else
                {
                    //Trava s[i] e anda por todos s[j]. MenorS registra o primeiro s[] menor encontrado
                    if( menorS > s[i] and s[i] < s[j] and s[i] > 0)// Não deixa o s[] ser menor do q 0.
                    {                   
                        {   
                            menorS = s[i];
                            d = i;// salva a posição quando tem q fazer a troca
                                            
                        }
                    }
                }
            }
        }

        //registra os valores de s[] antes de andar a posição
        for(int i = 0; i<n; i++)
        {
            auxS[i] = s[i];   
        }
        
        s[d]--;//Decrementa o valor de s[] do processo em execução.
        posicao++;//Incrementa o valor da posição
      
        //Vetor dos valores do tempo de espera
        for(int i = 0; i<=qtd; i++)
        {
            if(auxS[i] == s[i] and s[i] > 0)
            {
                ++espera[i];
            }
        }

        //Vetor dos valores do tempo de resposta
        for(int i = 0; i<=qtd; i++)
        {
            if(auxS[i] == s[i] and copiaS[i] == s[i])
            {
                ++resposta[i];
            }
        }
    }
    
    //Cálculo da média
    for(int i=0; i<n; i++)
    {
        somaEspera += espera[i];

        somaResposta += resposta[i];
    }

    mediaEspera = somaEspera/n;
    mediaResposta = somaResposta/n;
    
    /*
    //Imprime vetor
    cout <<Espera <<"\t " <<Resposta <<endl;
    for(int i=0; i<n; i++)
    {
        cout <<espera[i] <<"\t " <<resposta[i] <<endl;
    }
     */
    cout <<"SRT_: Media Espera: " <<mediaEspera <<endl;
    
    cout <<"SRT_: Media Resposta: " <<mediaResposta;
    
 
    
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

    return menor;
}