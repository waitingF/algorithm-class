/*
B:合唱队形
描述
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换位置就能排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK，则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1 <= i <= K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
输入
输入的第一行是一个整数N（2 <= N <= 100），表示同学的总数。第一行有n个整数，用空格分隔，第i个整数Ti（130 <= Ti <= 230）是第i位同学的身高（厘米）。
输出
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
样例输入
8
186 186 150 200 160 130 197 220
样例输出
4
*/

#include<iostream>
using namespace std;

const int N = 102;
int height[N];
int pre[N];	// pre[i]表示从1到i的最长上升子序列长度 
int post[N];// post[j]表示从j到n的最长下降子序列长度 

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

