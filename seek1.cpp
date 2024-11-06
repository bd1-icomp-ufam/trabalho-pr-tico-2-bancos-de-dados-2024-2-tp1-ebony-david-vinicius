#include "bptree.hpp"
#include <cstdlib>
#include <cstdio>
#include <iostream>

BPTree indicePrimario(3); // Instância para o índice primário

void buscarPorID(int id) {
    std::string resultado = indicePrimario.search(id);
    if (resultado == "Key not found") {
        std::cout << "Registro com ID " << id << " não encontrado." << std::endl;
    } else {
        std::cout << "Registro encontrado: " << resultado << std::endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr,"Nº de argumentos inválido, precisa ser 1\n");
        exit(1);
    }

    int id = atoi(argv[1]);
    buscarPorID(id);
    return 0;
}
