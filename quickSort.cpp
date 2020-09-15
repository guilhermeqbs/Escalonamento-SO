#include<iostream>
#include<windows.h>
#include<math.h>
#include<locale.h>
#include<chrono>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

using namespace std;
void quickSort(int vetor[], int inicio, int fim, long long int &cont, long long int &mov)
{
    int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = vetor[(inicio + fim) / 2];
	while(i <= j)
	{
	    cont++;
		while(vetor[i] < pivo && i < fim)
		{
			i++;
			cont++;
		}
		while(vetor[j] > pivo && j > inicio){
			j--;
			cont++;
		}
		if(i <= j)
		{
			aux = vetor[i];
			mov++;
            vetor[i] = vetor[j];
            mov++;
			vetor[j] = aux;
			mov++;
			i++;
			j--;
			cont++;
		}
	}
	if(j > inicio)
		quickSort(vetor, inicio, j+1, cont, mov);
		cont++;
	if(i < fim)
		quickSort(vetor, i, fim, cont, mov);
		cont++;


}