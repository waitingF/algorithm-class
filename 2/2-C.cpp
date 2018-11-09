/*
C:Percolation
����
����һ��N��N�еľ��󣬾����е�ÿ��Ԫ���Ǹ�����ÿ�����������ֿ��ܵ�״̬����ͨ�Ļ�رյġ���ʼʱ�����з����ǹرյġ��������ݵ�ÿһ����ָ��������ĳ��ԭ���رյķ����ɿ�ͨ�ġ�Ҫ���д�����жϵ�ǰ�Ƿ���ڴӾ�����������һ�е��κ�һ�����ŵķ����ߵ�������һ�е��κ�һ�����ŵķ����·����������ڵĻ��������ǰ�Ĳ����������ߵ���14��ʱ������������ͨ͸�ģ���ô�����14��ע�⣺����������ֻ��Ѿ����е�һ���ַ���򿪡�������в��趼ִ�����ˣ�������Ȼ��������ͨ͸�ģ���ô���-1����Ȼ������������ͨ͸��һ����Ҫ�����ǣ�������һ�к�������һ�ж�����Ҫ��һ�������Ǵ򿪵ġ�

�ھ���������ʱ��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҳ�����߳�����ı߽硣

����
����ĵ�һ����һ����Ȼ��T(1��T��10)������������ݵ�������ÿ��������ݵĵ�һ����������Ȼ��N��M������N��1��N��1,000���������ά�ȣ�M��1��M��N*N������������д򿪵ķ�����Ŀ������M����ÿ����������Ȼ�����ֱ�������򿪵ķ�����С����±ꡣע�⣺�����о�����±��1��ʼ���������±��ȡֵ����[1, N]�����е���������

���
ÿ������������һ����Ȼ��K����ʾ�򿪵�K������󣬾���������ͨ͸�ġ����M�����񶼴򿪺󣬾�����Ȼ��������ͨ͸�ģ���ô���-1��

��������
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
�������
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
				if(pos <= n) { // ��һ�� 
					if(father[0] == -1) {
						father[0] = 0;
					} 
					uion(pos, 0);
				}
				if(pos > n*(n-1)) { // ���һ�� 
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


