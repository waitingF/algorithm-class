/*
����
��һȺ���а����ߣ���һ�죬���Ǵ�����nֻ������������������ÿһֻ������������ͬ�����е�һ�֣�Ϊ�����۷��㣬���ǳ�����ΪA��B���������nֻ�걾�ֳ����顪��һЩ����A��һЩ����B��������ֱ�ӱ���κ�һ���걾���������Ƿǳ����ѣ�������Ǿ�����������ķ�����
��ÿ�Ա걾i��j������ϸ�ĵذ����Ƿŵ�һ���о�������������Լ����ж�����ȷ�ţ���ô���ǰ���Ժ������Ϊ����ͬ��������ζ��������������ֻ����ͬһ�ࣩ�����ǡ���ͬ��������ζ��������������ֻ���Բ�ͬ���ࣩ������Ҳ���Զ�ĳЩ�걾�жϲ���������Ȩ������������£����ǳ���Ա걾�ǲ���ȷ�ġ�
����������nֻ�걾�ļ��ϣ����ж���Щû����Ȩ�ı걾�Ե�m���жϵļ��ϣ�����ͬ�����ߡ���ͬ������������֪�����������ÿֻ��������A��B�е�һ������뷨�Ƿ�һ�¡��������˵�������ÿ�Ժ�������������ʽ���A��B�ǿ��ܵģ�����ÿ����Ϊ����ͬ���ģ�i��j���ԣ�����i��j����ͬ��ǵ��������ÿ����Ϊ����ͬ���ģ�i��j���ԣ�����i��j�в�ͬ��ǵ��������ô���ǿ���˵��m���ж���һ�µġ���������ڤ˼�����Լ����ж��Ƿ���һ�µġ������������ƺ�����㷨��������⡣


����
��������������ݣ����ļ�������Ϊ��ֹ��

ÿ�����ݵ�һ��Ϊ�����������ֱ���n��m��
nΪ��������������Ŵ�0��n-1
mΪ��ϵ������

��������m���ϵ���ݣ�ÿ������ռһ�У�Ϊ����������ǰ����������ʾ�����ı�ţ�����������Ϊ��ϵ�����ࣨ��ͬ���߲�ͬ����
0Ϊ��ͬ��1Ϊ��ͬ

1 < n <= 1000
1 < m <= 100000
���
��������YES
����������NO

��������
3 3
0 1 0
1 2 1
0 2 1
3 3
0 1 0
1 2 1
0 2 0
�������
YES
NO

˼·��
����ͼȾɫ 
*/

#include<iostream>
#include<queue>
#include<memory.h>
#include<stdio.h>
using namespace std;

#define SAME 1
#define DIFF 2 

const int N = 1005;
int relation[N][N];	// �����飬���ܶ�̬�����ڴ棻0��ʾ�޹�ϵ��1��ʾ����ͬ�࣬2��ʾͬ�� 
int color[N];	// ÿ���ڵ����ɫ�� 0����ν��1��ɫ��2��ɫ��3��ͻ 
int visit[N];
queue<int> myQueue;
bool success;
int n, m;

bool BFS(int node) {
	if(visit[node]){
		return true;
	}
	visit[node] = 1;
	if (color[node] == 0) {	// ��δȾɫ�� 
		color[node] = 1;
	}
	
	for(int i=0; i<n; i++) {
		if (relation[node][i] == SAME) {
			if (color[i] == 0) {
				color[i] = color[node];
				myQueue.push(i);
			} else if (color[node] != color[i]) {
				return false;
			}
		} else if(relation[node][i] == DIFF) {
			if (color[i] == 0) {
				color[i] = 3 - color[node];
				myQueue.push(i);
			} else if(color[i] == color[node]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	while(scanf("%d %d", &n, &m)!=-1) {
		memset(relation, 0, sizeof(relation));
		memset(color, 0, sizeof(color)); 
		memset(visit, 0, sizeof(visit));
		while(!myQueue.empty()){
			myQueue.pop();
		}
		success = true;
		
		for(int i=0; i<m; i++) {
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			if (r == 0) {
				relation[x][y] = SAME;
				relation[y][x] = SAME;
			} else {
				relation[x][y] = DIFF;
				relation[y][x] = DIFF;
			}
		} 
		
		for (int i=0; i<n; i++) {
			myQueue.push(i);
			while(!myQueue.empty()) {
				if(!BFS(myQueue.front())) {
					success = false;
					break;
				}
				myQueue.pop();
			}	
		}
		
		if(success) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
} 
