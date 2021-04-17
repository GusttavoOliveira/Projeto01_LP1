#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include "consultarPorTipo.h"


using namespace std;

int consultarPorTipo()
{
  ifstream ip; //Cria uma variável para apontar para o arquivo


  start: //////////////////// aqui retorna a função
  string line;
  string entrada;
  bool validador = true;
  //Lê cada linha do arquivo "ip" e guarda em "line", uma linha a cada iteração

  while(validador){
    validador = false;
    cout << "Digite qual será o tipo de insumo:" << endl;
    getline (cin, entrada);

    transform(entrada.begin(), entrada.end(), entrada.begin(),[](unsigned char c){ return tolower(c); }); // converte a entrada em minúsculo

    if(entrada != "vacina" && entrada != "medicamento" && entrada != "epi"){
      system("cls");
      validador = true;
    }

  }


    for(int i=0; i<3; i++){ // Esse loop irá girar o dataset 3 vezes
      ip.open("estoqueMS.csv"); // Abrirá
      if(ip.is_open()){
        while (getline(ip, line)){
          // copia uma string ( no caso line ) e guarda em iss.
          istringstream iss(line);

          //possíveis varíaveis dos insumos
          string insumo, nome, valorUni, quantidade, dataVenc, nomeFabri, tipoVac, quantDoses, interDose, tamDosagem, administracao, formOfertados, tipoEPI, descricaoEPI;

          // procura linhas válidas
          if(getline(iss, insumo, ',') && getline(iss, nome, ',') &&  getline(iss, valorUni, ',') && getline(iss, quantidade, ',') && getline(iss, dataVenc, ',') && getline(iss, nomeFabri, ',') && getline(iss, tipoVac,',') && getline(iss, quantDoses, ',') && getline(iss, interDose,',') && getline(iss, tamDosagem,',') && getline(iss, administracao,',') && getline(iss, formOfertados,',') && getline(iss, tipoEPI,',')&& getline(iss, descricaoEPI)){

            /*
            char *endp = nullptr;
            long n = strtol(id.c_str(), &endp, 10);
            */

            if(i==0 &&  entrada=="vacina"){
              //especifica linhas de vacina
              if(insumo == "Vacina" && tamDosagem == "NaN" && tipoEPI == "NaN"){
                cout << "Insumo: " << insumo << endl;
                cout << "Nome: " << nome << endl;
                cout << "Preco por unidade: " << valorUni << endl;
                cout << "Quantidade: " << quantidade << endl;
                cout << "Vencimento: " << dataVenc << endl;
                cout << "Fabricante: " << nomeFabri << endl;
                cout << "Tipo de vacina: " << tipoVac << endl;
                cout << "Quantidade de doses: " << quantDoses << endl;
                cout << "Período de espera entre as doses: " << interDose << endl;
                cout << "\n----------------------------------\n";
              }
            }
            if(i==1 && entrada=="medicamento"){
              //especifica linhas de medicamento
              if(insumo == "Medicamento" && tipoVac == "NaN" && descricaoEPI == "NaN"){
                cout << "Insumo: " << insumo << endl;
                cout << "Nome: " << nome << endl;
                cout << "Preco por unidade: " << valorUni << endl;
                cout << "Quantidade: " << quantidade << endl;
                cout << "Vencimento: " << dataVenc << endl;
                cout << "Fabricante: " << nomeFabri << endl;
                cout << "Dosagem: " << tamDosagem << endl;
                cout << "Forma de administracao: " << administracao << endl;
                cout << "Forma de disponibilização: " << formOfertados << endl;
                cout << "\n----------------------------------\n";
              }
            }

            if(i==2 && entrada == "epi"){
            //especifica linhas de EPI
              if(insumo == "EPI" && tamDosagem == "NaN" && tipoVac == "NaN"){
                cout << "Insumo: " << insumo << endl;
                cout << "Nome: " << nome << endl;
                cout << "Preco por unidade: " << valorUni << endl;
                cout << "Quantidade: " << quantidade << endl;
                cout << "Vencimento: " << dataVenc << endl;
                cout << "Fabricante: " << nomeFabri << endl;
                cout << "Tipo de EPI: " << tipoEPI << endl;
                cout << "Descricao do EPI: " << descricaoEPI << endl;
                cout << "\n----------------------------------\n";
              }
            }

          }
        }
        ip.close();
      }else{
        cout << "Não foi possível abrir o arquivo" << endl;
      }
    }

    char resposta;
    do{
      cout << '\n' << "Quer consultar mais um insumo? S/N" << endl;
      cin >> resposta;
    if(resposta == 'S' or resposta == 's'){
      system("cls");
      goto start;
    }
    else if(resposta == 'N' or resposta == 'n'){
      system("cls");
      return 0;
    }
    }while(resposta != 'N' or resposta == 'S' or resposta == 's' or resposta != 'n');

}
