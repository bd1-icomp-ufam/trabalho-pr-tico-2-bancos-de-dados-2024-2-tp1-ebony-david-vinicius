#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP
#include <cstdint>

//ATENÇÃO AO PROX COMENTÁRIO PFV
// mudar pro tamanho do bloco na máquina(getconf PAGESIZE)
constexpr static int32_t tamanho_bloco = 4096;

constexpr static int numero_buckets = 20010*1024/tamanho_bloco;

static const char* nome_arquivo_dados = "arquivos/dados.bin";
static const char* nome_arquivo_hash = "arquivos/hash.bin";
//
#endif
