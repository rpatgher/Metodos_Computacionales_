//
//  main.cpp
//  ExamenPrueba
//
//  Created by Remy Patgher on 01/10/23.
//

#include <iostream>

using namespace std;

class Nodo{
public:
    int valor;
    Nodo *siguiente;
    Nodo *anterior;
};

class ListaCircular{
private:
    Nodo *inicio;
    Nodo *fin;
    
public:
    ListaCircular(){
        inicio = NULL;
        fin = NULL;
    }
    
    int listaVacia(){
        if(inicio == NULL && fin == NULL)
            return 1;
        return 0;
    }
    
    void insertarFinal(int num){
        cout << "Nuevo Elemento al final: " << num << endl;
        Nodo *elemento = new Nodo();
        if(listaVacia() == 1){
            elemento->valor = num;
            elemento->siguiente = elemento;
            elemento->anterior = elemento;
            inicio = elemento;
            fin = elemento;
        }else{
            elemento->valor = num;
            elemento->siguiente = inicio;
            elemento->anterior = fin;
            fin->siguiente = elemento;
            inicio->anterior = elemento;
            fin = elemento;
        }
    }
    
    void insertarInicio(int num){
        cout << "Nuevo Elemento al inicio: " << num << endl;
        Nodo *elemento = new Nodo();
        if(listaVacia() == 1){
            elemento->valor = num;
            elemento->siguiente = elemento;
            elemento->anterior = elemento;
            inicio = elemento;
            fin = elemento;
        }else{
            elemento->valor = num;
            elemento->siguiente = inicio;
            elemento->anterior = fin;
            inicio->anterior = elemento;
            fin->siguiente = elemento;
            inicio = elemento;
        }
    }
    
    void eliminaFinal(){
        if(listaVacia() == 1){
            cout << "No se puede eliminar porque la lista está vacía" << endl;
            return;
        }
        cout << "Elemento " << fin->valor << " eliminado" << endl;
        Nodo *temporal = fin;
        fin = fin->anterior;
        fin->siguiente = inicio;
        inicio->anterior = fin;
        delete temporal;
    }
    
    void buscar(int num){
        Nodo *indice = inicio;
        int i = 1, b = 0;
        do{
            if(indice->valor == num){
                cout << "Elemento " << indice->valor << " en posición: " << i << endl;
                b++;
            }
            indice = indice->siguiente;
            i++;
        }while(indice != inicio);
        if(b == 0)
            cout << "Elemento " << num << " no encontrado" << endl;
    }
    void mostrarElementos(){
        Nodo *indice = inicio;
        int i = 0;
        cout << "|";
        do{
            cout << "\t" << indice->valor << "\t|";
            indice = indice->siguiente;
            i++;
        }while(indice != inicio);
        cout << endl;
    }
};


int main() {
    ListaCircular Lista;
    Lista.insertarFinal(2);
    Lista.insertarFinal(4);
    Lista.insertarFinal(5);
    Lista.insertarInicio(3);
    Lista.mostrarElementos();
    Lista.buscar(5);
    Lista.buscar(2);
    Lista.buscar(2);
    Lista.buscar(6);
    Lista.eliminaFinal();
    Lista.mostrarElementos();
    
    return 0;
}
