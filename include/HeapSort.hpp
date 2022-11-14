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
                    t = elements[i];
                } else {
                    n--;
                    stats->comparar();
                    if (n <= 0) return;
                    t = elements[n];
                    elements[n] = elements[0];
                }
                pai = i;
                filho = i * 2 + 1;
                stats->comparar();
                while (filho < n) {
                    stats->comparar();
                    if ((filho + 1 < n)  &&  (elements[filho + 1] > elements[filho])){
                        filho++;
                    }
                    stats->comparar();
                    if (elements[filho] > t) {
                        elements[pai] = elements[filho];
                        stats->trocar();
                        pai = filho;
                        filho = pai * 2 + 1;
                    } else {
                        break;
                    }
                    stats->comparar();
                }
                elements[pai] = t;
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