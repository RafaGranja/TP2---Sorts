#pragma once
#include "Vetor.hpp"


using namespace std;

class QuicksortMediana : public Vetor{

    public:

        int partition(int inicio, int fim) {
            //procura a mediana entre inicio, meio e fim
            int meio = (inicio + fim) / 2;
            int a = elements[inicio].key;
            int b = elements[meio].key;
            int c = elements[fim].key;
            int medianaIndice; //índice da mediana
            //A sequência de if...else a seguir verifica qual é a mediana
            stats->comparar();
            if (a < b) {
                stats->comparar();
                if (b < c) {
                    //a < b && b < c
                    medianaIndice = meio;
                } else {
                    if (a < c) {
                        //a < c && c <= b
                        medianaIndice = fim;
                    } else {
                        //c <= a && a < b
                        medianaIndice = inicio;
                    }
                }
            } else {
                stats->comparar();
                if (c < b) {
                    //c < b && b <= a
                    medianaIndice = meio;
                } else {
                    stats->comparar();
                    if (c < a) {
                        //b <= c && c < a
                        medianaIndice = fim;
                    } else {
                        //b <= a && a <= c
                        medianaIndice = inicio;
                    }
                }
            }
            //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
            swap(medianaIndice, fim);
                
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
        //Quicksort mediana de três
        void quicksort(int inicio, int fim) {
            stats->comparar();
            if (inicio < fim) {
                //realiza a partição
                int q = partition(inicio, fim);
                //ordena a partição esquerda
                quicksort(inicio, q - 1);
                //ordena a partição direita
                quicksort(q + 1, fim);
            }
        }

        void Sort (char* saida)
        {    
            stats->comparar();
            if(size <= 1) return;

            quicksort(0, size);
            snapshot(saida);

        }

        QuicksortMediana(int _tam, int seed){
            fill(_tam,seed, "QuicksortSelecao");
        }

        QuicksortMediana(){}

};