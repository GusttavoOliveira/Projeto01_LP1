#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "entregaParaEstados.h"

// ESTUDO 0

using namespace std;
void escreverNoCsv(vector<vector<string>> matriz);
void carregaBancoDeDados(vector<vector<string>> &matriz);
void distribui(vector<vector<string>> &matriz, string nomeInsumo,int estadoIndex, bool &validador);

int entregaParaEstados() {
    string estados[27] = {"Acre","Alagoas","Amapá","Amazonas","Bahia","Ceará","Distrito Federal","Espírito Santo","Goiás","Maranhão","Mato Grosso","Mato Grosso do Sul","Minas Gerais",
                            "Pará","Paraíba","Paraná","Pernambuco","Piauí","Rio de Janeiro","Rio Grande do Norte","Rio Grande do Sul","Rondônia","Roraima","Santa Catarina","São Paulo","Sergipe","Tocantins"};
    string estados2[27] = {"acre","alagoas","amapá","amazonas","bahia","ceará","distrito federal","espírito santo","goiás","maranhão","mato grosso","mato grosso do sul","minas gerais","pará","paraíba","paraná",
                            "pernambuco","piauí","rio de janeiro","rio grande do norte","rio grande do sul","rondônia","roraima","santa catarina","são paulo","sergipe","tocantins"};

    string insumo;
    char resposta;
    vector<vector<string>> matriz;
    int e;
    bool validador = true;

    carregaBancoDeDados(matriz);// carrega o banco de dados e armazena ele em vetor de vetor

    while(validador == true){
        cout << "Digite o nome do insumo que você deseja distribuir: " << endl;
        getline(cin,insumo);
        transform(insumo.begin(), insumo.end(), insumo.begin(),[](unsigned char c){ return tolower(c);});
        e = -1;
        while(e <= -1 || e >= 27){
            string estado;
            cout << "Digite o nome do estado ao qual você deseja distribuir o(s) insumos: " << endl;
            getline(cin,estado);
            transform(estado.begin(), estado.end(), estado.begin(),[](unsigned char c){ return tolower(c);});
            e = distance(estados2, find(estados2, estados2 + 27, estado)); //retorna a dist�ncia entre o endere�o do primeiro elemento e o endere�o do elemento escolhido
            if(e>=0){
                system("clear");
            }
        }

        distribui(matriz, insumo, e, validador);
    }

    do{
        //vector<string> tempLine;
        cout << '\n' << "Quer atualizar as modificações no banco de dados? S/N" << endl;
        cin >> resposta;
        cin.ignore();
            if(resposta == 'S' or resposta == 's'){
                escreverNoCsv(matriz);
                system("clear");
            }
            else if(resposta == 'N' or resposta == 'n'){
                system("clear");
            }
    }while(resposta != 'N' && resposta != 'S' && resposta != 's' && resposta != 'n');


}

void carregaBancoDeDados(vector<vector<string>> &matriz){

    ifstream ip;
    ip.open("estoqueMS.csv"); // Abrir�
    string colunasArquivo[41];
    string line;

    if(ip.is_open()){
        while (getline(ip, line)){
            vector<string> temp;
            // copia uma string ( no caso line ) e guarda em iss.
            istringstream iss(line);
            for(int x = 0 ; x < 41; x++){
            getline(iss,colunasArquivo[x],','); /// alguma coisa significa item da coluna do dataset
            temp.push_back(colunasArquivo[x]);
            colunasArquivo[x].clear();
            }

            matriz.push_back(temp);
        }
    }else{
    cout << "Não foi possível abrir o arquivo" << endl;
    }

}

void distribui(vector<vector<string>> &matriz, string nomeInsumo,int estadoIndex, bool &validador){
    vector<int> indexEncontrados;
    int qtdeInsumos;
    char resposta;

    cout << "Estado Index : " << estadoIndex << endl;
    string tempNome;
    for(int i = 0; i < matriz.size(); i++){ // Verifica se em alguma linha do DB existe alguma nome igual ao nome do insumo digitado
        tempNome = matriz[i][1];
        transform(tempNome.begin(), tempNome.end(), tempNome.begin(),[](unsigned char c){ return tolower(c);}); // converte o dado em minusculo
        if(nomeInsumo == tempNome){
            indexEncontrados.push_back(i); // guarda o index em um vetor
        }
    }
    if(indexEncontrados.size()==0){ // se n�o tiver alguma palavra igual, avisa que o objeto n�o foi insumo
        cout << "Nenhum insumo com este nome foi encontrado." << endl;
        return;
    }
    else{
        do{
        cout << "Quantos insumos deseja distribuir?" << endl;
        cin >> qtdeInsumos;
        cin.ignore();

            for(int i = 0; i < indexEncontrados.size(); i++){
                matriz[indexEncontrados[i]][3] = to_string(atoi(matriz[indexEncontrados[i]][3].c_str()) - qtdeInsumos);
                matriz[indexEncontrados[i]][estadoIndex+14] = to_string(atoi(matriz[indexEncontrados[i]][estadoIndex+14].c_str()) + qtdeInsumos);
                // for(int j = 0; j<matriz[i].size(); j++){
                //     cout << matriz[indexEncontrados[i]][j] << endl;
                // }
            }



            do{
                cout << '\n' << "Quer distribuir mais uma vez? S/N" << endl;
                cin >> resposta;
                cin.ignore();
                    if(resposta == 'S' or resposta == 's'){
                        system("clear");
                    }
                    else if(resposta == 'N' or resposta == 'n'){
                        system("clear");
                        validador = false;
                    }
            }while(resposta != 'N' && resposta != 'S' && resposta != 's' && resposta != 'n');
        }while(resposta == 'S' or resposta == 's');

    }
}

void escreverNoCsv(vector<vector<string>> matriz){
  ifstream file("estoqueMS.csv");
  ofstream out("estoqueMS.csv");
  if(out.is_open()){
    for(int i = 0; i < matriz.size(); i++){
        for(int j = 0; j < matriz[i].size(); j++){
            if( j < (matriz[i].size() - 1)) {
                out << matriz[i][j] << ",";
            }else  if(j == (matriz[i].size() - 1)){
                out << matriz[i][j];
            }
        }
        out << endl;
    }
    out.close();
  }
  else{
    cout << " Não foi possível abrir o arquivo" << endl;
  }
}
