#include "Sistema.h"
#include "astronauta.h"
#include "vector"


using namespace std;

int main() {
    Sistema sistema;

    // TESTANDO CRIANDO ASTRONAUTA TESTE
    sistema.registerAstronaut("11111111111", "edson", 21);
    sistema.registerAstronaut("22222222222", "juan", 20);
    std::cout << "-------------- REGISTREI ASTRONAUTA -------------------------" << endl;
    // TESTANDO CRIANDO VOOS
    sistema.registerFlight(1);
    sistema.registerFlight(2);
    std::cout << "----------- REGISTREI VOOS ----------------------------" << endl;
    // TESTANDO ADD ASTRONAUTAS EM VOO
    sistema.addAstronautInFlight("11111111111", 1);
    sistema.addAstronautInFlight("22222222222", 1);
    std::cout << "------------ADD ASTRONAUTA EM VOO ---------------------------" << endl;
    //TESTANDO REMOVE ASTRONAUTA
    sistema.removeAstronautInFlight("11111111111");
    std::cout << "-------------- REMOVI ASTRONAUTA -------------------------" << endl;
    //TESTANDO LANÇAR VOO
    sistema.TakeOffFlight(1);
    std::cout << "---------------LANCEI VOO------------------------" << endl;
    //TESTANDO EXPLODIR
    sistema.explodeFlight(1);
    std::cout << "--------------EXPLODI ELE-------------------------" << endl;
    // LISTANDO 
    sistema.ListFlights();
    std::cout << "----------------LISTEI TODOS VOOS REGISTRADOS -----------------------" << endl;
    //TESTANDO MOSTRAR MORTES
    sistema.ShowDeads();
    std::cout << "---------------MOSTRANDO MORTES ( PRIMEIRO VOO) ------------------------" << endl;
    sistema.addAstronautInFlight("11111111111", 2);
    std::cout << "------------ADD O OUTRO ASTRONAUTO NO VOO---------------------------" << endl;

    sistema.TakeOffFlight(2);
    std::cout << "------------LANCEI OUTRO VOO---------------------------" << endl;
    sistema.EndFlight(2);
    std::cout << "------------FINALIZEI ELE--------------------------" << endl;
    sistema.ListFlights();
    std::cout << "------------LISTEI OS VOOS DNV---------------------------" << endl;

    sistema.ShowDeads();
    std::cout << "------------VENDO AS MORTES---------------------------" << endl;

    sistema.registerAstronaut("11111111111", "joao", 21);
    std::cout << "------------TENTEI REGISTRAR ASTRONAUTA COM MSM CPF DE OUTRO---------------------------" << endl;

    sistema.registerAstronaut("33333333333", "joao", 21);
    std::cout << "------------REGISTREI OUTRO ASTRONAUTA---------------------------" <<endl;

    sistema.registerFlight(3);
    std::cout << "------------REGISTREI OUTRO VOO---------------------------" << endl; 

    sistema.addAstronautInFlight("33333333333", 3);
    sistema.addAstronautInFlight("11111111111", 3);
    std::cout << "------------COLOQUEI 2 ASTRONAUTAS NO VOO 3---------------------------" << endl; 
    sistema.TakeOffFlight(3);
    sistema.explodeFlight(3);
    std::cout << "------------lancei e explodi---------------------------" << endl; 

    sistema.ListFlights();
    std::cout << "-----------VENDO OS VOOS---------------------------" << endl; 

    sistema.ShowDeads();
    std::cout << "----------VENDO AS NOVAS MORTES--------------------------" << endl; 

    // 




    return 0;
}