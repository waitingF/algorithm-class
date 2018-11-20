/*
B:�ϳ�����
����
Nλͬѧվ��һ�ţ�������ʦҪ�����е�(N-K)λͬѧ���У�ʹ��ʣ�µ�Kλͬѧ������λ�þ����ųɺϳ����Ρ�
�ϳ�������ָ������һ�ֶ��Σ���Kλͬѧ���������α��Ϊ1, 2, ��, K�����ǵ���߷ֱ�ΪT1, T2, ��, TK�������ǵ��������T1 < T2 < �� < Ti , Ti > Ti+1 > �� > TK (1 <= i <= K)��
��������ǣ���֪����Nλͬѧ����ߣ�����������Ҫ��λͬѧ���У�����ʹ��ʣ�µ�ͬѧ�ųɺϳ����Ρ�
����
����ĵ�һ����һ������N��2 <= N <= 100������ʾͬѧ����������һ����n���������ÿո�ָ�����i������Ti��130 <= Ti <= 230���ǵ�iλͬѧ����ߣ����ף���
���
�������һ�У���һ��ֻ����һ������������������Ҫ��λͬѧ���С�
��������
8
186 186 150 200 160 130 197 220
�������
4
*/

#include<iostream>
using namespace std;

const int N = 102;
int height[N];
int pre[N];	// pre[i]��ʾ��1��i������������г��� 
int post[N];// post[j]��ʾ��j��n����½������г��� 

int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		int tmp;
		scanf("%d", &tmp);
		height[i] = tmp;
		pre[i] = 1;
		post[i] = 1;
	}
	
	// pre
	for(int i=1; i<=n; i++) {
		int maxLen = 1;
		for(int j=1; j<i; j++) {
			if(height[i] > height[j]) {
				maxLen = max(maxLen, pre[j]+1);
			}
		}
		pre[i] = maxLen;
	}
	
	// post
	for(int i=n; i>=1; i--) {
		int maxLen = 1;
		for(int j=i+1; j<=n; j++) {
			if(height[i] > height[j]) {
				maxLen = max(maxLen, post[j]+1);
			}
		}
		post[i] = maxLen;
	}
	
	int res = 0;
	for(int i=1; i<=n; i++) {
		res = max(res, pre[i] + post[i] - 1);
	}
	printf("%d\n", n-res);
}

