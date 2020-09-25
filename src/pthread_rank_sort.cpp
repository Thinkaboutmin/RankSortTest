#include <iostream>
#include <string>
#include <chrono>

#include "gerar_lista_sorteada.h"
#include "rank_sort_pthread.h"
#include "imprimir_duracao.h"


int main(int argc, char ** argv) {
    if (argc == 1) {
        std::cerr << "Não foi passado o número de threads para executar o ranksort.";
        return 1;
    } else if (argc == 2) {
        std::cerr << "Não foi passado o número de elementos da lista a ser sorteada.";
        return 1;
    }

    size_t thread_number = 0;
    try {
        thread_number = std::stoi(argv[1]);
    } catch (std::invalid_argument error) {
        std::cerr << "Não foi possível compreender o valor " << argv[1] << " para o número de threads";
        return 1;
    } catch(std::out_of_range error) {
        std::cerr << "O número de threads foi muito grande.";
        return 1;
    }

    size_t elementos_lista = 0;
    try {
        elementos_lista = std::stoi(argv[2]);
    } catch (std::invalid_argument error) {
        std::cerr << "Não foi possível compreender o valor " << argv[2] << " para o número de elementos";
        return 1;
    } catch(std::out_of_range error) {
        std::cerr << "O número de elementos foi muito grande.";
        return 1;
    }


    std::vector<size_t> lista = gerarListaSorteada(elementos_lista);

    auto inicio = std::chrono::steady_clock::now();
    std::vector<size_t> lista_sorteada = sortear_pthread(lista, thread_number);
    auto fim = std::chrono::steady_clock::now();

    imprimirDuracao(fim - inicio);

    return 0;
}