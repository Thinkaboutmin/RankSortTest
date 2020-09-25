#include <vector>

/*
 * Sorteia um tipo vector de forma não deterministica.
 */
std::vector<size_t> sortear_openmp(const std::vector<size_t> & lista, size_t & thread_num);