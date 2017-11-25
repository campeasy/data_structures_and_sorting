// ------------------------------------------------------------
// Salvatore Campisi
// C++ PROGRAMMING
// Anno Accademico 2016/2017
// Argomento: Strutture Dati : Heap
// ------------------------------------------------------------
#include <iostream>
using namespace std;

template <class T>
class MaxHeap{
	private:
		T* heap;
		//Puntatore alla prima locazione di memoria
		int heapsize;
		//Elementi memorizzati
		int dim;
		//Elementi memorizzabili
		static const short int UNDEFINED = -1;
		//Utile per settare la prima locazione di memoria che resterà inutilizzata
	public:
		MaxHeap(int temp){
			heapsize = 0;
			dim = temp+1;
			heap = new T[dim];
			heap[0] = UNDEFINED;
		}
		int left(int i){ return 2*i; }
		int right(int i){ return (2*i)+1; }
		int padre(int i){ return i/2; }
		void swap(int i, int j){ T app = heap[i]; heap[i] = heap[j]; heap[j] = app; return; }
		void heapify(int temp){
			if(temp > heapsize){ cout << "Error" << endl; return; }
			int l = left(temp);
			int r = right(temp);
			int bigger = temp;
			if(l <= heapsize && heap[l] > heap[temp]) bigger = l;
			if(r <= heapsize && heap[r] > heap[bigger]) bigger = r;
			if(bigger != temp){
				swap(bigger, temp);
				heapify(bigger); }
				return;
		}
		void buildHeap(){
			for(int k = heapsize/2; k>=1; k--) heapify(k);
		}
		void put(T temp){
			if(heapsize == dim-1){ cout << "Error, Full Heap" << endl; return; }
			heapsize++;
			heap[heapsize] = temp;
			buildHeap();
		}
		T take(){
			if(heapsize == 0){ cout << "Error, Heap is Empty" << endl; return UNDEFINED; }
			T temp = heap[1];
			swap(1,heapsize);
			heapsize--;
			heapify(1);
			return temp;
		}
		void print(){
			for(int k = 1; k<=heapsize; k++) cout << heap[k] << "[" << k << "]" << " ";
			cout << endl;
		}
		void heapsort(){
			int tempHeapsize = heapsize;
			for(int k=heapsize; k>1; k--){
				swap(1,heapsize);
				heapsize--;
				heapify(1);
			}
			cout << "HEAPSORT:  ";
			for(int k=1; k<=tempHeapsize; k++) cout << heap[k] << "  ";
			cout << endl;
		}
};

int main(){
	system("clear");

	//TESTING ROUTINE:
	MaxHeap<int> testHeap(7);
	testHeap.put(59);
	testHeap.put(1);
	testHeap.put(76);
	testHeap.put(35);
	testHeap.put(35);
	testHeap.put(23);
	testHeap.print();
	testHeap.take();
	testHeap.print();
	testHeap.heapsort();
	cout << endl << endl;

	return 0;
}
