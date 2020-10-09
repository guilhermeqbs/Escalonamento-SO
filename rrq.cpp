#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void rrq(int e, int *y, int *s)
{   
    const int n = 4;
    int qtd = 0;//Quantidade que deve ser comparada -- Permite fazer as operações apenas dos processo que entraram. 
    int quantum = 3;
    int andador = quantum;
    
    int sub[n];
    int posicao=0;//Posição do processo
    float tam=0;//Tamanho do processo
    int x=-1;
    int a=-1;

    int fila[n];

    int resposta[n];//Vetor que armazena o valor de resposta de cada posição
    int espera[n]; //Vetor que armazena o valor de espera de cada processo
    
    int copiaS[n];//Copia do vetor s[]
    int auxS[n];//Copia do vetor s[]

    //Respostas
    float somaEspera=0;
    float mediaEspera; 
    float somaResposta=0;
    float mediaResposta;
    int indice = 0;
    
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

    //Cálculo do tamanho do processo
    for(int i=0; i<n; i++){
        tam += s[i];
    }
    tam = ceil(tam/quantum);
    
    fila[0]=1;

    posicao = y[0];//Determina onde o processo começa

    for(int u=0; u<=tam; u++)
    {
        for(int i=0; i<n; i++)
        {
            if(posicao >= y[i])
            {
                qtd = i;//Contador do número de execuções da variável i      
            }
        }

        //indice = menorEmFila(fila,qtd);

        a=-1;

        for(int i=0; i<=qtd and a==-1; i++)
        {   

            if(fila[i] == 1)
            {
                //pula
                for(int j=0;j<=qtd;j++)
                {
                    fila[j]=0;
                }

                x=-1;

                for(int k=1, j=i+1; k<=qtd-i or x==-1; j++, k++)//pular pro proximo
                {   
                    if(i == qtd)
                    {
                        j=0;
                        k=-1;
                        qtd++;
                    }

                    if(copiaS[j]>0)
                    {   
                        //pula proximo
                        indice = j;
                        fila[j] = 1;
                        x = j;
                        a = j;
                        break;
                    }
                    
                //i =       2      
                    //s = 0 2 2 0 0

                        //quando o j ta no ultimo
                    if( ((k == qtd-i) and copiaS[j] < 1)  )
                    {
                        //pula pro inicio d
                        j=-1;
                        k=-2;
                        qtd+=i;
                    } 
                }
                
            }
        }

        if(copiaS[indice] >= quantum)
        {
            andador = quantum;           
        }
        else
        {
            andador = copiaS[indice];
        }
        
        //registra os valores de s[] antes de andar a posição
        for(int i = 0; i<n; i++)
        {
            auxS[i] = copiaS[i];   
        }

        copiaS[indice]-=andador;//Decrementa o valor de s[] do processo em execução.
        posicao+=andador;//Incrementa o valor da posição

        //Vetor dos valores do tempo de espera
        for(int i = 0; i<n; i++)
        {
            if(auxS[i] == copiaS[i] and copiaS[i] > 0)
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
    
    
    //Imprime vetor
    cout <<"Espera" <<"\t " <<"Resposta" <<endl;
    for(int i=0; i<n; i++)
    {
        cout <<espera[i] <<"\t " <<resposta[i] <<endl;
    }
     
    cout <<"RRQ5: Media Espera: " <<fixed <<setprecision(2) <<mediaEspera <<endl;
    
    cout <<"RRQ5: Media Resposta: " <<mediaResposta;
    
}


