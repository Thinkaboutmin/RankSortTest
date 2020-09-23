#include <iostream>

#include "imprimir_duracao.h"

void imprimirDuracao(std::chrono::duration<long, std::ratio<1, 1000000000>> duracao) {
    using minutes = std::chrono::minutes;
    using seconds = std::chrono::seconds;
    using milliseconds = std::chrono::milliseconds;

    auto duration_minutes = std::chrono::duration_cast<minutes>(duracao).count();
    auto duration_total_seconds = std::chrono::duration_cast<seconds>(duracao).count() ;
    auto duration_seconds = duration_total_seconds - (duration_minutes * 60);
    // Devemos utilizar o total senão estaremos deixando os valores dos minutos.
    auto duration_milliseconds = std::chrono::duration_cast<milliseconds>(duracao).count() - (duration_total_seconds * 1000);

    std::cout << duration_minutes << ":"
        << duration_seconds << ":"
        << duration_milliseconds;
}