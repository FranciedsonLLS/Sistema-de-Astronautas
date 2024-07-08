#ifndef SISTEMA_H
#define SISTEMA_H


#include <vector>
#include <iostream>
#include <algorithm>
#include "Astronauta.h"
#include "Voo.h"

using namespace std;

class Sistema {
private:
    std::vector<Astronauta*> astronautas;
    std::vector<Voo*> voos;
    std::vector<Astronauta*> deadAstronaut; // GUARDANDO OS ASTRONAUTAS QUE MORRERAM 

public:
    // CREATE ASTRONAUTA
    void registerAstronaut(string cpf, string name, int idade) {
        for (auto& astronauta : astronautas) {
            if (astronauta->cpf == cpf) {
                cout << "CPF JA EXISTENTE" << endl;
                return;
            }
        }
        astronautas.push_back(new Astronauta(cpf, name, idade));
        std::cout << "ASTRONAUTA CADASTRADO! " << "\n" << " NOME: " << name << " CPF: " << cpf << "\n";
    }

    // CREATE VOO
    void registerFlight(int code) {
        for (auto& voo : voos) {
            if (voo->code == code) {
                std::cout << "CODIGO JA EXISTENTE" << std::endl;
                return;
            }
        }
        voos.push_back(new Voo(code));
        std::cout << "VOO CADASTRADO. \n CODIGO:" << code << "\n";
    }

    //FUNC ADD ASTRONAUTA EM VOO
    void addAstronautInFlight(std::string cpf, int code) {
        Astronauta* astronauta = nullptr;
        for (auto& a : astronautas) {
            if (a->cpf == cpf) {
                astronauta = a;
                break;
            }
        }

        if (astronauta == nullptr) {
            std::cout << "CPF: " << cpf << " NAO ENCONTRADO." << std::endl;
            return;
        }

        Voo* voo = nullptr;
        for (auto& v : voos) {
            if (v->code == code) {
                voo = v;
                break;
            }
        }

        if (voo == nullptr) {
            std::cout << "CODIGO DE VOO INVALIDO. " << std::endl;
            return;
        }

        if (!astronauta->disponivel) {
            std::cout << "ESSE ASTRONAUTA NAO TA DISPONIVEL." << std::endl;
            return;
        }

        if (voo->status != "planejado") {
            std::cout << "ESSE VOO NAO PLANEJADO." << "\n" << "Codigo: "<< code << std::endl;
            return;
        }
        

        voo->passanger.push_back(astronauta);
        std::cout << "O ASTRONAUTA, " << astronauta->name << ". FOI ADICIONADO AO VOO." << std::endl;
    }

    //remover astronauta de voo
    void removeAstronautInFlight(std::string cpf) {
        

        

        

        for (auto& voo : voos) {
            if (voo->status == "planejado") {
                auto it = std::remove_if(voo->passanger.begin(), voo->passanger.end(),
                                         [cpf](Astronauta* a) { return a->cpf == cpf; });

                if (it != voo->passanger.end()) {
                    voo->passanger.erase(it, voo->passanger.end());
                    std::cout << "O ASTRONAUTA FOI REMOVIDO COM SUCESSO." << "\n CODIGO DE VOO: " << voo->code << std::endl;
                }
            } else if (voo->status == "em curso") {
                std::cout << "O VOO TA EM CURSO E NÃO É POSSIVEL REMOVER O ASTRONAUTA" << std::endl;
            } 
        }
    }
    
    void TakeOffFlight(int codigoVoo) {
    // ENCONTRAR O VOO QUE FOI ESPECIFICADO PELO CODIGO
    Voo* voo = nullptr;
    for (auto& v : voos) {
        if (v->getCode() == codigoVoo) {
            voo = v;
            break;
        }
    }

    if (voo == nullptr) {
        std::cout << "VOO NAO ENCONTRADO \n CODIGO: " << codigoVoo << std::endl;
        return;
    }

    // VER SE TEM ASTRONAUTA
    if (voo->getPassenger().empty()) {
        std::cout << "NAO EXISTE ASTRONAUTAS NESSE VOO \n CODIGO: " << codigoVoo << std::endl;
        return;
    }

    // ALTERANDO STATUS
    voo->status = "em curso"; 

    // ATT E ADICIONAR VOO PARTICIPADO PELOS ASTRONAUTAS LISTADOS
    for (auto& astronauta : voo->getPassenger()) {
        astronauta->ParticipatedFlight.push_back(codigoVoo);
    }

    std::cout << "VOO LANCADO COM SUCESSO! \n CODIGO: " << codigoVoo << std::endl;
}

    //EXPLODIR VOO
void explodeFlight(int code) {
    Voo* voo = nullptr;
    for (auto& v : voos) {
        if (v->code == code) {
            voo = v;
            break;
        }
    }

        //VERIFICAR CODIGO
        if (voo == nullptr) {
            std::cout << "CODIGO: " << code << " NAO ENCONTRADO." << std::endl;
            return;
        }

        //VER SE TA EM CURSO (PRA PODER EXPLODIR)
        if (voo->status != "em curso") {
            std::cout << "ESSE VOO NÃO FOI LANÇADO!" << "\n CODIGO: " << code << std::endl;
            return;
        }

        // ALTERAR STATUS DE VIVO
        for (auto& astronauta : voo->passanger) {
            astronauta->vivo = false;
            deadAstronaut.push_back(astronauta);
        }

        //STATUS VOO PARA EXPLODIDO
        voo->status = "explodido";
        std::cout << "O VOO FOI " << " EXPLODIDO." << "\n CODIGO:"<< code <<std::endl;
    }

    // FUNC FINALIZAR VOO
    void EndFlight(int code) {
        Voo* voo = nullptr;
        for (auto& v : voos) {
            if (v->code == code) {
                voo = v;
                break;
            }
        }
    //VERIFICAR CODIGO
        if (voo == nullptr) {
            std::cout << "CODIGO: " << code << " NAO ENCONTRADO." << std::endl;
            return;
        }
    //VER SE TA EM CURSO (PRA PODER FINALIZAR)
        if (voo->status != "em curso") {
            std::cout << "ESSE VOO NÃO FOI LANÇADO!" << "\n CODIGO: " << code << std::endl;
            return;
        }

    //ALTERAR STATUS DE VOO PARA FINALIZADO
        voo->status = "FINALIZADO";
        std::cout << "VOO FINALIZADO \n CODIGO: " << code << std::endl;
    }

// EXIBIR MORTOS
    void ShowDeads() {
    std::cout << "OS SEGUINTES ASTRONAUTAS QUE FORAM MORTOS:" << std::endl;
    for (const auto& astronauta : deadAstronaut) {
        std::cout << "CPF: " << astronauta->cpf << ", NOME: " << astronauta->name << std::endl;
        if (!astronauta->ParticipatedFlight.empty()) {
            std::cout << "  VOOS JA PARTICIPADOS:" << std::endl;
            for (int codigoVoo : astronauta->ParticipatedFlight) {
                std::cout << "   VOO DE CODIGO: " << codigoVoo << std::endl;
            }
        }
    }
}

    // FUNC MOSTRAR TODOS OS VOOS
    void ListFlights() {
        std::cout << "VOOS DO SISTEMA: " << std::endl;
        for (const auto& voo : voos) {
            voo->ShowInfo();
        }
    }
};

#endif 