#include <iostream>
#include <time.h>
#include <stdio.h>
#include "../include/QuicksortRecursivo.hpp"
#include "../include/QuicksortMediana.hpp"
#include "../include/QuicksortSelecao.hpp"
#include "../include/QuicksortNaoRecursivo.hpp"
#include "../include/QuicksortEmpilha.hpp"
#include "../include/MergeSort.hpp"
#include "../include/HeapSort.hpp"

using namespace std;

int main(int argc, char *argv[]){

    FILE *arq;
    int v,k,m,s,size;
    string *param = new string[argc];
    char *entrada;
    char *saida;
    char Linha[100];

    for(int i = 0; i < argc; i++){

        param[i]=argv[i];

    }


    for(int i = 0; i < argc; i++){

        if (param[i]=="-v")
        {
            v = stoi(param[i+1]);
            i++;
        }
        if (param[i]=="-k")
        {   
            k = stoi(param[i+1]);
            i++;
        }
        if (param[i]=="-s")
        {   
            s = stoi(param[i+1]);
            i++;
        }
        if (param[i]=="-m")
        {   
            m = stoi(param[i+1]);
            i++;
        }
        if (param[i]=="-i")
        {
            entrada = argv[i+1];
            i++;
        }
        if (param[i]=="-o")
        {
            saida =  argv[i+1];
            i++;
        }

    }   

    // Abre um arquivo TEXTO para LEITURA
    arq = fopen(entrada, "rt");
    if (arq == NULL)  // Se houve erro na abertura
    {
        cout << "Problemas na abertura do arquivo de entrada" << endl;
        return 0;
    }

    if(v==1){

        QuicksortRecursivo quicksort;

        FILE *arq2;
        char Str[500] = "------------------------- QuicksortRecursivo -------------------------------------- \n";

        arq2 = fopen(saida, "a");  // Cria um arquivo texto para gravação
        if (arq2 == NULL) // Se não conseguiu criar
        {
            cout << "Problemas na CRIACAO do arquivo de saida" << endl;
            return 0;
        }
        fputs(Str, arq2);

        fclose(arq2);

        while (!feof(arq))
        {

            fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
            size=atoi(Linha);
            quicksort = QuicksortRecursivo(size,s);
            quicksort.Sort(saida);

        }
        
    }
    if(v==2){

        QuicksortMediana quicksort;

        FILE *arq2;
        char Str[500] = "------------------------- QuicksortMediana -------------------------------------- \n";

        arq2 = fopen(saida, "a");  // Cria um arquivo texto para gravação
        if (arq2 == NULL) // Se não conseguiu criar
        {
            cout << "Problemas na CRIACAO do arquivo de saida" << endl;
            return 0;
        }
        fputs(Str, arq2);

        fclose(arq2);

        while (!feof(arq))
        {

            fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
            size=atoi(Linha);
            quicksort = QuicksortMediana(size,s);
            quicksort.Sort(saida);

        }

    }
    if(v==3){

        QuicksortSelecao quicksort;

        FILE *arq2;
        char Str[500] = "------------------------- QuicksortSelecao -------------------------------------- \n";

        arq2 = fopen(saida, "a");  // Cria um arquivo texto para gravação
        if (arq2 == NULL) // Se não conseguiu criar
        {
            cout << "Problemas na CRIACAO do arquivo de saida" << endl;
            return 0;
        }
        fputs(Str, arq2);

        fclose(arq2);

        while (!feof(arq))
        {

            fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
            size=atoi(Linha);
            quicksort = QuicksortSelecao(size,s);
            quicksort.Sort(m,saida);

        }

    }
    if(v==4){

        QuicksortNaoRecursivo quicksort;

        FILE *arq2;
        char Str[500] = "------------------------- QuicksortNaoRecursivo -------------------------------------- \n";

        arq2 = fopen(saida, "a");  // Cria um arquivo texto para gravação
        if (arq2 == NULL) // Se não conseguiu criar
        {
            cout << "Problemas na CRIACAO do arquivo de saida" << endl;
            return 0;
        }
        fputs(Str, arq2);

        fclose(arq2);

        while (!feof(arq))
        {

            fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
            size=atoi(Linha);
            quicksort = QuicksortNaoRecursivo(size,s);
            quicksort.Sort(saida);

        }

    }
    if(v==5){

        QuicksortEmpilha quicksort;

        FILE *arq2;
        char Str[500] = "------------------------- QuicksortEmpilha -------------------------------------- \n";

        arq2 = fopen(saida, "a");  // Cria um arquivo texto para gravação
        if (arq2 == NULL) // Se não conseguiu criar
        {
            cout << "Problemas na CRIACAO do arquivo de saida" << endl;
            return 0;
        }
        fputs(Str, arq2);

        fclose(arq2);

        while (!feof(arq))
        {

            fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
            size=atoi(Linha);
            quicksort = QuicksortEmpilha(size,s);
            quicksort.Sort(saida);

        }
        
    }
    if(v==6){

        HeapSort quicksort;

        FILE *arq2;
        char Str[500] = "------------------------- HeapSort -------------------------------------- \n";

        arq2 = fopen(saida, "a");  // Cria um arquivo texto para gravação
        if (arq2 == NULL) // Se não conseguiu criar
        {
            cout << "Problemas na CRIACAO do arquivo de saida" << endl;
            return 0;
        }
        fputs(Str, arq2);

        fclose(arq2);

        while (!feof(arq))
        {

            fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
            size=atoi(Linha);
            quicksort = HeapSort(size,s);
            quicksort.Sort(saida);

        }
        
    }
    if(v==7){

        MergeSort quicksort;

        FILE *arq2;
        char Str[500] = "------------------------- MergeSort -------------------------------------- \n";

        arq2 = fopen(saida, "a");  // Cria um arquivo texto para gravação
        if (arq2 == NULL) // Se não conseguiu criar
        {
            cout << "Problemas na CRIACAO do arquivo de saida" << endl;
            return 0;
        }
        fputs(Str, arq2);

        fclose(arq2);

        while (!feof(arq))
        {

            fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
            size=atoi(Linha);
            quicksort = MergeSort(size,s);
            quicksort.Sort(saida);

        }
        
    }

    fclose(arq);

    return 0;

}