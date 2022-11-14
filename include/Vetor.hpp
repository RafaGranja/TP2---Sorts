#pragma once
#include <iostream>
#include "Analisa.hpp"
#include <stdio.h>

using namespace std;

class Vetor{

    public:
        Analisa *stats;
        int *elements;
        int size;
        void fill(int _tam,int seed, string tipo){

            this->stats = new Analisa(tipo,_tam);
            stats->iniciaTime();
            this->elements = new int[_tam];
            this->size=_tam;
            srand(seed);
            
            for(int i = 0; i < size; i++){
                elements[i] = rand();
            }   

        }
        
        void swap (const int i, const int j)
        {
            int k = elements[i];
            elements[i] = elements[j];
            elements[j] = k;
            stats->trocar();
        }

        void snapshot (char* saida)
        {   
            FILE *arq;
            char Str[500];

            arq = fopen(saida, "a");  // Cria um arquivo texto para gravação
            if (arq == NULL) // Se não conseguiu criar
            {
                cout << "Problemas na CRIACAO do arquivo de saida" << endl;
                return;
            }
            
            stats->terminaTime();
            // cout << "[";
            // for(auto i = 0; i < size; i++) {
            //     cout << elements[i] << ", ";
            // }
            // cout << "]" << endl;
            strcpy(Str,stats->imprime().c_str());
            fputs(Str, arq);

            fclose(arq);
        }
};
