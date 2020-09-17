#include <iostream>
#include <fstream>
#define TAM 826

using namespace std;

struct candidato{
    int num_inscricao, idade, pontuacao, cod_do_curso_pretendido; //pontuacao 0 a 5000
};



int main(){

    ofstream arquivo;

    int quant = 827;

    struct candidato candid[TAM];



    arquivo.open ("dados.txt");



    for(unsigned int i=0; i<TAM; i++){            //lê numero de inscricao > idade > pontuacao > curso, se num negativo fecha, se pontuacao fora fecha
        cin >> candid[i].num_inscricao; 
        if(candid[i].num_inscricao < 0){
            arquivo.close();
            cout << "programa finalizado";
            break;
        }
        cin >> candid[i].idade >> candid[i].pontuacao;
        if(candid[i].pontuacao < 0 or candid[i].pontuacao > 5000){
            cout << "nota invalida";
            break;
        }
        cin >> candid[i].cod_do_curso_pretendido;
        arquivo << candid[i].num_inscricao << "\n" << candid[i].idade << "\n" << candid[i].pontuacao << "\n" << candid[i].cod_do_curso_pretendido << "\n"; 
    }

    arquivo.close();

    return 0;
}