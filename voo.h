#ifndef VOO_H
#define VOO_H

#include <vector>
#include <string>
#include "Astronauta.h"

using namespace std;

class Voo {
public:
    int code;
    std::vector<Astronauta*> passanger;
    std::string status;  // planejado/ em curso ou finalizado

    // CONTR
    Voo(int code)
        : code(code), status("planejado") {}

    //MOSTRAR INFO DO VOO
    void ShowInfo() {
        std::cout << "CODIGO: " << code << "\n";
        std::cout << "STATUS: " << status << "\n";
        std::cout << "PASSAGEIROS:\n";
        for (auto& passageiro : passanger) {
            std::cout << " - " << passageiro->name << "\n";
        }
    }

    int getCode() const { return code; }
    std::string getStatus() const { return status; }

    void addPassenger(Astronauta* astronauta) {
        passanger.push_back(astronauta);
    }

    const std::vector<Astronauta*>& getPassenger() const {
        return passanger;
    }
};

#endif 