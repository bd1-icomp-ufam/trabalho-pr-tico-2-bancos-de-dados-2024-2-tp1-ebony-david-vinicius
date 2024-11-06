// arquivo findrec
//
#include <cstdio>
#include <cstdlib>

#include "arquivo_hash.hpp"
#include "artigo.hpp"
#include "constantes.hpp"

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("número de argumentos incorreto.\n");
        exit(1);
    }
    auto id_buscado = atoi(argv[1]);
    
    ArquivoHash arquivo_hash(nome_arquivo_hash, numero_buckets, ArquivoHash::Modo::leitura);

    off_t offset_do_dado_no_arquivo_de_dados = arquivo_hash.busca(id_buscado);
    int blocos_lidos = 1;

    artigo artigo_buscado;
    FILE* fp = fopen(nome_arquivo_dados, "rb");

    if(offset_do_dado_no_arquivo_de_dados == ArquivoHash::NAO_ENCONTRADO) {
        printf("id não encontrrado!");
        goto fim;
    }

    fseek(fp, offset_do_dado_no_arquivo_de_dados, SEEK_SET);

   
    fread(&artigo_buscado, sizeof(artigo), 1, fp);
    blocos_lidos++;
    if (offset_do_dado_no_arquivo_de_dados/tamanho_bloco != (offset_do_dado_no_arquivo_de_dados+sizeof(artigo)-1)/tamanho_bloco){
        blocos_lidos++;
    }
    imprime_artigo(artigo_buscado);

    printf("buscou com sucesso\n");
    fim:
    printf("nº de blocos lidos: %d\n",blocos_lidos);
    return 0;
}
