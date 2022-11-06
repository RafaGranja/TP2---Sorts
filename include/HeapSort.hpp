#pragma once
#include <iostream>
#include "Vetor.hpp"


using namespace std;

class HeapSort: public Vetor{

    public:
    
        void heap(int Esq, int Dir){
            int i, j;
            int x;
            i = Esq;
            j = i * 2;
            x = elements[i];
            stats->comparar();
            while (j <= Dir){
                stats->comparar();
                stats->comparar();
                stats->comparar();
                stats->comparar();
                if (j < Dir) 
                if (elements[j] < elements[j+1]) j++;
                if (x >= elements[j]) break;
                elements[i] = elements[j];
                i = j;
                j = i *2;
            }
            
            elements[i] = x;
        }

        void heapSort(int n) {
            int Esq;
            Esq = n / 2 + 1;
            stats->comparar();
            while (Esq > 1) {
                stats->comparar();
                Esq--;
                heap(Esq, n);
            }
        }
        
        void Sort (char* saida)
        {    

            if(size <= 1) return;

            heapSort(size-1);
            snapshot(saida);

        }

        HeapSort(int _tam, int seed){
            fill(_tam,seed,"HeapSort");
        }

        HeapSort(){}


};