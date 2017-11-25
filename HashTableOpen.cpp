// ------------------------------------------------------------
// Salvatore Campisi
// C++ PROGRAMMING
// Anno Accademico 2016/2017
// Argomento: Strutture Dati : Open Hash Table
// ------------------------------------------------------------
#include <iostream>
using namespace std;

template <class T>
class HashTableOpen{
  private:
    T* array;
    int dim;
    //Costante per contrassegnare locazioni vuote:
    static const short int NULLO = -1;
    //Costante per contrassegnare locazioni eliminate:
    static const short int DELETED = -2;
  public:
    HashTableOpen(int temp){
      dim = temp;
      array = new T[dim];
      for(int i = 0; i<dim; i++) array[i] = NULLO;
    }
    int getDim(){ return dim; }
    void insert(T val){
      int i = 0;
      while(i < dim){
        int j = hash(val,i);
        if(array[j] == NULLO || array[j] == DELETED){
          array[j] = val;
          cout << "Element " << val << " hash been correctly inserted" << endl;
          return;
        }
        i++;
      }
      cout << "Error, Hash Table Full" << endl;
    }
    void del(T val){
      int i = 0;
      while(i < dim){
        int j = hash(val,i);
        if(array[j] == val){
          array[j] = DELETED;
          cout << "Element " << val << " hash been correctly eliminated" << endl;
          return;
        }
        i++;
      }
      cout << "Error, Element is not in the Hash Table" << endl;
    }
    bool search(T val){
      int i = 0;
      while(i < dim){
        int j = hash(val,i);
        if(array[j] == val){ cout << "Element " << val << " is present in the Hash Table" << endl; return true; }
        i++;
      }
      cout << "Element you searched is not in the Hash Table" << endl;
      return false;
    }
    void print(){
      cout << endl << "HASH TABLE:  ";
      for(int k = 0; k<dim; k++) cout << array[k] << "  ";
      cout << endl;
    }
    //Da implementare nelle classi ereditanti:
    virtual int hash(T val, int i) = 0;
};

template <class T>
class LinearHashTableOpen : public HashTableOpen<T>{
  private:
    int hash(T val, int i){	return ((int)val + i) % this->getDim(); }
  public:
    LinearHashTableOpen(int temp) : HashTableOpen<T>(temp){}
};
template <class T>class QuadraticHashTableOpen : public HashTableOpen<T>{
  private:
    int c1,c2;
    int hash(T val, int i){	return ((int)val + c1*i + c2*(i*i)) % this->getDim(); }
  public:
    QuadraticHashTableOpen(int temp, int _c1, int _c2) : HashTableOpen<T>(temp){ c1 = _c1; c2 = _c2; }
};

int main(){
  system("clear");

  //TESTING ROUTINE:
  LinearHashTableOpen<int> tabella(5);
  tabella.insert(3);
  tabella.insert(15);
  tabella.insert(25);
  tabella.insert(35);
  tabella.insert(5);
  tabella.print();
  //TESTING ROUTINE:
  QuadraticHashTableOpen<int> tab(5,5,2);
  tab.insert(3);
  tab.insert(15);
  tab.insert(25);
  tab.insert(4);
  tab.insert(1);
  tab.print();

  return 0;
}
