#include "consultaDistEstados.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>


using namespace std;

int consultaDistEstados(){

  string estados[27] = {"Acre","Alagoas","Amap�","Amazonas","Bahia","Cear�","Distrito Federal","Esp�rito Santo","Goi�s","Maranh�o","Mato Grosso","Mato Grosso do Sul","Minas Gerais","Par�","Para�ba","Paran�","Pernambuco","Piau�","Rio de Janeiro","Rio Grande do Norte","Rio Grande do Sul","Rond�nia","Roraima","Santa Catarina","S�o Paulo","Sergipe","Tocantins"};
  string estados2[27] = {"acre","alagoas","amap�","amazonas","bahia","cear�","distrito federal","esp�rito santo","goi�s","maranh�o","mato grosso","mato grosso do sul","minas gerais","par�","para�ba","paran�","pernambuco","piau�","rio de janeiro","rio grande do norte","rio grande do sul","rond�nia","roraima","santa catarina","s�o paulo","sergipe","tocantins"};


  start:

  ifstream ip;
  ip.open("estoqueMS.csv"); // Abrir�

  vector<vector<string>> matriz;
  string colunasArquivo[41];
  string line;


  int e = -1;
  while(e == -1){

    string entrada;
    cout << "Digite o estado que deseja consultar:" << endl;
    getline(cin, entrada);
    //fflush(stdin);
    transform(entrada.begin(), entrada.end(), entrada.begin(),[](unsigned char c){ return tolower(c);});
    e = distance(estados2, find(estados2, estados2 + 27, entrada));
    if(e>=0){
      system("cls");
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
    cout << "N�o foi poss�vel abrir o arquivo" << endl;
  }

  bool verificaVazio = false;
  int estadoQtde[matriz.size()];

  for(int i = 1 ; i < matriz.size(); i++){
      estadoQtde[i] = atoi(matriz[i][e+14].c_str());

      if(estadoQtde[i] > 0 ){
        verificaVazio = true;
        cout << "Estado do " << estados[e] << "\n" <<endl;

        string flag;
        flag = matriz[i][0];

        //especifica linhas de vacina
        if(flag =="Vacina"){
          cout << "Insumo: " << matriz[i][0] << endl;
          cout << "Nome: " << matriz[i][1] << endl;
          cout << "Preco por unidade: " << matriz[i][2] << endl;
          cout << "Quantidade do " << estados[e] << ": " << matriz[i][e+14] << endl;
          cout << "Vencimento: " << matriz[i][4] << endl;
          cout << "Fabricante: " << matriz[i][5] << endl;
          cout << "Tipo de vacina: " << matriz[i][6] << endl;
          cout << "Quantidade de doses: " << matriz[i][7] << endl;
          cout << "Per�odo de espera entre as doses: " << matriz[i][8] << endl;
          cout << "\n----------------------------------\n";
        }

        //especifica linhas de medicamento
        if(flag =="Medicamento"){
          cout << "Insumo: " << matriz[i][0] << endl;
          cout << "Nome: " << matriz[i][1] << endl;
          cout << "Preco por unidade: " << matriz[i][2] << endl;
          cout << "Quantidade do estado do " << estados[e] << ": " << matriz[i][e+14] << endl;
          cout << "Vencimento: " << matriz[i][4] << endl;
          cout << "Fabricante: " << matriz[i][5] << endl;
          cout << "Dosagem: " << matriz[i][9] << endl;
          cout << "Forma de administracao: " << matriz[i][10] << endl;
          cout << "Forma de disponibiliza��o: " << matriz[i][11] << endl;
          cout << "\n----------------------------------\n";
        }

        //especifica linhas de EPI
        if(flag == "Epi"){
          cout << "Insumo: " << matriz[i][0] << endl;
          cout << "Nome: " << matriz[i][1] << endl;
          cout << "Preco por unidade: " << matriz[i][2] << endl;
          cout << "Quantidade do estado do " << estados[e] << ": " << matriz[i][e+14] << endl;
          cout << "Vencimento: " << matriz[i][4] << endl;
          cout << "Fabricante: " << matriz[i][5] << endl;
          cout << "Tipo de EPI: " << matriz[i][12] << endl;
          cout << "Descricao do EPI: " << matriz[i][13] << endl;
          cout << "\n----------------------------------\n";
        }

      }
  }

  if(!verificaVazio){
    cout << "Esse estado n�o recebeu insumos ainda!" << endl;
    verificaVazio = false;
  }

  char resposta;
  do{
    cout << '\n' << "Quer consultar mais uma vez? S/N" << endl;
    cin >> resposta;
    cin.ignore();
    if(resposta == 'S' or resposta == 's'){
      system("cls");
      goto start;
    }
    else if(resposta == 'N' or resposta == 'n'){
      system("cls");
      return 0;
    }
  }while(resposta != 'N' or resposta == 'S' or resposta == 's' or resposta != 'n');

  return 0;
}
