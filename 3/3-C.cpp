/*
C:公共子序列

描述
我们称序列Z = < z1, z2, ..., zk >是序列X = < x1, x2, ..., xm >的子序列当且仅当存在 严格上升 的序列< i1, i2, ..., ik >，使得对j = 1, 2, ... ,k, 有xij = zj。比如Z = < a, b, f, c > 是X = < a, b, c, f, b, c >的子序列。

现在给出两个序列X和Y，你的任务是找到X和Y的最大公共子序列，也就是说要找到一个最长的序列Z，使得Z既是X的子序列也是Y的子序列。

输入
输入包括多组测试数据。每组数据包括一行，给出两个长度不超过200的字符串，表示两个序列。两个字符串之间由若干个空格隔开。

输出
对每组输入数据，输出一行，给出两个序列的最大公共子序列的长度。

样例输入
abcfbc         abfcab
programming    contest 
abcd           mnp

样例输出
4
2
0
*/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 205;
char X[N];
char Y[N];
int LCS[N][N];

int main() {
	while(scanf("%s %s", X, Y)!=-1) {
		int lenX = strlen(X);
		int lenY = strlen(Y);
		for(int i=0; i<=lenX; i++) {
			LCS[i][0] = 0;
		}
		for(int j=0; j<=lenY; j++) {
			LCS[0][j] = 0;
		}
		
		for(int i=1; i<=lenX; i++) {
			for(int j=1; j<=lenY; j++) {
				if(X[i-1] == Y[j-1]) {
					LCS[i][j] = LCS[i-1][j-1]+1;
				} else {
					LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
				}
			}
		}
		
		printf("%d\n", LCS[lenX][lenY]);
	}
}




