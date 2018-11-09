/*
C:Percolation
描述
定义一个N行N列的矩阵，矩阵中的每个元素是个方格，每个方格有两种可能的状态：开通的或关闭的。初始时，所有方格都是关闭的。输入数据的每一步会指定矩阵中某个原来关闭的方格变成开通的。要求编写程序判断当前是否存在从矩阵中最上面一行的任何一个开着的方格走到最下面一行的任何一个开着的方格的路径。如果存在的话，输出当前的步数。比如走到第14步时，矩阵变成上下通透的，那么就输出14。注意：输入数据中只会把矩阵中的一部分方格打开。如果所有步骤都执行完了，矩阵仍然不是上下通透的，那么输出-1。显然，矩阵变成上下通透的一个必要条件是：最上面一行和最下面一行都至少要有一个方格是打开的。

在矩阵中行走时，只能横着走或竖着走，不能斜着走，也不能走出矩阵的边界。

输入
输入的第一行是一个自然数T(1≤T≤10)，代表测试数据的组数。每组测试数据的第一行有两个自然数N和M，其中N（1≤N≤1,000）代表方阵的维度，M（1≤M≤N*N）代表本组测试中打开的方格数目。随后的M行中每行有两个自然数，分别代表所打开的方格的行、列下标。注意：本题中矩阵的下标从1开始，即所有下标的取值都是[1, N]区间中的正整数。

输出
每组测试数据输出一个自然数K，表示打开第K个方格后，矩阵变成上下通透的。如果M个方格都打开后，矩阵仍然不是上下通透的，那么输出-1。

样例输入
1
4 10 
2 2
3 1
4 2
4 4
1 2
2 3
2 1
3 2
3 4
3 1
样例输出
8
*/

#include<iostream>
using namespace std;

const int N = 1005;
const int M = N * N;
int father[M];

int findFather(int node) {
	if(father[node] != node) {
		father[node] = findFather(father[node]);
		return father[node];
	}
	return father[node];
}

void uion(int x, int y) {
	int fatherX = findFather(x);
	int fatherY = findFather(y);
	if (fatherX != fatherY) {
		father[fatherY] = fatherX;
	} 
}

int position(int x, int y, int n) {
	return (x-1) * n + y;
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		bool pass = false;
		for(int i=0; i<=n*n+1; i++) {
			father[i] = -1;
		}
		for(int i=1; i<=m; i++) {
//			for(int j=0; j<=n*n+1; j++) {
//				printf("%d ", father[j]);
//			}
//			printf("\n");
			int x, y;
			scanf("%d %d", &x, &y);
			int pos = position(x, y, n);
			father[pos] = pos;
			if(!pass) {
				if(pos <= n) { // 第一行 
					if(father[0] == -1) {
						father[0] = 0;
					} 
					uion(pos, 0);
				}
				if(pos > n*(n-1)) { // 最后一行 
					if(father[n*n+1] == -1) {
						father[n*n+1] = n*n + 1;
					}
					uion(pos, n*n+1);
				}
				
				if(0<position(x-1, y, n) && position(x-1, y, n)<=n*n && father[position(x-1, y, n)]!=-1) {
					uion(pos, position(x-1, y, n));
				}
				if(0<position(x+1, y, n) && position(x+1, y, n)<=n*n && father[position(x+1, y, n)]!=-1) {
					uion(pos, position(x+1, y, n));
				}
				if(0<position(x, y-1, n) && position(x, y-1, n)<=n*n && father[position(x, y-1, n)]!=-1) {
					uion(pos, position(x, y-1, n));
				}
				if(0<position(x, y+1, n) && position(x, y+1, n)<=n*n && father[position(x, y+1, n)]!=-1) {
					uion(pos, position(x, y+1, n));
				}
				
				if(father[0]!=-1 && father[n*n+1]!=-1 && findFather(0)==findFather(n*n+1)) {
					pass = true;
					printf("%d\n", i);
				}
			}
		}
		if(!pass) {
			printf("-1\n");
		}
		
	}
	
	return 0;
}


