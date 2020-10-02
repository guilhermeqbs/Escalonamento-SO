
using namespace std;

void prio(int n, int *p, int *y, int *s){

    //Respostas
    float somaEspera=0;
    float mediaEspera; 
    float somaResposta=0;
    float mediaResposta;

    int d=0;//Posição do decrementador
    int menorP = 0;//Menor valor de s[]
    int posicao=0;//Posição do processo
    int qtd = 0;//Quantidade que deve ser comparada -- Permite fazer as operações apenas dos processo que entraram. 
    int tam=0;//Tamanho do processo

    int resposta[n];//Vetor que armazena o valor de resposta de cada posição
    int espera[n]; //Vetor que armazena o valor de espera de cada processo
    
    for(int i=0; i<n; i++)
    {
        tam += s[i];
    }
    
    posicao = y[0];//Determina onde o processo começa

    for(int u=0; u<tam; u++)
    {   
         menorP = p[d];//Determina onde o processo começa

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

        for (int i = 0; i<=qtd; i++)
        {
           for(int j=0; j<=i; j++)//comparar os valores de S dos processos na fila de espera
            {   
                //Quando o valor de s[] chegar em zero, verifica se tem algum processo anterior na espera
                if(s[d] < 1)
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
                    //Trava p[i] e anda por todos p[j]. MenorP registra o primeiro menor p[] encontrado
                    if( menorP > p[i] and p[i] < p[j] and s[i] > 0)// Não deixa o s[] ter terminado.
                    {                   
                        {   
                            menorP = p[i];
                            d = i;// salva a posição quando tem q fazer a troca
                                            
                        }
                    }
                }
            }
            
        }

        s[d]--;
        posicao++;
    }
}