// ------------------------------------------------------------
// Salvatore Campisi
// C++ PROGRAMMING
// Anno Accademico 2016/2017
// Argomento: Algoritmi di Ordinamento : Quick Sort
// ------------------------------------------------------------
#include <iostream>
using namespace std;

template <class T>
void quicksort(T v[], int top, int bottom);
template <class T>
int partition(T v[], int top, int bottom);

template <class T>
void inline scambia(T v[], int x, int y){
	T t = v[x];
	v[x] = v[y];
	v[y] = t;
}
template <class T>
void stampa(T v[], int n){
	for(int i=0; i<n; i++) {
		cout << v[i] << " ";
	}
	cout << endl << endl;
}
template <class T>
void quicksort(T v[], int top, int bottom) {
	int middle;
	if (top < bottom) {
		middle = partition(v, top, bottom);
		quicksort(v, top, middle);   				// sort top partition
		quicksort(v, middle+1, bottom);    	// sort bottom partition
    }
	return;
}
template <class T>
int partition(T v[], int top, int bottom) {
	T x = v[top];
	int i = top - 1;
    int j = bottom + 1;
    do {
    	do j--;
		while (x < v[j]);
        do i++;
        while (x > v[i]);
        if (i < j) scambia(v, i, j);
	} while (i < j);
    return j;
}

int main () {
	int v[10] = {3,6,7,2,1,8,4,9,5,0};
	stampa(v,10);
	quicksort(v,0,9);
	stampa(v,10);
	return 0;
}
