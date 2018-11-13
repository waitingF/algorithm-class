/*
D:最大子矩阵
*/

#include<iostream>
using namespace std;

const int N = 105;
int array[N][N];	// 下标定为从1开始 
int prefixSum[N][N];	// 前缀和数组 

int main() {
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> array[i][j];
		}
	}
	for(int i=0; i<n; i++) {
		prefixSum[i][0] = 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			prefixSum[i][j] += prefixSum[i][j-1] + array[i][j];
		}
	}
	
	int answer = 0;
	for(int leftColumn=0; leftColumn<=n; leftColumn++) {
		for(int rightColumn=leftColumn+1; rightColumn<=n; rightColumn++) {
			int tmpSum = 0;
			for(int row=1; row<=n; row++) {
				tmpSum += prefixSum[row][rightColumn] - prefixSum[row][leftColumn];
				if(tmpSum > answer) {
					answer = tmpSum;
				}
				if(tmpSum < 0) {
					tmpSum = 0;
				}
			}	
		}
	}
	
	cout << answer << endl;
	
	return 0;
}
