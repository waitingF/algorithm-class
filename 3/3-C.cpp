/*
C:����������

����
���ǳ�����Z = < z1, z2, ..., zk >������X = < x1, x2, ..., xm >�������е��ҽ������� �ϸ����� ������< i1, i2, ..., ik >��ʹ�ö�j = 1, 2, ... ,k, ��xij = zj������Z = < a, b, f, c > ��X = < a, b, c, f, b, c >�������С�

���ڸ�����������X��Y������������ҵ�X��Y����󹫹������У�Ҳ����˵Ҫ�ҵ�һ���������Z��ʹ��Z����X��������Ҳ��Y�������С�

����
�����������������ݡ�ÿ�����ݰ���һ�У������������Ȳ�����200���ַ�������ʾ�������С������ַ���֮�������ɸ��ո������

���
��ÿ���������ݣ����һ�У������������е���󹫹������еĳ��ȡ�

��������
abcfbc         abfcab
programming    contest 
abcd           mnp

�������
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




