#include <iostream>
#include <fstream>
#include <string>
#define TAM 826


using namespace std;

struct curso{
    int vaga[40];
};


int main(){ 
    
    ifstream arquivo;
    string line;
    int i=0, v1=0, v2=0, v3=0, v4=0, c1=0, c2=0, c3=0, c4=0, contador=0;
    int num_inscricao[TAM] = {0}, idade[TAM] = {0}, nota[TAM] = {0}, curso_pretendido[TAM] = {0}, vetorzao[TAM*4], vetorzinho1[TAM*2], vetorzinho2[TAM*2];
    int nota_por_curso_pretendido1[TAM] = {0}, nota_por_curso_pretendido2[TAM] = {0}, nota_por_curso_pretendido3[TAM] = {0}, nota_por_curso_pretendido4[TAM] = {0}, num_inscricao1[TAM] = {0}, num_inscricao2[TAM] = {0}, num_inscricao3[TAM] = {0}, num_inscricao4[TAM] = {0}, idade1[TAM] = {0}, idade2[TAM] = {0}, idade3[TAM] = {0}, idade4[TAM] = {0};
    int curso1[40], curso2[40], curso3[40], curso4[40]; 
    int menor_notac1 = 0, menor_notac2 = 0, menor_notac3 = 0, menor_notac4 = 0, indice_menor_nota;

    arquivo.open ("dados.txt");

    while (getline (arquivo, line)){
        vetorzao[i] = stoi(line);
        if(vetorzao[i]<0){
            return 0;
        }
        //cout << vetorzao[i] << "\n";
        i++;
    }
    
    for(i = 0; i < TAM*4; i++){     //separa todas as informacoes em vetores especificos
        switch(contador){
            case 0: 
                num_inscricao[v1] = vetorzao[i];
                v1++;
                contador++;
                break;
            case 1:
                idade[v2] = vetorzao[i];
                v2++;
                contador++;
                break;
            case 2:
                nota[v3] = vetorzao[i];
                v3++;
                contador++;
                break;
            case 3:
                curso_pretendido[v4] = vetorzao[i];
                v4++;
                contador = 0;
        }
    }

    for(i = 0; i < TAM; i++){               //organizar notas por curso pretendido
        switch(curso_pretendido[i]){
            case 1:
                nota_por_curso_pretendido1[c1] = nota[i];
                num_inscricao1[c1] = num_inscricao[i];
                idade1[c1] = idade[i];
                c1++;
                break;
            case 2:
                nota_por_curso_pretendido2[c2] = nota[i];
                num_inscricao2[c2] = num_inscricao[i];
                idade2[c2] = idade[i];
                c2++;
                break;
            case 3:
                nota_por_curso_pretendido3[c3] = nota[i];
                num_inscricao3[c3] = num_inscricao[i];
                idade3[c3] = idade[i];
                c3++;
                break;
            case 4:
                nota_por_curso_pretendido4[c4] = nota[i];
                num_inscricao4[c4] = num_inscricao[i];
                idade4[c4] = idade[i];
                c4++;
                break;
        }
    }

    for(int x = 0; x < TAM; x++){                   //organizar notas do curso 1 em nota decrescente 
        for(int y = x+1;y < TAM; y++){
            if(nota_por_curso_pretendido1[x] < nota_por_curso_pretendido1[y]){
                nota_por_curso_pretendido1[x] = nota_por_curso_pretendido1[x]+nota_por_curso_pretendido1[y];
                nota_por_curso_pretendido1[y] = nota_por_curso_pretendido1[x]-nota_por_curso_pretendido1[y];
                nota_por_curso_pretendido1[x] = nota_por_curso_pretendido1[x]-nota_por_curso_pretendido1[y];

                num_inscricao1[x] = num_inscricao1[x]+num_inscricao1[y];
                num_inscricao1[y] = num_inscricao1[x]-num_inscricao1[y];
                num_inscricao1[x] = num_inscricao1[x]-num_inscricao1[y];

                idade1[x] = idade1[x]+idade1[y];
                idade1[y] = idade1[x]-idade1[y];
                idade1[x] = idade1[x]-idade1[y];
                
                x=0;
            }else if(nota_por_curso_pretendido1[x] == nota_por_curso_pretendido1[y]){
                if(idade1[x]<idade1[y]){
                    nota_por_curso_pretendido1[x] = nota_por_curso_pretendido1[x]+nota_por_curso_pretendido1[y];
                    nota_por_curso_pretendido1[y] = nota_por_curso_pretendido1[x]-nota_por_curso_pretendido1[y];
                    nota_por_curso_pretendido1[x] = nota_por_curso_pretendido1[x]-nota_por_curso_pretendido1[y];

                    num_inscricao1[x] = num_inscricao1[x]+num_inscricao1[y];
                    num_inscricao1[y] = num_inscricao1[x]-num_inscricao1[y];
                    num_inscricao1[x] = num_inscricao1[x]-num_inscricao1[y];

                    idade1[x] = idade1[x]+idade1[y];
                    idade1[y] = idade1[x]-idade1[y];
                    idade1[x] = idade1[x]-idade1[y];
                }
            }
        }
    }
    for(int x = 0; x < TAM; x++){                  //organizar notas do curso 2 em nota decrescente 
        for(int y = x+1;y < TAM; y++){
            if(nota_por_curso_pretendido2[x] < nota_por_curso_pretendido2[y]){
                nota_por_curso_pretendido2[x] = nota_por_curso_pretendido2[x]+nota_por_curso_pretendido2[y];
                nota_por_curso_pretendido2[y] = nota_por_curso_pretendido2[x]-nota_por_curso_pretendido2[y];
                nota_por_curso_pretendido2[x] = nota_por_curso_pretendido2[x]-nota_por_curso_pretendido2[y];

                num_inscricao2[x] = num_inscricao2[x]+num_inscricao2[y];
                num_inscricao2[y] = num_inscricao2[x]-num_inscricao2[y];
                num_inscricao2[x] = num_inscricao2[x]-num_inscricao2[y];

                idade2[x] = idade2[x]+idade2[y];
                idade2[y] = idade2[x]-idade2[y];
                idade2[x] = idade2[x]-idade2[y];
                
                x=0;
            }else if(nota_por_curso_pretendido2[x] == nota_por_curso_pretendido2[y]){
                if(idade2[x]<idade2[y]){
                    nota_por_curso_pretendido2[x] = nota_por_curso_pretendido2[x]+nota_por_curso_pretendido2[y];
                    nota_por_curso_pretendido2[y] = nota_por_curso_pretendido2[x]-nota_por_curso_pretendido2[y];
                    nota_por_curso_pretendido2[x] = nota_por_curso_pretendido2[x]-nota_por_curso_pretendido2[y];

                    num_inscricao2[x] = num_inscricao2[x]+num_inscricao2[y];
                    num_inscricao2[y] = num_inscricao2[x]-num_inscricao2[y];
                    num_inscricao2[x] = num_inscricao2[x]-num_inscricao2[y];

                    idade2[x] = idade2[x]+idade2[y];
                    idade2[y] = idade2[x]-idade2[y];
                    idade2[x] = idade2[x]-idade2[y];
                }
            }
        }
    }
    for(int x = 0; x < TAM; x++){                  //organizar notas do curso 3 em nota decrescente 
        for(int y = x+1;y < TAM; y++){
            if(nota_por_curso_pretendido3[x] < nota_por_curso_pretendido3[y]){
                nota_por_curso_pretendido3[x] = nota_por_curso_pretendido3[x]+nota_por_curso_pretendido3[y];
                nota_por_curso_pretendido3[y] = nota_por_curso_pretendido3[x]-nota_por_curso_pretendido3[y];
                nota_por_curso_pretendido3[x] = nota_por_curso_pretendido3[x]-nota_por_curso_pretendido3[y];

                num_inscricao3[x] = num_inscricao3[x]+num_inscricao3[y];
                num_inscricao3[y] = num_inscricao3[x]-num_inscricao3[y];
                num_inscricao3[x] = num_inscricao3[x]-num_inscricao3[y];

                idade3[x] = idade3[x]+idade3[y];
                idade3[y] = idade3[x]-idade3[y];
                idade3[x] = idade3[x]-idade3[y];
                
                x=0;
            }else if(nota_por_curso_pretendido3[x] == nota_por_curso_pretendido3[y]){
                if(idade3[x]<idade3[y]){
                    nota_por_curso_pretendido3[x] = nota_por_curso_pretendido3[x]+nota_por_curso_pretendido3[y];
                    nota_por_curso_pretendido3[y] = nota_por_curso_pretendido3[x]-nota_por_curso_pretendido3[y];
                    nota_por_curso_pretendido3[x] = nota_por_curso_pretendido3[x]-nota_por_curso_pretendido3[y];

                    num_inscricao3[x] = num_inscricao3[x]+num_inscricao3[y];
                    num_inscricao3[y] = num_inscricao3[x]-num_inscricao3[y];
                    num_inscricao3[x] = num_inscricao3[x]-num_inscricao3[y];

                    idade3[x] = idade3[x]+idade3[y];
                    idade3[y] = idade3[x]-idade3[y];
                    idade3[x] = idade3[x]-idade3[y];
                }
            }
        }
    }
    for(int x = 0; x < TAM; x++){                  //organizar notas do curso 4 em nota decrescente 
        for(int y = x+1;y < TAM; y++){
            if(nota_por_curso_pretendido4[x] < nota_por_curso_pretendido4[y]){
                nota_por_curso_pretendido4[x] = nota_por_curso_pretendido4[x]+nota_por_curso_pretendido4[y];
                nota_por_curso_pretendido4[y] = nota_por_curso_pretendido4[x]-nota_por_curso_pretendido4[y];
                nota_por_curso_pretendido4[x] = nota_por_curso_pretendido4[x]-nota_por_curso_pretendido4[y];

                num_inscricao4[x] = num_inscricao4[x]+num_inscricao4[y];
                num_inscricao4[y] = num_inscricao4[x]-num_inscricao4[y];
                num_inscricao4[x] = num_inscricao4[x]-num_inscricao4[y];

                idade4[x] = idade4[x]+idade4[y];
                idade4[y] = idade4[x]-idade4[y];
                idade4[x] = idade4[x]-idade4[y];
                
                x=0;
            }else if(nota_por_curso_pretendido4[x] == nota_por_curso_pretendido4[y]){
                if(idade4[x]<idade4[y]){
                    nota_por_curso_pretendido4[x] = nota_por_curso_pretendido4[x]+nota_por_curso_pretendido4[y];
                    nota_por_curso_pretendido4[y] = nota_por_curso_pretendido4[x]-nota_por_curso_pretendido4[y];
                    nota_por_curso_pretendido4[x] = nota_por_curso_pretendido4[x]-nota_por_curso_pretendido4[y];

                    num_inscricao4[x] = num_inscricao4[x]+num_inscricao4[y];
                    num_inscricao4[y] = num_inscricao4[x]-num_inscricao4[y];
                    num_inscricao4[x] = num_inscricao4[x]-num_inscricao4[y];

                    idade4[x] = idade4[x]+idade4[y];
                    idade4[y] = idade4[x]-idade4[y];
                    idade4[x] = idade4[x]-idade4[y];
                }
            }
        }
    }

    cout << "Lista de pessoas que venderam a alma pra faculdade:\nAprovados no curso 1:\n";     //imprimindo resultado dos fodidos
    for(i = 0; i < c1 and i < 40; i++){
        cout << num_inscricao1[i] << "\n";
    }
    cout << "Aprovados no curso 2:\n";
    for(i = 0; i < c2 and i < 40; i++){
        cout << num_inscricao2[i] << "\n";
    }
    cout << "Aprovados no  curso 3:\n";
    for(i = 0; i < c3 and i < 40; i++){
        cout << num_inscricao3[i] << "\n";
    }
    cout << "Aprovados no curso 4:\n";
    for(i = 0; i < c4 and i < 40; i++){
        cout << num_inscricao4[i] << "\n";
    }

    arquivo.close();

    return 0;
}