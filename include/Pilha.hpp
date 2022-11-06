#pragma once
#include <iostream>

class Item
{   
    public:
        int esq;
        int dir;

};

class Lista{

    public:
        Item data;
        Lista *prox;    

};

class Pilha{

    public:
        Lista *lista;


        void IniciaPilha(){

            lista = new Lista;

        }

        int Vazia(){

            if(lista == NULL){

                return 1;   // true

            }
            else{

                return 0;   // false

            }
        }

        void Empilha (Item v){
            
            if(Vazia()){
                lista->data=v;
            }else{

                Lista *aux = new Lista;
                aux->data=v;
                aux->prox=lista;
                lista=aux;

            }

        }

        Item Desempilha (){

            Item ret = lista->data;
            Lista *aux = lista;
            lista=lista->prox;
            delete aux;
            return ret;

        }

};

