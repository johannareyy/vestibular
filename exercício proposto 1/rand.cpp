#include <iostream>
#include <fstream>
#include <time.h>
#define TAM 826

using namespace std;

struct candidato{
    int num_inscricao, idade, pontuacao, cod_do_curso_pretendido; //pontuacao 0 a 5000
};



int main(){
    srand(time(NULL));
    ofstream arquivo;

    struct candidato candid[TAM];



    arquivo.open ("dados.txt");



    for(unsigned int i=0; i<TAM; i++){            //gera os dados randomicamente
        candid[i].num_inscricao = rand()%9999999+1; 
        if(candid[i].num_inscricao < 0){
            arquivo.close();
            cout << "programa finalizado";
            break;
        }
        candid[i].idade = rand()%50+15; 
        candid[i].pontuacao = rand()%5000;
        if(candid[i].pontuacao < 0 or candid[i].pontuacao > 5000){
            cout << "nota invalida";
            break;
        }
        candid[i].cod_do_curso_pretendido = rand()%4+1;
        arquivo << candid[i].num_inscricao << "\n" << candid[i].idade << "\n" << candid[i].pontuacao << "\n" << candid[i].cod_do_curso_pretendido << "\n"; 
    }

    arquivo.close();

    return 0;
}