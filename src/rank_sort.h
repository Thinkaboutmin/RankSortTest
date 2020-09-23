#include <vector>

/*
 * Sorteia lista de forma linear com o uso do ranksort.
 */
std::vector<size_t> sortear(const std::vector<size_t> lista);

/*
 * Realiza operações do ranksort na lista em relação a lista_comp utilizando o elem_to_rank.
 */
void computar_lista(const std::vector<size_t> & lista_comp, std::vector<size_t> & lista, size_t elem_to_rank);