cmake_minimum_required(VERSION 3.0.0)
project(rank_sort VERSION 0.1.0)

add_executable(
    rank_sort
    src/rank_sort.cpp
    src/gerar_lista_sorteada.cpp
    src/linear_rank_sort.cpp
    src/imprimir_duracao.cpp
)

find_library(PTHREAD pthread REQUIRED)
project(rank_sort_pthread VERSION 0.1.0)
add_executable(
    rank_sort_pthread
    src/rank_sort.cpp
    src/gerar_lista_sorteada.cpp
    src/rank_sort_pthread.cpp
    src/pthread_rank_sort.cpp
    src/imprimir_duracao.cpp
    )
target_link_libraries(rank_sort_pthread ${PTHREAD})

project(rank_sort_openmp)
find_package(OpenMP REQUIRED)
add_executable(
    rank_sort_openmp
    src/rank_sort.cpp
    src/gerar_lista_sorteada.cpp
    src/rank_sort_openmp.cpp
    src/openmp_rank_sort.cpp
    src/imprimir_duracao.cpp
)
target_link_libraries(rank_sort_openmp OpenMP::OpenMP_CXX)