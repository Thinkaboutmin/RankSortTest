# Roda o programa x (tem que ser um rank sort) vezes enquanto passa
# tudo do output padrão para um arquivo log.
function executar_programa {
    local PROGRAMA=$1
    local VEZES=$2
    local LOG=$3
    local ARG1=$4
    local ARG2=$5

    local I=0
    while ((I != VEZES))
    do
        echo "$(./$PROGRAMA $ARG1 $ARG2) | $ARG1 $ARG2" >> "$LOG"
        ((++I))
    done

    return 0
}

# Número de elementos a ser realizado o ranksort.
NUMERO_ELEMENTOS=300000
VEZES=5

executar_programa "../rank_sort" $VEZES "rank_sort_linear.log" $NUMERO_ELEMENTOS


NUMERO_THREADS=(1 2 4 8 12 24)

for NUM_THREAD in $NUMERO_THREADS
do
    PTHREAD_LOG="rank_sort_pthread.log"
    OPENMP_LOG="rank_sort.openmp.log"
    executar_programa "../rank_sort_pthread" $VEZES "$PTHREAD_LOG" $NUM_THREAD $NUMERO_ELEMENTOS
    executar_programa "../rank_sort_openmp" $VEZES "$OPENMP_LOG" $NUM_THREAD $NUMERO_ELEMENTOS
done