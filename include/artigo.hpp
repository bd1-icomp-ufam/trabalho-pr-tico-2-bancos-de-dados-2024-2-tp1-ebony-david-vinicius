    #ifndef ARTIGO_H
    #define ARTIGO_H

    //
    // Estrutura de data e hora para representar quando um artigo foi atualizado.
    typedef struct {
        char dia;   // Dia da atualização (1-31)
        char mes;   // Mês da atualização (1-12)
        short ano;  // Ano da atualização

        char seg;   // Segundo da atualização (0-59)
        char min;   // Minuto da atualização (0-59)
        char hora;  // Hora da atualização (0-23)
    } data_hora;

    // Estrutura de um artigo científico.
    typedef struct {
        int id;                         // Identificador único do artigo
        char titulo[301];               // Título do artigo com espaço para 300 caracteres + '\0'
        int ano;                        // Ano de publicação do artigo
        char autores[151];              // Lista de autores do artigo com espaço para 150 caracteres + '\0'
        int citacoes;                   // Número de vezes que o artigo foi citado
        data_hora atualizacao;          // Data e hora da última atualização do artigo
        char resumo[1025];              // Resumo do artigo com espaço para 1024 caracteres + '\0'
    } artigo;

    artigo csv_para_artigo(const char* linha);
    void imprime_artigo(artigo& a);

    #endif // ARTIGO_H
