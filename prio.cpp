#include <iostream>
#include <iomanip>
using namespace std;

int menorNumP(int *p, int *s,int qtd);

void prio(int n, int *p, int *y, int *s)
{
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
    for(int a=0; a<n; a++)
    {   
        copiaS[a]= s[a];
        auxS[a] = s[a];
       
        espera[a] = 0;
        resposta[a] = 0;
    }
    
    //Cálculo do tamanho do processo
    for(int a=0; a<n; a++){
        tam += s[a];
    }

    posicao = y[0];//Determina onde o processo começa

    for(int u=0; u<tam; u++)
    {
        for(int k=0; k<n; k++){
            
            if(posicao >= y[k])
            {
                qtd = k;//Contador do número de execuções da variável i      
            }
        }
        
        //registra os valores de s[] antes de andar a posição
        for(int i = 0; i<n; i++)
        {
            auxS[i] = s[i];   
        }
        
        s[menorNumP(p,s,qtd)]--;//Decrementa o valor de s[] do processo em execução.
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
    
    
    //Imprime vetor
    cout <<"Espera" <<"\t " <<"Resposta" <<endl;
    for(int i=0; i<n; i++)
    {
        cout <<espera[i] <<"\t " <<resposta[i] <<endl;
    }
     
     
    cout <<"PRIO: Media Espera: " <<fixed <<setprecision(2) <<mediaEspera <<endl;
    
    cout <<"PRIO: Media Resposta: " <<mediaResposta;
}

int menorNumP(int *p, int *s,int qtd)//retorna o indice do menor numero do vetor
{   
    int menor=99999999;
    int indice;

    for(int i=0;i<=qtd;i++)
    {  
        if (p[i] < menor and s[i] > 0)
        {
            menor = p[i];
            indice = i;
        }
    }
    return indice;
}