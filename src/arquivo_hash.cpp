#include "arquivo_hash.hpp"
#include "constantes.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>


ArquivoHash::ArquivoHash(const char *arquivo, int num_buckets, Modo modo) {
  static_assert(sizeof(Bucket) < tamanho_bloco);
  this->num_buckets = num_buckets;
  this->fp = fopen(arquivo, modo_de(modo));
  if (modo == Modo::escrita) {
    preenche_buckets();
  }
}


void ArquivoHash::preenche_buckets() {
    Bucket vazio;
    for(int i = 0; i < num_buckets; i++) {
        fseek(this->fp, i * tamanho_bloco, SEEK_SET);
        fwrite(&vazio, sizeof(Bucket), 1, this->fp);
    }
}

size_t ArquivoHash::funcao_hash(int id) {
    return id % this->num_buckets;
}

void ArquivoHash::insere(int id, off_t offset) {
    size_t id_bucket = funcao_hash(id);
    Bucket bucket;
    fseek(fp, id_bucket * tamanho_bloco, SEEK_SET);
    fread(&bucket, sizeof(Bucket), 1, fp);
    if(bucket.tamanho == Bucket::MAX_ENTRADAS) {
        printf("erro: bucket #%lu não consegue ter mais nenhuma entrada\n", id_bucket);
        return;
    }
    bucket.entradas[bucket.tamanho++] = Entrada{.id = id, .offset = offset};
    fseek(fp, id_bucket * tamanho_bloco, SEEK_SET);
    fwrite(&bucket, sizeof(Bucket), 1, fp);
}

off_t ArquivoHash::busca(int id) {
    size_t id_bucket = funcao_hash(id);
    Bucket bucket;
    fseek(fp, id_bucket * tamanho_bloco, SEEK_SET);
    fread(&bucket, sizeof(Bucket), 1, fp);
    for(int i = 0; i < bucket.tamanho; i++) {
        if(bucket.entradas[i].id == id) {
            return bucket.entradas[i].offset;
        }
    }
    return NAO_ENCONTRADO;
}
