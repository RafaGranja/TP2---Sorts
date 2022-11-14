#pragma once
#include <iostream>
#include <time.h>
#include <string.h>


using namespace std;

class Analisa{

    public:

        clock_t inicio,fim;
        int compara=0;
        int trocas=0;
        string tipo;
        int size;

        void iniciaTime(){
            inicio = clock();
        }

        void terminaTime(){
            fim = clock();
        }

        string imprime(){
            string ret;
            ret = tipo + " " + to_string(size) +"\n"
            + "TEMPO DE EXECUÇÃO: " +  to_string((double)(fim - inicio) / CLOCKS_PER_SEC) + "\n" +
            + "NUMERO DE COMPARACOES: " + to_string(compara) + "\n" 
            + "NUMERO DE TROCAS: " + to_string(trocas) + "\n"
            + " ------------------------------------------- \n";
            return ret;
        }

        void comparar(){
            compara++;
        }

        void trocar(){
            trocas++;
        }

        void reseta(){
            inicio=0;
            fim=0;
            compara=0;
        }

        Analisa(string _tipo, int _size){
            tipo=_tipo;
            size=_size;
        }
    
};