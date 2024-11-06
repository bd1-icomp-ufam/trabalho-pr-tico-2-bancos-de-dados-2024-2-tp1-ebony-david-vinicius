#include "artigo.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>

//fun auxiliar, copia os primeiros 'tam' caracteres de src pro dest e adiciona um \0 no fim
void copia(char* dest, const char* src, int tam) {
    if(tam > 0)
        strncpy(dest, src, tam);
    else tam = 0;
    dest[tam] = '\0';
}

//pega o dado da coluna e bota em dest 
int pega_conteudo(const char *comeco_coluna, char* dest) {
    int pos = 0;
    int aspas = 0;
    char ultimo = '\0';
    while(true) {
        if(comeco_coluna[pos]=='\0') break;
        if(comeco_coluna[pos]==';' && (aspas == 0 || (ultimo == '"' && aspas % 2 == 0))) {
            break;
        }
        if(comeco_coluna[pos]=='"') aspas++;
        ultimo = comeco_coluna[pos++];
    }
    copia(dest, comeco_coluna + 1, pos - 2 - (comeco_coluna[pos] == '\0' ? 2 : 0));
    return pos + 1;
}

artigo csv_para_artigo(const char *linha){
    artigo a;

    char strint[40];
    auto tam = pega_conteudo(linha,strint);
    a.id = atoi(strint);

    tam += pega_conteudo(linha+tam,a.titulo);

    tam += pega_conteudo(linha+tam,strint);
    a.ano = atoi(strint);

    tam += pega_conteudo(linha+tam,a.autores);

    tam += pega_conteudo(linha+tam,strint);
    a.citacoes = atoi(strint);

    char str_data_hora[50];
    tam += pega_conteudo(linha+tam, str_data_hora);
    auto& att = a.atualizacao;
    sscanf(str_data_hora, "%hd-%hhd-%hhd %hhd:%hhd:%hhd", &att.ano, &att.mes, &att.dia, &att.hora, &att.min, &att.seg);

    tam += pega_conteudo(linha+tam,a.resumo);

    return a;
}

void imprime_artigo(artigo& a) {
    printf("ID: %d\n", a.id);
    printf("Titulo: %s\n", a.titulo);
    printf("Ano: %d\n", a.ano);
    printf("Autores: %s\n", a.autores);
    printf("Citacoes: %d\n", a.citacoes);
    auto& att = a.atualizacao;
    printf("Última Atualização: %hd/%hhd/%hhd %hhd:%hhd:%hhd\n", att.ano, att.mes, att.dia, att.hora, att.min, att.seg);
    printf("Resumo: %s\n", a.resumo);
}
