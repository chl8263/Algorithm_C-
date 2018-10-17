#include<iostream>

using namespace std;


void merge(int data [] , int dataSize, int p , int q , int r) {
	
	int i = p; 
	int j = q;
	int k = p;
	int *temp = (int *)malloc(dataSize*sizeof(int));
	
	while (i<=q && j<=r) {
		if (data[i] <= data[j]) {
			temp[k++] = data[i++];
		}
		else if(data [i] >= data[j]) {
			temp[k++] = data[j++];
		}
	}
	while (i <= q) {
		temp[k++] = data[i++];
	}
	while (j <= r) {
		temp[k++] = data[j++];
	}
	for (int i = p; i < r; i++) {
		data[i] = temp[i];
	}

	//free(temp);

}

bool mergesort(int data[] , int p , int r) {
	
	int dataSize = sizeof(data) / sizeof(int);
	if (p >= r) return true;
	
	if (p < r) {
		int q = (p + r) / 2;
		mergesort(data , p , q);
		mergesort(data, q + 1, r);
		merge(data , dataSize, p , q , r);
	}
}


int main() {
	int data[] = {123,25,234,54,37,235,7,2311,2};
	int dataSize = sizeof(data) / sizeof(int);
	//cout << dataSize;
	if (mergesort(data, 0, 7)) {
		for (int i = 0; i < dataSize; i++) {
			cout << data[i] << " ,";
		}
	}
		
}