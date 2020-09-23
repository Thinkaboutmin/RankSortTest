#include <chrono>

/*
 * Imprimi no output padrão a duração com o seguinte formato minutos:segundos:milisegundos.
 *
 * A duração pode ser obtida por operações entre time_points. A duração tem que ter tipo
 * de nanosegundos(1e9).
 */
void imprimirDuracao(std::chrono::duration<long, std::ratio<1, 1000000000>> duracao);