// ------------------------------------------------------------
// Salvatore Campisi
// C++ PROGRAMMING
// Anno Accademico 2016/2017
// Argomento: Strutture Dati : Albero Binario
// ------------------------------------------------------------
#include <iostream>
using namespace std;

template <class H>
class Nodo{
  private:
    H valore;
    Nodo<H>* padre;
    Nodo<H>* left;
    Nodo<H>* right;
  public:
    Nodo(H temp){ valore = temp; padre = NULL; left = NULL; right = NULL; }
    //Setters:
    void setValore(H temp)      { valore = temp; }
    void setPadre(Nodo<H>* temp){ padre  = temp; }
    void setLeft(Nodo<H>* temp) { left   = temp; }
    void setRight(Nodo<H>* temp){ right  = temp; }
    //Getters:
    H getValore()      { return valore; }
    Nodo<H>* getPadre(){ return padre;  }
    Nodo<H>* getLeft() { return left;   }
    Nodo<H>* getRight(){ return right;  }
};

template <class H>
class Albero{
  private:
    Nodo<H>* radice;
  public:
    Albero(){ radice = NULL; }
    // INSERIMENTO:
    void insert(H val){
      Nodo<H>* temp = new Nodo<H>(val);
      //Caso 0: Albero Vuoto
      if(radice == NULL){ radice = temp; return; }
      //Caso 1: Albero Non Vuoto
      Nodo<H>* app = NULL;
      Nodo<H>* aux = radice;
      while(aux != NULL){
        app = aux;
        if(temp->getValore() < aux->getValore()) aux = aux->getLeft();
        else aux = aux->getRight();
      }
      if(temp->getValore() < app->getValore()) app->setLeft(temp);
      else app->setRight(temp);
      temp->setPadre(app);
      return;
    }
    // ELIMINAZIONE:
    void del(H val){
      Nodo<H>* temp = ricerca(val);
      //Caso 0: Non esiste
      if(temp == NULL){ delete temp; return; }
      //Caso 1: Figli entrambi nulli
      if(temp->getLeft()==NULL && temp->getRight()==NULL){
        Nodo<H>* p = temp->getPadre();
        if(p == NULL){ radice = NULL; delete temp; return; }
        if(temp == p->getLeft()){ p->setLeft(NULL); delete temp; return; }
        if(temp == p->getRight()){ p->setRight(NULL); delete temp; return; }
      }
      //Caso 2: Nessun figlio nullo
      if(temp->getLeft()!=NULL && temp->getRight()!=NULL){
        H k = (successore(temp))->getValore();
        del(k);
        temp->setValore(k);
        return;
      }
      //Caso 3: Solo un figlio
      Nodo<H>* p = temp->getPadre();
      Nodo<H>* f = temp->getLeft();
      if(f == NULL){ f = temp->getRight(); }
      if(p == NULL){ radice = f; delete temp; return; }
      else{
        if(temp == p->getLeft()) p->setLeft(f);
        if(temp == p->getRight()) p->setRight(f);
        f->setPadre(p);
        delete temp;
        return;
      }
      if(temp == p->getLeft()){ p->setLeft(f); f->setPadre(p); delete temp; return; }
      if(temp == p->getRight()){ p->setRight(f); f->setPadre(p); delete temp; return; }
    }
    // RICERCA:
    Nodo<H>* ricerca(H val){
      Nodo<H>* aux = radice;
      while(aux != NULL){
        if(val == aux->getValore()) return aux;
        if(val < aux->getValore()) aux = aux->getLeft();
        else aux = aux->getRight();
      }
      return NULL;
    }
    // METODI DI SUPPORTO:
    Nodo<H>* minimo(Nodo<H>* start){
      Nodo<H>* app = start;
      Nodo<H>* aux = start;
      while(aux != NULL){
        app = aux;
        aux = aux->getLeft();
      }
      return app;
    }
    Nodo<H>* successore(Nodo<H>* temp){
      if(temp->getRight() == NULL){ return NULL; }
      Nodo<H>* toreturn = minimo(temp->getRight());
      return toreturn;
    }
    // STAMPA:
    void inorder(Nodo<H>* temp){
      if(temp){
        inorder(temp->getLeft());
        cout << temp->getValore() << "\t";
        inorder(temp->getRight());
      }
    }
    void print(){ cout << endl; inorder(radice); cout << endl; }
};

int main(){
  system("clear");

  Albero<int> intree;
  intree.insert(5);
  intree.insert(1);
  intree.insert(17);
  intree.insert(3);
  intree.print();
  intree.del(5);
  intree.print();

  Albero<float> fltree;
  fltree.insert(5.3);
  fltree.insert(1.3);
  fltree.insert(13.3);
  fltree.insert(2.1);
  fltree.insert(3.8);
  fltree.print();
  fltree.del(1.3);
  fltree.print();

  return 0;
}
