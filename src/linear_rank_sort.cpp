#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

#include "gerar_lista_sorteada.h"
#include "rank_sort.h"
#include "imprimir_duracao.h"

void imprimirLista(const std::vector<size_t> & lista) {
    constexpr unsigned short max_inline = 20;
    unsigned short inline_elems = 0;
    for (size_t elemento : lista) {
        std::cout << elemento << "\n";
    }
}

int main(int argc, char ** argv) {
    if (argc == 1) {
        std::cerr << "Não foi passado o número de elementos para executar o ranksort.";
        return 1;
    }

    size_t elementos_lista = 0;
    try {
        elementos_lista = std::stoi(argv[1]);
    } catch (std::invalid_argument error) {
        std::cerr << "Não foi possível compreender o valor " << argv[1] << " para o número de elementos";
        return 1;
    } catch(std::out_of_range error) {
        std::cerr << "O número de elementos foi muito grande.";
        return 1;
    }

    
    std::vector<size_t> lista = gerarListaSorteada(elementos_lista);
    auto inicio = std::chrono::steady_clock::now();
    std::vector<size_t> lista_sorteada = sortear(lista);
    auto fim = std::chrono::steady_clock::now();

    imprimirDuracao(fim - inicio);    

    return 0;
}