#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <string.h>


int p=-1, i=-1, s=-1;

using namespace std;

void entradaArquivo(string nomeTXT);
void quebrarLinha(string linha);//Quebra a linha do arquivo em interos
char *convercaoStringParaChar(string linha);

int main(){
    
    setlocale(LC_ALL,NULL);
   
    string nomeTXT = "entrada.txt";

    //Fazer o cin e cout bunitin.
    
    entradaArquivo(nomeTXT);
        
    
    //char *pch, str;
    //string aux="2 31 45";

    //str[100] = aux;

    //pch = strtok(str," ");
       

    

    return 0;

}

void entradaArquivo(string nomeTXT){

    ifstream arquivo;
    string linha;
    int count = 0;

    //Abri o arquivo.
    arquivo.open(nomeTXT, ios::out );
        
        //Verifica se o arquivo foi aberto corretamente
        if(arquivo.is_open()){
            
            //Rodar enquanto todo o arquivo não for lido(eof).
            while(!arquivo.eof()) {
                
                //Quebra cada linha do arq e armazena numa string.
                getline(arquivo,linha);
                quebrarLinha(linha);
                //cout <<"line: " <<linha<<endl;
                //cout <<"cont: " <<count<<endl<<endl;
                
                count++;

            }
        }
        else
        {
            cout <<"\nO arquivo não foi aberto corretamente.\n";
        }

    arquivo.close();
}

//nao pronto
void quebrarLinha(string linha)
{
     char *linhaAux;
     char *fragLinha;//*char para quebrar a linha 

     linhaAux = convercaoStringParaChar(linha);

     

}


char *convercaoStringParaChar(string linha)
{
    //As duas linhas de codigo criam uma copia da string em um *char; 
    //Pois só é possivel conveter atraves do *char.
    char * aux = (char*) calloc(linha.length()+1, sizeof(char*));
    strcpy(aux, linha.c_str());

    return aux;
}