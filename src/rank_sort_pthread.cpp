#include <cmath>
#include <thread>
#include <utility>

#include "rank_sort_pthread.h"
#include "rank_sort.h"

/*
 * Realiza as operações de sorteamento baseado no rank.
 * 
 * Cada thread funciona de forma independente ou seja temos threads
 * não determinísticas.
 */
void computar_lista_pthread(const std::vector<size_t> & lista_comp, std::vector<size_t> & lista, std::pair<size_t, size_t> * alcance) {
    for (size_t i = alcance->first; i < alcance->second; ++i) {
        computar_lista(lista_comp, lista, lista_comp[i]);
    }

    delete alcance;
}

/*
 * Cria as threads e roda a operação de sorteamento.
 *
 * Cada thread recebe um valor de trabalho, esse valor de trabalho
 * é a divisão do número de elementos pelo número de threads. Essa
 * operação é truncada para não haver erros de conversão.
 *
 * Caso falte algum elemento, divisão quebrada, ele é realizado pela thread principal
 * junto da parte definida para as outras threads afinal, ela é uma thread também...
 */
std::vector<size_t> sortear_pthread(const std::vector<size_t> & lista,size_t & thread_num) {
    std::vector<size_t> lista_sorteada(lista.size());

    // Segura outras threads menos a principal.
    std::vector<std::thread *> threads(thread_num - 1);
    size_t thread_workload = std::trunc(lista.size() / thread_num);
    size_t available_work = 0;
    for (auto & thread : threads) {
        auto alcance = new std::pair<size_t, size_t>(
            available_work,
            available_work + thread_workload
        );
    
        thread = new std::thread(computar_lista_pthread, std::ref(lista), std::ref(lista_sorteada), alcance);

        available_work += thread_workload;
    }

    // Resgata elementos faltando.
    size_t missing_work = lista.size() - (thread_workload * thread_num);
    thread_workload += missing_work;
    auto alcance = new std::pair<size_t, size_t>(
        available_work,
        available_work + thread_workload
    );
    computar_lista_pthread(lista, lista_sorteada, alcance);

    // Sincroniza as threads e retira elas do heap.
    for (auto thread : threads) {
        thread->join();
        delete thread;
    }
    
    return lista_sorteada;
}