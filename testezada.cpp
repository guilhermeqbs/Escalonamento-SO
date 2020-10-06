#include <iostream>

using namespace std;

int main()
{   
    int n = 4;
    int v[n] = {1,3,1,0};
    int menor=99999999;

    for(int i=0;i<n;i++)
    {  
        if (v[i] < menor and v[i] > 0)
        {
            menor = v[i];
        }
    }
    
    cout <<menor;
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