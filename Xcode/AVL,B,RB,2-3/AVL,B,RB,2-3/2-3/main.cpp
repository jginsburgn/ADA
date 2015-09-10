#include <iostream>
#include "BinaryTree23.h"

int main(int argc, const char * argv[])
{
    std::cout << "Bienvenido al arbol 23 TX-2932" << std::endl;
    std::cout << "A continuacion se haran los procesos" << std::endl;
    std::cout << "\nInsertar e imprimir" << std::endl;
    
    BinaryTree23<int> *T23 = new BinaryTree23<int>();

    T23->insert(50);
    T23->insert(62);
    T23->insert(75);
    T23->insert(13);
    T23->insert(33);
    T23->insert(27);
    T23->insert(29);
    T23->inOrder();
    std::cout << std::endl;
    
    T23->postOrder();
    std::cout << std::endl;
    
    std::cout << "\nBorrar" << std::endl;
    
    T23->remove(13);
    T23->remove(62);
    T23->inOrder();
    cout << endl;
    
    std::cout << "\nBuscar" << std::endl;
    
    if(T23->search(62)){
        std::cout << "Se encontró el dato" << std::endl;
    }else{
        std::cout << "No se encontró el dato" << std::endl;
    }
    
    std::cout << "\n" << std::endl;
    
    delete T23;
    
    return 0;
}
