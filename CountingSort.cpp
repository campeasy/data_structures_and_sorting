// ------------------------------------------------------------
// Salvatore Campisi
// C++ PROGRAMMING
// Anno Accademico 2016/2017
// Argomento: Algoritmi di Ordinamento : Counting Sort
// ------------------------------------------------------------
#include <iostream>
using namespace std;

void stampaVettore(int* pointer, int dim){
	for(int i = 1; i<=dim; i++) cout << pointer[i] << " ";
	cout << endl;
}

void CountingSort(int* arrayTemp, int dimTemp){
	int max = arrayTemp[0];
	for(int i = 1; i<dimTemp; i++){ if(arrayTemp[i] > max) max = arrayTemp[i]; }
	int dimC = max+1;
	int* c = new int[dimC];
	for(int i = 0; i<dimC; i++) c[i] = 0;
	for(int i = 0; i<dimTemp; i++) c[arrayTemp[i]]++;
	for(int i = 1; i<dimC; i++) c[i]+=c[i-1];
	int* b = new int[dimTemp];
	for(int i = 0; i<dimTemp; i++){
		b[c[arrayTemp[i]]] = arrayTemp[i];
		c[arrayTemp[i]]--;
	}
	arrayTemp = b;
	stampaVettore(arrayTemp,dimTemp);
}

int main(){
	system("clear");
	int v[10] = {16,15,34,39,101,2,87,49,58,67};
	int* puntatore = v;
	CountingSort(puntatore,10);
	return 0;
}
