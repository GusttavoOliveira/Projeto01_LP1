#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "retornaDistribuidosPorTipo.h"

// ESTUDO 0

using namespace std;

int retornaDistribuidosPorTipo(){

  start:

  ifstream ip;
  ip.open("estoqueMS.csv"); // Abrir�

  vector<vector<string>> matriz;
  string colunasArquivo[41];
  string line;
  string entrada;

  bool validador = true;
  //L� cada linha do arquivo "ip" e guarda em "line", uma linha a cada itera��o

  while(validador){
    validador = false;
    cout << "Digite qual será o tipo de insumo:" << endl;
    getline (cin, entrada);

    transform(entrada.begin(), entrada.end(), entrada.begin(),[](unsigned char c){ return tolower(c); }); // converte a entrada em min�sculo

    entrada[0] = toupper(entrada[0]);

    if(entrada != "Vacina" && entrada != "Medicamento" && entrada != "Epi"){
      system("clear");
      validador = true;
    }

  }

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


  string estados[27] = {"Acre","Alagoas","Amapá","Amazonas","Bahia","Ceará","Distrito Federal","Espírito Santo","Goiás","Maranhão","Mato Grosso","Mato Grosso do Sul","Minas Gerais","Pará","Paraíba","Paraná","Pernambuco","Piauí","Rio de Janeiro","Rio Grande do Norte","Rio Grande do Sul","Rondônia","Roraima","Santa Catarina","São Paulo","Sergipe","Tocantins"};

  bool verificaVazio = false;
  int estadoQtde[matriz.size()];
  for(int e = 0; e < 27; e++){ // vtncu isso ta mt lindo



    for(int i = 1 ; i < matriz.size(); i++){
        estadoQtde[i] = atoi(matriz[i][e+14].c_str());

        string flag;
        flag = matriz[i][0];

        if(estadoQtde[i] > 0 && flag == entrada){
          verificaVazio = true;
          cout << "Estado do " << estados[e] << "\n" <<endl;

          //especifica linhas de vacina
          if(flag == "Vacina" && entrada == "Vacina"){
            cout << "Insumo: " << matriz[i][0] << endl;
            cout << "Nome: " << matriz[i][1] << endl;
            cout << "Preço por unidade: " << matriz[i][2] << endl;
            cout << "Quantidade do " << estados[e] << ": " << matriz[i][e+14] << endl;
            cout << "Vencimento: " << matriz[i][4] << endl;
            cout << "Fabricante: " << matriz[i][5] << endl;
            cout << "Tipo de vacina: " << matriz[i][6] << endl;
            cout << "Quantidade de doses: " << matriz[i][7] << endl;
            cout << "Período de espera entre as doses: " << matriz[i][8] << endl;
            cout << "\n----------------------------------\n";
          }

          //especifica linhas de medicamento
          if(flag =="Medicamento" && entrada == "Medicamento"){
            cout << "Insumo: " << matriz[i][0] << endl;
            cout << "Nome: " << matriz[i][1] << endl;
            cout << "Preço por unidade: " << matriz[i][2] << endl;
            cout << "Quantidade do estado do " << estados[e] << ": " << matriz[i][e+14] << endl;
            cout << "Vencimento: " << matriz[i][4] << endl;
            cout << "Fabricante: " << matriz[i][5] << endl;
            cout << "Dosagem: " << matriz[i][9] << endl;
            cout << "Forma de administracao: " << matriz[i][10] << endl;
            cout << "Forma de disponibilização: " << matriz[i][11] << endl;
            cout << "\n----------------------------------\n";
          }

          //especifica linhas de EPI
          if(flag == "Epi" && entrada == "Epi"){
            cout << "Insumo: " << matriz[i][0] << endl;
            cout << "Nome: " << matriz[i][1] << endl;
            cout << "Preço por unidade: " << matriz[i][2] << endl;
            cout << "Quantidade do estado do " << estados[e] << ": " << matriz[i][e+14] << endl;
            cout << "Vencimento: " << matriz[i][4] << endl;
            cout << "Fabricante: " << matriz[i][5] << endl;
            cout << "Tipo de EPI: " << matriz[i][12] << endl;
            cout << "Descrição do EPI: " << matriz[i][13] << endl;
            cout << "\n----------------------------------\n";
          }

      }
    }
  }
  if(!verificaVazio){
    cout << "Nenhum estado recebeu insumos ainda!" << endl;
    verificaVazio = false;
  }

char resposta;
  do{
    cout << '\n' << "Quer consultar mais uma vez? S/N" << endl;
    cin >> resposta;
    if(resposta == 'S' or resposta == 's'){
      system("clear");
      goto start;
    }
    else if(resposta == 'N' or resposta == 'n'){
      system("clear");
      return 0;
    }
  }while(resposta != 'N' or resposta == 'S' or resposta == 's' or resposta != 'n');

  return 0;
}

