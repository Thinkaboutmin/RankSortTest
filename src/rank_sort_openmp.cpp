#include <omp.h>
#include "rank_sort_openmp.h"
#include "rank_sort.h"

/*
 * Cria as threads e roda a operação de sorteamento.
 *
 * A principal diferença aqui entre a utilização do pthread é o
 * sugar syntax omp loop. Ele gerencia a lista fazendo com que os
 * threads concorram por ela sem necessitar gerenciar os trabalhos
 * a serem realizados.
 */
std::vector<size_t> sortear_openmp(const std::vector<size_t> & lista, size_t & thread_num) {
    std::vector<size_t> lista_sorteada(lista.size());

    // Muito mais rápido de se fazer assim...
    #pragma omp parallel num_threads(thread_num)
    {
        #pragma omp for
        for (size_t i = 0; i < lista.size(); ++i) {
            computar_lista(lista, lista_sorteada, lista[i]);
        }
    }

    return lista_sorteada;
}
