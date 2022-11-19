#pragma once
#include "Vetor.hpp"

using namespace std;

class QuicksortSelecao : public Vetor{

    public:

        int partition(int inicio, int fim, int part) {

            int separa = ((inicio + fim)%part)+inicio;
            int a = elements[inicio].key;
            int b = elements[separa].key;
            int c = elements[fim].key;
            int separaIndice; 
            
            stats->comparar();
            if (a < b) {
                stats->comparar();
                if (b < c) {
                    //a < b && b < c
                    separaIndice = separa;
                } else {
                    stats->comparar();
                    if (a < c) {
                        //a < c && c <= b
                        separaIndice = fim;
                    } else {
                        //c <= a && a < b
                        separaIndice = inicio;
                    }
                }
            } else {
                stats->comparar();
                if (c < b) {
                    //c < b && b <= a
                    separaIndice = separa;
                } else {
                    stats->comparar();
                    if (c < a) {
                        //b <= c && c < a
                        separaIndice = fim;
                    } else {
                        //b <= a && a <= c
                        separaIndice = inicio;
                    }
                }
            }
            //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
            swap(separaIndice, fim);
                
            //*******************ALGORITMO DE PARTIÇÃO DE CORMEN*********************
            //o pivo é o elemento final
            int pivo = elements[fim].key;
            int i = inicio - 1;
            int j;
            /*
            * Este laço irá varrer os vetores da esquerda para direira
            * procurando os elementos que são menores ou iguais ao pivô.
            * Esses elementos são colocados na partição esquerda.         
            */
            for (j = inicio; j <= fim - 1; j++) {
                stats->comparar();
                if (elements[j].key <= pivo) {
                    i = i + 1;
                    swap(i, j);
                }
            }
            //coloca o pivô na posição de ordenação
            swap(i + 1, fim);
            return i + 1; //retorna a posição do pivô
        }

        /*
         * Método privado que implementa o Quicksort recursivamente
         */
        void quicksort (const int start, const int end, int part)
        {

            stats->comparar();
            if (start >= end) return;

            int pivot = partition(start, end, part);

            quicksort(start, pivot - 1, part);
            quicksort(pivot + 1, end, part);

        }

        void Sort (const int part,char* saida)
        {    

            stats->comparar();
            if(size <= 1) return;

            quicksort(0, size,part);
            snapshot(saida);

        }

        QuicksortSelecao(int _tam, int seed){
            fill(_tam,seed, "QuicksortSelecao");
        }

        QuicksortSelecao(){}

};