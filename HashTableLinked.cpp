// ------------------------------------------------------------
// Salvatore Campisi
// C++ PROGRAMMING
// Anno Accademico 2016/2017
// Argomento: Strutture Dati : Linked Hash Table
// ------------------------------------------------------------
#include <iostream>
using namespace std;

template <class T>
class Nodo{
    private:
		T key;
		Nodo<T>* next;
	public:
		Nodo(T temp){ key = temp; next = NULL; }
		//Setters:
		void setKey(T _key){ key = _key; }
		void setNext(Nodo<T>* temp){ next = temp; }
		//Getters:
		T getKey(){ return key; }
		Nodo<T>* getNext(){ return next; }
};

template <class T>
class Lista{
	private:
		Nodo<T>* head;
	public:
		Lista(){ head = NULL; }
		void insert(T val){
			Nodo<T>* temp = new Nodo<T>(val);
			if(head == NULL){ head = temp; return; }
			temp->setNext(head);
			head = temp;
			return;
		}
		bool search(T val){
			Nodo<T>* supp = head;
			while(supp != NULL){
				if(supp->getKey() == val) return true;
				else supp = supp->getNext();
			}
			return false;
		}
		void del(T val){
			if(search(val) == false) return;
			if(head->getKey() == val){ Nodo<T>* temp = head; head = head->getNext(); delete temp; return; }
			Nodo<T>* supp = head;
			Nodo<T>* app = supp;
			while(supp->getNext() != NULL){
				app = supp;
				supp = supp->getNext();
				if(supp->getKey() == val){
					app->setNex(supp->getNext());
					delete supp;
					return;
				}
			}
			if(supp->getKey() == val){
				app->setNext(supp->getNext());
				delete supp;
				return;
			}
			return;
		}
		void print(){
			Nodo<T>* temp = head;
			if(temp == NULL){ cout << "Empty List" << endl; return; }
			while(temp != NULL){
				cout << temp->getKey() << " -> ";
				temp = temp->getNext();
			}
			cout << "NULL" << endl;
		}
};

template <class T>
class THLinkata{
	private:
		Lista<T>* array;
		int dim;
	public:
		THLinkata(int temp){
			dim = temp;
			array = new Lista<T>[dim];
		}
		int getDim(){ return dim; }
		void insert(T val){
			int j = hash(val);
			array[j].insert(val);
			return;
		}
		Lista<T>* search(T val){
			int j = hash(val);
			if(array[j].search(val) == true){ cout << "Element is present in the List at position " << j << endl; return &array[j]; }
			else return NULL;
		}
		void del(T val){
			int j = hash(val);
			if(array[j].search(val) == true) array[j].del(val);
			else return;
		}
		void print(){
			cout << "\nTABELLA HASH: " << endl;
			for(int k = 0; k<dim; k++){ cout << "Posizione [" << k << "] : ";  array[k].print(); }
		}
		//Da implementare nella sottoclasse:
		virtual int hash(T val) = 0;
};

template <class T>
class DivTHLinkata : public THLinkata<T>{
	private:
		int hash(T val){ return ((int)val) % this->getDim(); }
	public:
		DivTHLinkata(int temp) : THLinkata<T>(temp){}
};

int main(){
	system("clear");

	//TESTING ROUTINE:
	DivTHLinkata<int> mioHash(7);
	mioHash.print();
	mioHash.insert(7);
	mioHash.insert(14);
	mioHash.insert(21);
	mioHash.insert(16);
	mioHash.insert(15);
	mioHash.insert(8);
	mioHash.print();
	mioHash.search(8);

	cout << endl;
	return 0;
}
