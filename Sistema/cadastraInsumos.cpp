#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include "cadastraInsumos.h"

using namespace std;

//Transfere cadastro para o arquivo:
void escreverNoCsv(vector<string> cadastro){

  ofstream arquivo;

  arquivo.open("estoqueMS.csv", ios::app);
  string linha;
  if(arquivo.is_open()){
    arquivo << "\n";

    for(int i = 0; i < 41; i++){
      if( i < 40){
        arquivo << cadastro[i] << ",";
      }else  if(i == 40){
        arquivo << cadastro[i];
      }
    }
    arquivo.close();
  }
  else{
    cout << " N�o foi poss�vel abrir o arquivo" << endl;
  }
}

int cadastraInsumos(){

    start:
    string outputs[14] = {"um insumo:", "o nome do insumo:", "o pre�o por unidade:","a quantidade do insumo:", "o vencimento do insumo:", "o fabricante do insumo:", "o tipo da vacina:", "a quantidade de doses:", "o intervalo das doses", "a dosagem do medicamento:", "a administra��o do medicamento:", "a disponibiliza��o do medicamento:", "o tipo do EPI:", "a descri��o do EPI:" };

    vector<string> cadastro;// armazena os valores
    cout << "\nVamos cadastrar um insumo!" << endl;
    string flag;//primeira coisa que o usu�rio escreve

    for(int i = 0; i < 41; i++){ // loop que percorre todas as 41 colunas
        string val; // recebe o valor da entrada

        if(i==0){
            cout << "\nDigite " << outputs[i]<< endl;
            getline(cin, val);// l� o valor
            transform(val.begin(), val.end(), val.begin(),[](unsigned char c){ return tolower(c); });//transforma a flag e minusculo
            val[0] = toupper(val[0]);//Capitaliza a primeira palavra
            flag = val;
        }

        if((flag=="Vacina" || flag=="vacina") && i!=0 && i<9){
            cout << "\nDigite " << outputs[i]<< endl;
            getline(cin, val);// l� o valor
        }

        if((flag=="Medicamento" or flag=="medicamento") && i!=0 && ((i<6) || (i>8 && i<12))){
            cout << "\nDigite " << outputs[i]<< endl;
            getline(cin, val);// l� o valor
        }

        if((flag=="EPI" or flag=="epi") && i!=0 && ((i<6) || (i>11))){
            cout << "\nDigite " << outputs[i]<< endl;
            getline(cin, val);// l� o valor
        }


        transform(val.begin(), val.end(), val.begin(),[](unsigned char c){ return tolower(c); });// transforma valores em minusculo
        val[0] = toupper(val[0]); // Capitaliza a primeira palavra

        if(flag != "Vacina" && flag != "vacina" && flag != "Medicamento" && flag != "medicamento" &&  flag != "EPI" && flag != "epi"){
            system("cls");
            goto start;
        }

        else if(flag=="Vacina" or flag=="vacina"){ //Entradas apenas caso o insumo escolhido for Vacina
            if(i<9){
                cadastro.push_back(val);
            }
            if(i>=9 && i<14){
                cadastro.push_back("NaN");
            }
            if(i>=14){
                cadastro.push_back("0");
            }
        }

        else if(flag=="Medicamento" or flag=="medicamento"){ //Entradas apenas caso o insumo escolhido for Medicamento

            if((i<6) || (i>8 && i<12)){
                cadastro.push_back(val);
            }
            if((i>=6 && i<=8) || (i>11 && i<14)){
                cadastro.push_back("NaN");
            }
            if(i>=14){
                cadastro.push_back("0");
            }
        }

        else if(flag=="EPI" or flag=="epi"){ //Entradas apenas caso o insumo escolhido for EPI

            if((i<6) || (i>11)){
                cadastro.push_back(val);
            }
            if(i>5 && i<12){
                cadastro.push_back("NaN");
            }
            if(i>=14){
                cadastro.push_back("0");
            }
        }
    }
    escreverNoCsv(cadastro);
    cadastro.clear();
    char resposta;

    do{
        cout << '\n' << "Quer cadastrar mais um insumo? S/N" << endl;
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

