#ifndef ARQUIVO_HASH_HPP
#define ARQUIVO_HASH_HPP
#include <cstddef>
#include <cstdio>
#include <limits>

#include "constantes.hpp"
//
//ajuda escrever e ler o arquivo hash
class ArquivoHash {
  FILE *fp;
  int num_buckets;

public:
  constexpr static off_t NAO_ENCONTRADO = std::numeric_limits<off_t>::max();
  struct Entrada {
    int id;
    off_t offset;
  } __attribute__((packed));
  struct Bucket {
    // -2 pra garantir que vai tudo caber em um bloco
    constexpr static size_t MAX_ENTRADAS = (tamanho_bloco / sizeof(Entrada)) - 2;
    size_t tamanho = 0;
    Entrada entradas[MAX_ENTRADAS];
  };
  enum Modo { escrita, leitura };

  const char *modo_de(Modo m) {
    if (m == Modo::escrita)
      return "wb+";
    if (m == Modo::leitura)
      return "rb";
    return "";

  }
  //declaração construtor
  ArquivoHash(const char *arquivo, int num_buckets, Modo modo);

  void preenche_buckets();

  size_t funcao_hash(int id);

  void insere(int id, off_t offset);

  off_t busca(int id);
};

#endif
