// ------------------------------------------------------------
// Salvatore Campisi
// C++ PROGRAMMING
// Anno Accademico 2016/2017
// Argomento: Algoritmi di Ordinamento : Merge Sort
// ------------------------------------------------------------
#include <iostream>
using namespace std;

template <class T>
void mergesort(T v[], int low, int high);
template <class T>
void merge(T v[], int low, int mid, int high);

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
void mergesort(T v[], int low, int high) {
	if( low<high ) {
		int mid = (low+high)/2;
		mergesort( v, low, mid );
		mergesort( v, mid+1, high );
		merge( v, low, mid, high );
 	}
}
template <class T>
void merge(T v[], int low, int mid, int high) {
	T b[50];
	int h = low;
	int i = low;
	int j = mid+1;

	while( (h<=mid) && (j<=high) ) {
		if( v[h] <= v[j] ) b[i] = v[h++];
		else b[i] = v[j++];
  		i++;
	}
 	if(h>mid)
  		for(int k=j; k<=high; k++) b[i++]=v[k];
 	else
		for(int k=h; k<=mid; k++) b[i++]=v[k];
 	for(int k=low; k<=high; k++) v[k]=b[k];
}

int main () {
	int v[10] = {3,6,7,2,1,8,4,9,5,0};
	stampa(v,10);
	mergesort(v,0,9);
	stampa(v,10);
	return 0;
}
