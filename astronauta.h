#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <iostream>
#include <string>
#include <vector>

class Astronauta {
public:
    std::string cpf;
    std::string name;
    std::vector<int> ParticipatedFlight;
    int idade;
    bool disponivel;
    bool vivo;
    

    // CONTRUTOR
    Astronauta(std::string cpf, std::string nome, int idade)
        : cpf(cpf), name(nome), idade(idade), disponivel(true) {}

    // EXIBIR INFO 
    void exibirInfo() {
        std::cout << "CPF: " << cpf << "\n";
        std::cout << "Nome: " << name << "\n";
        std::cout << "Idade: " << idade << "\n";
    }
};

#endif 

