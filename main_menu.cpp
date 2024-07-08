#include "Sistema.h"
#include "astronauta.h"
#include "vector"
#include <iostream>
#include <string>

using namespace std;
// SISTEMA
int main() {
    Sistema sistema;
    

    int opcao;

    do {
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "*                                                             *" << endl;
        cout << "*            SISTEMA DE ASTRONAUTAS                           *" << endl;
        cout << "*                                                             *" << endl;
        cout << "*                                              by:Franciedson *" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "*   MENU DE COMANDOS;                                         *" << endl;
        cout << "*   1. Registrar Astronauta;                                  *" << endl;
        cout << "*   2. Registrar Voos;                                        *" << endl;
        cout << "*   3. Adicionar Astronauta em Voo;                           *" << endl;
        cout << "*   4. Remover Astronauta do Voo;                             *" << endl;
        cout << "*   5. Listar Voos;                                           *" << endl;
        cout << "*   6. Listar Mortes;                                         *" << endl;
        cout << "*   7. Lancar Voo;                                            *" << endl;
        cout << "*   8. Explodir Voo;                                          *" << endl;
        cout << "*   9. Finalizar Voo;                                         *" << endl;
        cout << "*   0. Sair do sistema;                                       *" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

        //MINHAS VARIAVEIS
        cin >> opcao;
        int code;
        string cpf, nome;               
        int idade;

        switch (opcao) {
            case 1:
                
                cout << "NOME: " << endl; cin >> nome;
                cout << "IDADE: " << endl; cin >> idade;
                cout << "CPF: " << endl; cin >> cpf;
                sistema.registerAstronaut(cpf, nome, idade);
                break;

            case 2:

                cout << "DIGITE O CODIGO DO VOO QUE DESEJA CRIAR: " << endl; cin >> code;
                sistema.registerFlight(code);
                break;

            case 3:
                 cout << "DIGITE CPF DO ASTRONAUTA E CODIGO DO VOO: " << endl;
                 cout << "CPF: " << endl; cin >> cpf;
                 cout << "CODIGO: " << endl; cin >> code;
                 sistema.addAstronautInFlight(cpf, code);
                break;
            case 4:
                cout << "DIGITE CPF DO ASTRONAUTA: " << endl; cin >> cpf;
                sistema.removeAstronautInFlight(cpf);
                break;
            case 5:
                sistema.ListFlights();
                break;
            case 6:
                sistema.ShowDeads();
                break;
            case 7:
                cout << "DIGITE O CODIGO DO VOO QUE DESEJA LANCAR: " << endl; cin >> code;
                sistema.TakeOffFlight(code);
                break;
            case 8:
                cout << "DIGITE O CODIGO DO VOO QUE DESEJA EXPLODIR: " << endl; cin >> code;
                sistema.explodeFlight(code);
                break;
            case 9:
                cout << "CODIGO DO VOO QUE DESEJA FINALIZAR: " << endl; cin >> code;
                sistema.EndFlight(code);
                break;
            case 0:
                cout << "SAINDO DO SISTEMA..." << endl;
            default:
                cout << "OPCAO INVALIDA." << endl;
                break;
        }
    } while (opcao != 0);




    return 0;
}