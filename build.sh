#! /bin/bash

echo "Criando pasta build"
mkdir build
cd build
echo "Gerando o make com cmake"
cmake -DCMAKE_CXX_FLAGS="-O3" -DCMAKE_BUILD_TYPE="Release" ..
echo "Compilando o programa"
make
mv rank_sort* ..
cd ..
echo "Build concluído"