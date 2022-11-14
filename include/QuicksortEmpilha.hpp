#pragma once
#include "Vetor.hpp"
#include "Pilha.hpp"


using namespace std;

class QuicksortEmpilha : public Vetor{

    public:
        void Particao(int Esq, int Dir,int *i, int *j){
           
            int x, w;
            *i = Esq; *j = Dir;
            x = elements[(*i + *j)/2]; /* obtem o pivo x */
            
            do{
                stats->comparar();
                while (x > elements[*i]){
                    stats->comparar();
                    (*i)++;
                }
                stats->comparar();
                while (x < elements[*j]){ 
                    stats->comparar();
                    (*j)--;
                }
                stats->comparar();
                if (*i <= *j){
                    swap(*i,*j);
                    (*i)++; (*j)--;
                }
                stats->comparar();
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
                    if ((j-esq)<(dir-i)) {

                        item.dir = j;
                        item.esq = esq;
                        stats->comparar();
                        pilha.Empilha(item);
                        esq = i;

                    }
                    else {

                        item.esq = i;
                        item.dir = dir;
                        stats->comparar();
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

        QuicksortEmpilha(int _tam, int seed){
            fill(_tam,seed,"QuicksortEmpilha");
        } 

        QuicksortEmpilha(){}
        

};