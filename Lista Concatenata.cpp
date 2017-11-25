// ------------------------------------------------------------
// Salvatore Campisi
// C++ PROGRAMMING
// Anno Accademico 2016/2017
// Argomento: Strutture Dati : Lista Concatenata
// ------------------------------------------------------------
#include <iostream>
using namespace std;

template <class H>
class Nodo{
  private:
    H valore;
    Nodo<H>* next;
  public:
    Nodo(H temp){ valore = temp; next = NULL; }
    //Setters:
    void setValore(H temp){ valore = temp; }
    void setNext(Nodo<H>* succ){ next = succ; }
    //Getters:
    H getValore(){ return valore; }
    Nodo<H>* getNext(){ return next; }
};

template <class H>
class Lista{
  private:
    Nodo<H>* head;
  public:
    Lista(){ head = NULL; }
    void insert(H val){
      Nodo<H>* temp = new Nodo<H>(val);
      //Caso 0: Lista Vuota
      if(head == NULL){ head = temp; return; }
      //Caso 1: Inserimento in testa
      if(val < head->getValore()){ temp->setNext(head); head = temp; return; }
      //Caso 2: Inserimento ordinato:
      Nodo<H>* app = head;
      while(app->getNext()!=NULL){
        if(val >= app->getValore() && val < app->getNext()->getValore()){ temp->setNext(app->getNext()); app->setNext(temp); return; }
        app = app->getNext();
      }
      app->setNext(temp);
      //Se non è mai stato effetuato un return precedentemente, vuol dire che deve essere effettuato un inserimento in coda.
    }
    void del(H val){
      if(head == NULL){ return; }
      Nodo<H>* temp = ricerca(val);
      if(temp == NULL){ delete temp; return; }
      if(val == head->getValore()){
        temp = head; head = head->getNext();
        delete temp; return;
      }
      temp = head;
      while(temp->getNext()!=NULL){
        if(val == temp->getNext()->getValore()){
          Nodo<H>* aux = temp->getNext();
          temp->setNext(aux->getNext());
          delete aux;
          return;
        }
        temp = temp->getNext();
      }
      temp = NULL;
    }
    Nodo<H>* ricerca(H val){
      if(head == NULL){ return NULL; }
      Nodo<H>* temp = head;
      while(temp != NULL){
        if(temp->getValore() == val){ return temp; }
        temp = temp->getNext();
      }
      return NULL;
    }
    void print(){
      if(head == NULL){ cout << "Lista Vuota." << endl; return; }
      Nodo<H>* temp = head;
      while(temp != NULL){
        cout << temp->getValore() << " → ";
        temp = temp->getNext();
      }
      cout << "NULL" << endl;
    }
  };

int main(){
    system("clear");
    Lista<int> lista;
    lista.insert(5);
    lista.insert(1);
    lista.insert(12);
    lista.insert(12);
    lista.insert(12);
    lista.insert(7);
    lista.insert(15);
    lista.insert(8);
    lista.print();

    lista.del(5);
    lista.del(1);
    lista.del(12);
    lista.del(15);
    lista.print();

    return 0;
}
