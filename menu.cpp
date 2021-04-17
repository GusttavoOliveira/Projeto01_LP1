#include <iostream>
#include <string>
#include <vector>
#include "menu.h"
#include "cadastraInsumos.h"
#include "consultaDistEstados.h"
#include "consultaDistribuidos.h"
#include "consultaInsumosMS.h"
#include "consultarPorTipo.h"
#include "retornaDistribuidosPorTipo.h"
#include "entregaParaEstados.h"

using namespace std;
/** MENU **/
int menu(){
    int opcao;
    print:
    setlocale(LC_ALL, "portuguese-brazilian");
    cout << "DIGITE UMA ALTERNATIVA PARA ACESSAR:" << endl;
    cout << "1) Cadastre insumos" << endl;
    cout << "2) Consulte relatório do estoque do MS" << endl;
    cout << "3) Consulte insumos disponíveis no estoque de acordo com o tipo" << endl;
    cout << "4) Consulte insumos distribuidos de acordo com o estado" << endl;
    cout << "5) Consulte distruibuidos de acordo com o tipo"<< endl;
    cout << "6) Consulte distribuidos de acordo com estado" << endl;
    cout << "7) Entrega insumos para os Estados" << endl;
    cout << "0) Sair" << endl;
    cin >> opcao;
    cin.ignore();
    system("cls");

    switch (opcao){
    case 0:
        cout << "Até a próxima" << endl;
        return 0;
    case 1:
        cadastraInsumos();
        break;
    case 2:
        consultaInsumosMS();
        break;
    case 3:
        consultarPorTipo();
        break;
    case 4:
        consultaDistribuidos();
        break;
    case 5:
        retornaDistribuidosPorTipo();
        break;
    case 6:
        consultaDistEstados();
        break;
    case 7:
        entregaParaEstados();
        break;
    }
}
