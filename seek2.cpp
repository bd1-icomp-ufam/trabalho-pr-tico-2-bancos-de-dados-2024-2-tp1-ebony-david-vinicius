#include "bptree.hpp"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

BPTree indiceSecundario(3); // Instância para o índice secundário

int calcularHash(const std::string& titulo) {
    int hash = 0;
    for (char c : titulo) {
        hash = hash * 31 + c;
    }
    return hash;
}

void buscarPorTitulo(const std::string& titulo) {
    int tituloHash = calcularHash(titulo);
    std::string resultado = indiceSecundario.search(tituloHash);
    if (resultado == "Key not found") {
        std::cout << "Registro com Título '" << titulo << "' não encontrado." << std::endl;
    } else {
        std::cout << "Registro encontrado: " << resultado << std::endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr,"Nº de argumentos inválido, precisa ser 1\n");
        exit(1);
    }

    char Titulo[301];
    strcpy(Titulo, argv[1]);
    buscarPorTitulo(Titulo);
    return 0;
}
