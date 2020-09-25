#include <algorithm>
#include "rank_sort.h"

void computar_lista(const std::vector<size_t> & lista_comp, std::vector<size_t> & lista, size_t elem_to_rank) {
    size_t rank = 0;
    for (auto elemento : lista_comp) {
        if (elem_to_rank > elemento) {
            ++rank;
        }
    }

    lista[rank] = elem_to_rank;
}

std::vector<size_t> sortear(const std::vector<size_t> & lista) {
    std::vector<size_t> lista_sorteada(lista.size());

    for (const size_t & elemento : lista) {
        computar_lista(lista, lista_sorteada, elemento);
    }

    return lista_sorteada;
}
