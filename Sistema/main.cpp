#include <iostream>
#include <string>
#include <vector>
#include "cadastraInsumos.h"
#include "consultaDistEstados.h"
#include "consultaDistribuidos.h"
#include "consultaInsumosMS.h"
#include "consultarPorTipo.h"
#include "retornaDistribuidosPorTipo.h"
#include "entregaParaEstados.h"
#include "menu.h"


using namespace std;

int main(){

    int acaba = 1;


    while(1){

        acaba = menu();
        if(acaba == 0){
            return 0;
        }
    }

}


