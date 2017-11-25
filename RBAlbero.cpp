// ------------------------------------------------------------
// Salvatore Campisi
// C++ PROGRAMMING
// Anno Accademico 2016/2017
// Argomento: Strutture Dati : Albero Rosso-Nero
// ------------------------------------------------------------
#include <iostream>
using namespace std;

template <class T>
class Nodo{
  //Attributes:
  private:
    T key;
    short int color;
    Nodo<T>* left;
    Nodo<T>* right;
    Nodo<T>* padre;
  //Methods:
  public:
    Nodo(T temp){
      key = temp;
      color = 1;
      //Setting Pointers:
      left = NULL; right = NULL; padre = NULL;
    }
    //Setters:
    void setKey(T temp){ key = temp; }
    void setColor(short int temp){
      if(temp != 0 && temp != 1){ cout << "Error Setting Color"; return; }
      color = temp;
    }
    void setLeft(Nodo<T>* temp){ left = temp; }
    void setRight(Nodo<T>* temp){ right = temp; }
    void setPadre(Nodo<T>* temp){ padre = temp; }
    //Getters:
    T getKey(){ return key; }
    short int getColor(){ return color; }
    Nodo<T>* getLeft(){ return left; }
    Nodo<T>* getRight(){ return right; }
    Nodo<T>* getPadre(){ return padre; }
};

template <class T>
class RBAlbero{
  private:
    Nodo<T>* radice;
  public:
    RBAlbero(){ radice = NULL; }
    //Rotazioni:
    void leftRotate(Nodo<T>* temp){
      Nodo<T>* z = temp->getPadre();
      Nodo<T>* x = temp->getRight();
      if(x == NULL) return;
      temp->setRight(x->getLeft());
      if(temp->getRight() != NULL) temp->getRight()->setPadre(temp);
      x->setLeft(temp);
      if(z == NULL){ radice = x; temp->setPadre(x); x->setPadre(NULL); return; }
      if(temp == z->getRight()) z->setRight(x);
      else z->setLeft(x);
      temp->setPadre(x);
      x->setPadre(z);
      return;
    }
    void rightRotate(Nodo<T>* temp){
      Nodo<T>* z = temp->getPadre();
      Nodo<T>* x = temp->getLeft();
      if(x == NULL) return;
      temp->setLeft(x->getRight());
      if(temp->getLeft() != NULL) temp->getLeft()->setPadre(temp);
      x->setRight(temp);
      if(z == NULL){ radice = x; temp->setPadre(x); x->setPadre(NULL); return; }
      if(temp == z->getRight()) z->setRight(x);
      else z->setLeft(x);
      temp->setPadre(x);
      x->setPadre(z);
      return;
    }
    //Violazione Proprietà:
    void RBInsertFixup(Nodo<T>* temp){
      short int B = 0;
      short int R = 1;
      if(temp == radice){ temp->setColor(B); return; }
      if(temp->getPadre()->getColor() == B) return;
      //Nodi di Supporto:
      Nodo<T>* padre = temp->getPadre();
      Nodo<T>* nonno = padre->getPadre();
      Nodo<T>* zio = nonno->getRight();
      if(padre == nonno->getRight()) zio = nonno->getLeft();
      //Caso 1:
      if(zio != NULL && zio->getColor() == R){
        padre->setColor(B);
        zio->setColor(B);
        nonno->setColor(R);
        RBInsertFixup(nonno);
        return;
      }
      //Caso 2/3:
      if(padre == nonno->getLeft()){
        if(temp == padre->getRight()){
          leftRotate(padre);
          padre = temp;
          temp = padre->getLeft();
        }
        rightRotate(nonno);
        padre->setColor(B);
        nonno->setColor(R);
        return;
      }
      if(padre == nonno->getRight()){
      if(temp == padre->getLeft()){
        rightRotate(padre);
        padre = temp;
        temp = padre->getRight();
      }
      leftRotate(nonno);
      padre->setColor(B);
      nonno->setColor(R);
      return;
    }
  }
  //Inserimento:
  void insert(T val){
    Nodo<T>* temp = new Nodo<T>(val);
    if(radice == NULL){ radice = temp; RBInsertFixup(temp); return; }
    Nodo<T>* app = NULL;
    Nodo<T>* aux = radice;
    while(aux != NULL){
      app = aux;
      if(val < aux->getKey()) aux = aux->getLeft();
      else aux = aux->getRight();
    }
    if(val < app->getKey()) app->setLeft(temp);
    else app->setRight(temp);
    temp->setPadre(app);
    RBInsertFixup(temp);
    return;
  }
  //Procedure di Stampa:
  void inorder(Nodo<T>* temp){
    if(temp == NULL) return;
    inorder(temp->getLeft());
    if(temp->getColor() == 0) cout << temp->getKey() << "(B) ";
    else cout << temp->getKey() << "(R) ";
    inorder(temp->getRight());
  }
  void print(){
    cout << "RBAlbero:  ";
    inorder(radice);
    cout << endl;
  }
};

int main(){
  system("clear");

  //TESTING ROUTINE:
  RBAlbero<int>* albero = new RBAlbero<int>();
  albero->insert(66);
  albero->insert(18);
  albero->insert(67);
  albero->insert(26);
  albero->insert(25);
  albero->insert(48);
  albero->insert(22);
  albero->insert(28);
  albero->insert(35);
  albero->print();
  //OUTPUT CORRETTO: 18(B) 22(R) 25(R) 26(B) 28(B) 35(R) 48(B) 66(R) 67(B)

  return 0;
}
