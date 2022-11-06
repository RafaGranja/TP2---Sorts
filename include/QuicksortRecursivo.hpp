#pragma once
#include "Vetor.hpp"

using namespace std;

class QuicksortRecursivo : public Vetor{
        
    public:
        int partition (const int start, const int end)
        {
            int i = start;

            for (int j = start; j < end; j++) {
                stats->comparar();
                /*  Elemento atual menor ou igual ao pivô? */
                if (elements[j] <= elements[end]) {
                    swap(i++, j);
                }
            }
            swap(i, end);

            return i;
        }

        /**
         * Método privado que implementa o Quicksort recursivamente
         */
        void quicksort (const int start, const int end)
        {
            stats->comparar();
            if (start >= end) return;

            int pivot = partition(start, end);

            quicksort(start, pivot - 1);
            quicksort(pivot + 1, end);
        }
        
        void Sort (char* saida)
        {    
            stats->comparar();
            if(size <= 1) return;

            quicksort(0, size);
            snapshot(saida);

        }

        QuicksortRecursivo(int _tam, int seed){
            fill(_tam,seed, "QuicksortRecursivo");
        }

        QuicksortRecursivo(){}

};