#pragma once
#include <iostream>
#include "Vetor.hpp"


using namespace std;

class HeapSort: public Vetor{

    public:
    
        void heapsort(int n) {
            int i = n / 2, pai, filho, t;
            while(true) {
                stats->comparar();
                if (i > 0) {
                    i--;
                    t = elements[i].key;
                } else {
                    n--;
                    stats->comparar();
                    if (n <= 0) return;
                    t = elements[n].key;
                    elements[n].key = elements[0].key;
                }
                pai = i;
                filho = i * 2 + 1;
                stats->comparar();
                while (filho < n) {
                    stats->comparar();
                    if ((filho + 1 < n)  &&  (elements[filho + 1].key > elements[filho].key)){
                        filho++;
                    }
                    stats->comparar();
                    if (elements[filho].key > t) {
                        elements[pai].key = elements[filho].key;
                        stats->trocar();
                        pai = filho;
                        filho = pai * 2 + 1;
                    } else {
                        break;
                    }
                    stats->comparar();
                }
                elements[pai].key = t;
            }
        }
        
        void Sort (char* saida)
        {    

            stats->comparar();
            if(size <= 1) return;

            heapsort(size);
            snapshot(saida);

        }

        HeapSort(int _tam, int seed){
            fill(_tam,seed,"HeapSort");
        }

        HeapSort(){}


};