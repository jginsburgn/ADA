#include <iostream>
#include "BinaryTreeRB.h"

int main(int argc, const char * argv[])
{
    std::cout << "Bienvenido al arbol 23 TX-2932" << std::endl;
    std::cout << "A continuacion se haran los procesos" << std::endl;
    std::cout << "\nInsertar e imprimir" << std::endl;

    BinaryTreeRB<int> *BTRB = new BinaryTreeRB<int>();
    BTRB->insert(50);
    BTRB->insert(60);
    BTRB->insert(70);
    BTRB->insert(74);
    BTRB->insert(85);
    BTRB->insert(45);
    
    BTRB->insert(2);
    BTRB->insert(120);
    BTRB->insert(64);
    BTRB->insert(250);
    BTRB->insert(330);
    
    BTRB->InOrder(BTRB->getRoot());
    std::cout << endl;
    BTRB->postOrder(BTRB->getRoot());
    std::cout << endl;
    std::cout << "\nBorrar" << std::endl;
    
    BTRB->removeInfo(60);
    BTRB->removeInfo(64);
    BTRB->removeInfo(45);
    BTRB->InOrder(BTRB->getRoot());
    cout << endl;
    
    std::cout << "\nBuscar" << std::endl;
    if(BTRB->search(120)){
        std::cout << "Se encontró el dato" << std::endl;
    }else{
        std::cout << "No se encontró el dato" << std::endl;
    }
    
    std::cout << "\n" << std::endl;

    
    delete BTRB;
    return 0;
}
