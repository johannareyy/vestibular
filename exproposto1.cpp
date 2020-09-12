#include <iostream>

using namespace std;

struct candidato{
    int num_inscricao, idade, pontuacao, cod_do_curso_pretendido; //pontuacao 0 a 5000
};

/*struct curso{
    int vaga[40];
}*/

int main(){


    struct candidato candid[2];

    for(unsigned int i=0; i<2; i++){
        cin >> candid[i].num_inscricao;
        if(candid[i].num_inscricao < 0){
            cout << "programa finalizado";
            break;
        }
        cin >> candid[i].idade;
        cin >> candid[i].pontuacao;
        if(candid[i].pontuacao < 0 or candid[i].pontuacao > 5000){
            cout << "nota invalida";
        }
        cin >> candid[i].cod_do_curso_pretendido;
    }

    return 0;
}