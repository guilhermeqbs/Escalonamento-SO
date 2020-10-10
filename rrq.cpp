#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void rrq(int n, int *y, int *s)
{   
    int qtd = 0;//Quantidade que deve ser comparada -- Permite fazer as operações apenas dos processo que entraram. 
    int quantum = 5;

    //Quantidade em que se deve andar pela execucao dos processos,
    int andador = quantum;//podendo assumir valor inferior quando o processo resta valor menor que o quantum.
    
    int posicao=0;//Posição do processo
    float tam=0;//Tamanho do processo
    
    //estas variavei sao usadas para nao alguns lacos executarem apenas uma vez depois de atendida certa condicao
    int x=-1;
    int a=-1;

    int fila[n];//fila que identifica qual é o proximo processo a ser executado.

    int resposta[n];//Vetor que armazena o valor de resposta de cada posição
    int espera[n]; //Vetor que armazena o valor de espera de cada processo

    int sub[n];//subtrai valor de espera e resposta, quando necessario. 
    
    int copiaS[n];//Copia do vetor s[]
    int auxS[n];//Copia do vetor s[]

    //Respostas
    float somaEspera=0;
    float mediaEspera; 
    float somaResposta=0;
    float mediaResposta;
    
    int indice = 0;//indice do processo atual em execucao
    
    //Copia vetores
    for(int i=0; i<n; i++)
    {   
        copiaS[i]= s[i];
        auxS[i] = s[i];

        fila[i] = 0;
        sub[i] = y[i] - y[0];
        espera[i] = 0;
        resposta[i] = 0;
    }

    //Cálculo do tamanho de toda a execucao de processos
    for(int i=0; i<n; i++){
        tam += s[i];
    }
    tam = ceil(tam/quantum);
    
    fila[0]=1;//set da fila para o primeiro processo

    posicao = y[0];//Determina onde o processo começa

    for(int u=0; u<tam; u++)
    {
        for(int i=0; i<n; i++)
        {
            if(posicao >= y[i])
            {
                qtd = i;//Contador do número de execuções da variável i      
            }
        }

        if( u!=0){
        a=-1;//depopis de o processo encontrado, permite finalizar o for.
        for(int i=0; i<=qtd and a==-1; i++)
        {   

            if(fila[i] == 1)
            {
                //zera toda a fila
                for(int j=0;j<=qtd;j++)
                {
                    fila[j]=0;
                }

                x=-1;//depopis de o processo encontrado, permite finalizar o for.
                for(int k=1, j=i+1; k<=qtd-i or x==-1; j++, k++)//pular pro proximo processo a ser executado no vetor fila.
                {   
                    if(i == qtd)//volta a inicio do vetor s[] quando necessario, afim de buscar o processo a ser executado.
                    {
                        j=0;
                        k=-1;
                        qtd++;
                    }

                    if(s[j]>0)//busca o proximo processo a ser executado
                    {   
                        //pula proximo
                        indice = j;
                        fila[j] = 1;
                        a = j;
                        break;//depois de encontrado o processo a ser executado, finaliza a proucura com o break e as variaveis 'a' e 'x'.
                    }
                    //quando o j ta no ultimo, deve se voltar ao incio da verificacao.
                    if( ((k == qtd-i) and s[j] < 1))
                    {
                        //pula pro inicio 
                        j=-1;
                        k=-2;
                        qtd+=i;
                    } 
                }
            }
        }
        }

        //identidica o valor que se deve andar na execucao
        if(s[indice] >= quantum)
        {
            andador = quantum;           
        }
        else//caso o processso tenha valor menor que o quantum
        {
            andador = s[indice];
        }
        
        //registra os valores de s[] antes de andar a posição
        for(int i = 0; i<n; i++)
        {
            auxS[i] = s[i];   
        }

        s[indice]-=andador;//Decrementa o valor de s[] do processo em execução.
        posicao+=andador;//Incrementa o valor da posição

        //Vetor dos valores do tempo de espera
        for(int i = 0; i<n; i++)
        {
            if(auxS[i] == s[i] and s[i] > 0)
            {
                espera[i] += andador;
            }
        }

        //Vetor dos valores do tempo de resposta
        for(int i = 0; i<n; i++)
        {
            if(auxS[i] == s[i] and copiaS[i] == s[i])
            {
                resposta[i] += andador;
            }
        }
    }

    //retira valor em excesso da espera e resposta.
    for(int i=0; i<n; i++)
    {
        espera[i] -= sub[i];
        resposta[i] -= sub[i];
    }

    
    //Cálculo da média
    for(int i=0; i<n; i++)
    {
        somaEspera += espera[i];

        somaResposta += resposta[i];
    }

    mediaEspera = somaEspera/n;
    mediaResposta = somaResposta/n;
    
     
    saidaArquivo("RRQ5 ",mediaEspera,mediaResposta);

}


