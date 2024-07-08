
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Astronauta {
public:
    std::string cpf;
    std::string name;
    int idade;
    bool disponivel;

    // Construtor
    Astronauta(std::string cpf, std::string nome, int idade)
        : cpf(cpf), name(nome), idade(idade), disponivel(true) {}

    // Método para exibir informações do astronauta
    void exibirInfo() {
        std::cout << "CPF: " << cpf << "\n";
        std::cout << "Nome: " << name << "\n";
        std::cout << "Idade: " << idade << "\n";
    }
};

class Voo {
public:
    int codigo;
    std::vector<Astronauta*> passanger;
    std::string status;  // "em planejamento", "em curso", "finalizado"

    // Construtor
    Voo(int codigo)
        : codigo(codigo), status("em planejamento") {}

    // Método para exibir informações do voo
    void exibirInfo() {
        std::cout << "Código do Voo: " << codigo << "\n";
        std::cout << "Status: " << status << "\n";
        std::cout << "Passageiros:\n";
        for (auto& passageiro : passanger) {
            std::cout << " - " << passageiro->name << "\n";
        }
    }
};