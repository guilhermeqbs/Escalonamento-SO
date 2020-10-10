#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void saidaArquivo(string str, float mediaEspera, float mediaResposta){

    ofstream saida;

    saida.open("saida.txt",fstream::app);

    saida <<str <<fixed <<setprecision(2)<<mediaEspera <<" "<<mediaResposta <<endl;

    saida.close();
}