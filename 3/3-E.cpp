/*
E:股票买卖

描述
最近越来越多的人都投身股市，阿福也有点心动了。谨记着“股市有风险，入市需谨慎”，阿福决定先来研究一下简化版的股票买卖问题。
假设阿福已经准确预测出了某只股票在未来 N 天的价格，他希望买卖两次，使得获得的利润最高。为了计算简单起见，利润的计算方式为卖出的价格减去买入的价格。
同一天可以进行多次买卖。但是在第一次买入之后，必须要先卖出，然后才可以第二次买入。
现在，阿福想知道他最多可以获得多少利润。

输入
输入的第一行是一个整数 T (T <= 50) ，表示一共有 T 组数据。
接下来的每组数据，第一行是一个整数 N (1 <= N <= 100, 000) ，表示一共有 N 天。第二行是 N 个被空格分开的整数，表示每天该股票的价格。该股票每天的价格的绝对值均不会超过 1,000,000 。
输出
对于每组数据，输出一行。该行包含一个整数，表示阿福能够获得的最大的利润。
样例输入
3
7
5 14 -2 4 9 3 17
6
6 8 7 4 1 -2
4
18 9 5 2
样例输出
28
2
0
提示
对于第一组样例，阿福可以第 1 次在第 1 天买入（价格为 5 ），然后在第 2 天卖出（价格为 14 ）。第 2 次在第 3 天买入（价格为 -2 ），然后在第 7 天卖出（价格为 17 ）。一共获得的利润是 (14 - 5) + (17 - (-2)) = 28
对于第二组样例，阿福可以第 1 次在第 1 天买入（价格为 6 ），然后在第 2 天卖出（价格为 8 ）。第 2 次仍然在第 2 天买入，然后在第 2 天卖出。一共获得的利润是 8 - 6 = 2
对于第三组样例，由于价格一直在下跌，阿福可以随便选择一天买入之后迅速卖出。获得的最大利润为 0
*/
#include<iostream>
using namespace std;

#define INF 1000000

const int N = 100005;
int price[N];
int delta[N] = {-INF};
long pre[N] = {-INF};	// pre[i] 表示从头到 i 的最大收益 
long post[N] = {-INF};	// post[i] 表示从 i 到尾的最大收益 

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			int tmp;
			scanf("%d", &tmp);
			price[i] = tmp;
			delta[i] = price[i] - price[i-1];
			delta[1] = 0;
			pre[i] = post[i] = 0; 
		}
		
		// pre
		int minPrice = price[1];
		pre[1] = 0; 
		for(int i=2; i<=n; i++) {
			minPrice = min(minPrice, price[i]);
			pre[i] = max(pre[i-1], long(price[i]-minPrice));
		} 
		
		// post
		int maxPrice = price[n];
		post[n] = 0;
		for(int i=n-1; i>=2; i--) {
			maxPrice = max(maxPrice, price[i]);
			post[i] = max(post[i+1], long(maxPrice-price[i]));
		}
		
		long res = -INF;
		for(int i=1; i<=n; i++) {
			res = max(res, pre[i] + post[i]);
		}
		
		printf("%ld\n", res);
		
		
		
	}
}






//#include<iostream>
//using namespace std;
//
//#define INF 10000000
//
//const int N = 100005;
//int price[N];
//int delta[N] = {-INF};	// 相邻price的差, delta[i] = price[i] - price[i-1], delta[1] = 0
//long dp[N];	// dp[i]表示以delta[i]结尾的最大子序列和
//int pos[N];	// pos[i]表示dp[i]开始的位置 
//
//int findMaxSubSequence(int start, int end) {
//	if(start > end) {
//		return 0;
//	}
//	dp[start] = delta[start];
//	pos[start] = start;
//	int max = delta[start];
//	int maxIndex = start;
//	for(int i=start+1; i<=end; i++) {
//		if(dp[i-1] >= 0) {
//			dp[i] = dp[i-1] + delta[i];
//			pos[i] = pos[i-1];
//		} else {
//			dp[i] = delta[i];
//			pos[i] = i;
//		}
//		
//		if(max <= dp[i]) {
//			max = dp[i];
//			maxIndex = i;
//		}
//	}
//	return maxIndex;
//}
//
//int main() {
//	int t;
//	scanf("%d", &t);
//	while(t--) {
//		for(int i=0; i<N; i++) {
//			delta[i] = -INF;
//			price[i] = -INF;
//			dp[i] = -INF;
//			pos[i] = 0;
//		}
//		int n;
//		scanf("%d", &n);
//		for(int i=1; i<=n; i++) {
//			int tmp;
//			scanf("%d", &tmp);
//			price[i] = tmp;
//			delta[i] = price[i] - price[i-1];
//			delta[1] = 0;
//		}
////		for(int i=1; i<=n; i++) {
////			cout << delta[i] << " ";
////		}
////		cout << endl;
//		
//		int maxIndex1 = findMaxSubSequence(1, n);
//		long max1 = dp[maxIndex1];
////		cout << "max1=" << max1 << " from " << pos[maxIndex1] << " to " << maxIndex1 << endl;
//		
//		int maxIndex2 = findMaxSubSequence(1, pos[maxIndex1]-1);
//		long max2 = dp[maxIndex2];
////		cout << "max2=" << max2 << " from " << pos[maxIndex2] << " to " << maxIndex2 << endl;
//		
//		int maxIndex3 = findMaxSubSequence(maxIndex1+1, n);
//		long max3 = dp[maxIndex3];
////		cout << "max3=" << max3 << " from " << pos[maxIndex3] << " to " << maxIndex3 << endl;
//		
//		long max4 = max2 > max3 ? max2 : max3;
//		max4 = max4 > 0 ? max4 : 0;
//		printf("%ld\n", max1 + max4);
// 		
//	}	
//}
