#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <string.h>


int p=-1, i=-1, s=-1;

using namespace std;

void quebrarLinha(string linha);//Quebra a linha do arquivo em interos
void entradaArquivo(string nomeTXT);

int main(){
    
    setlocale(LC_ALL,NULL);
   
    string nomeTXT="entrada.txt";

    //Fazer o cin e cout bunitin.
    
    entradaArquivo(nomeTXT);
        
    return 0;

}

void entradaArquivo(string nomeTXT){

    ifstream arquivo;
    string linha;
    int count=0;

    //Abri o arquivo.
    arquivo.open(nomeTXT, ios::out );
        
        //Verifica se o arquivo foi aberto corretamente
        if(arquivo.is_open()){
            
            //Rodar enquanto todo o arquivo não for lido(eof).
            while(!arquivo.eof()) {
                
                //Quebra cada linha do arq e armazena numa string.
                getline(arquivo,linha);
                // quebrarLinha();
                cout <<"line: " <<linha<<endl;
                cout <<"cont: " <<count<<endl<<endl;
                
                count++;

            }
        }
        else
        {
            cout <<"\nO arquivo não foi aberto corretamente.\n";
        }

    
}

//nao pronto
void quebrarLinha(string linha)
{
   char *pch, *str;
    
    pch = strtok(str," ");
}