#include <chrono>
#include <algorithm>
#include <random>

#include "gerar_lista_sorteada.h"

std::vector<size_t> gerarListaSorteada(size_t numero_de_elementos) {
    const size_t & num = numero_de_elementos;

    std::vector<size_t> lista(numero_de_elementos);
    size_t contador = 0;
    for (auto & elemento : lista) {
        elemento = contador;
        ++contador;
    }

    std::random_shuffle(lista.begin(), lista.end());

    return lista;
}