/*
E:Agri-Net

最小生成树 
*/

#include<iostream>
#include<queue>
using namespace std;

struct Edge {
	int start;
	int end;
	int weight;
};

struct cmp {
	bool operator() (const Edge& A, const Edge& B) {
		return A.weight > B.weight;
	}
};

const int N = 105;
int matrix[N][N];
int father[N];
priority_queue<Edge, vector<Edge>, cmp> edgeQueue;

int findFather(int x) {
	if(father[x] != x) {
		father[x] = findFather(father[x]);
		return father[x];
	}
	return father[x];
}

void uion(int x, int y) {
	int fatherX = findFather(x);
	int fatherY = findFather(y);
	if(fatherX != fatherY) {
		father[fatherX] = fatherY;
	}
}

int main() {
	int n;
	long weight = 0;
	while(scanf("%d", &n)!=-1) { // 未指定结束方式，默认EOF结束 
		if(n<3 || n >100) {
			break;
		}
		for(int i=0; i<N; i++) {
			father[i] = i;
		} 
		weight = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				int dis;
				scanf("%d", &dis);
				matrix[i][j] = dis;
				Edge e;
				e.start = i;
				e.end = j;
				e.weight = dis;
				edgeQueue.push(Edge(e));
			}
		}
		
		while(!edgeQueue.empty()) {
			Edge e = edgeQueue.top();
			edgeQueue.pop();
			if(e.start == e.end) {
				continue;
			}
			if(findFather(e.start) == findFather(e.end)) {
				continue;
			}
			uion(e.start, e.end);
			weight += e.weight;	
		}	
		printf("%d\n", weight);
	}
	return 0;
}
