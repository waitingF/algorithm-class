/*
求逆序对数

先写归并排序就很简单了，归并不会当我没说 
*/

#include<iostream>
using namespace std;

const int N = 20005;
int array[N];
int backup[N];
int reversePair;

void mergeSort(int l, int r) {
	if(l == r) {
		return;
	}
	int mid = (l + r) / 2;
	mergeSort(l, mid);
	mergeSort(mid+1, r);
	int i=l, j=mid+1;
	int k = l;
	while(i<=mid && j<=r) {
		if(array[i] > array[j]) {
			backup[k++] = array[j];
			j += 1;
			reversePair += mid-i+1;
		} else {
			backup[k++] = array[i];
			i += 1;
		} 
	}
	while(i<=mid) {
		backup[k++] = array[i];
		i += 1;
	}
	while(j<=r) {
		backup[k++] = array[j];
		j += 1;
	}
	for(int t=l; t<=r; t++) {
		array[t] = backup[t];
	}
}

int main() {
	int n;
	while(scanf("%d", &n)) {
		if(n == 0) {
			break;
		}
		
		for(int i=0; i<n; i++) {
			int tmp;
			scanf("%d", &tmp);
			array[i] = tmp;
		}
		
		reversePair = 0;
		mergeSort(0, n-1);
		printf("%d\n", reversePair);
	} 
	return 0;
}
