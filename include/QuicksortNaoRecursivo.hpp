#pragma once
#include "Vetor.hpp"
#include "Pilha.hpp"

using namespace std;


class QuicksortNaoRecursivo : public Vetor{

    public:
        void Particao(int Esq, int Dir,int *i, int *j){
           
            int x, w;
            *i = Esq; *j = Dir;
            x = elements[(*i + *j)/2]; /* obtem o pivo x */
            
            do{
                while (x > elements[*i]) (*i)++;
                while (x < elements[*j]) (*j)--;
                stats->comparar();
                if (*i <= *j){
                    swap(*i,*j);
                    (*i)++; (*j)--;
                }
            } while (*i <= *j);
        }

        void QuickSortNaoRec()
        {
            Pilha pilha;
            Item item; // campos esq e dir
            int esq, dir, i, j;
            pilha.IniciaPilha();
            esq = 0;
            dir = size-1;
            item.dir = dir;
            item.esq = esq;
            pilha.Empilha(item);
            do{
                stats->comparar();
                if (dir > esq) {
                    Particao(esq,dir,&i, &j);
                    stats->comparar();
                    if ((j-esq)>(dir-i)) {

                        item.dir = j;
                        item.esq = esq;
                        pilha.Empilha(item);
                        esq = i;

                    }
                    else {

                        item.esq = i;
                        item.dir = dir;
                        pilha.Empilha(item);
                        dir = j;

                    }
                }
                else {

                    item=pilha.Desempilha();
                    dir = item.dir;
                    esq = item.esq;
                    stats->trocar();
                }
                stats->comparar();
            } while (!pilha.Vazia());
        } 

        void Sort (char* saida)
        {    
            stats->comparar();
            if(size <= 1) return;
            QuickSortNaoRec();
            snapshot(saida);

        }

        QuicksortNaoRecursivo(int _tam, int seed){
            fill(_tam,seed,"QuicksortNaoRecursivo");
        } 

        QuicksortNaoRecursivo(){}

};