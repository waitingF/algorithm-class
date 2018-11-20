/*
E:��Ʊ����

����
���Խ��Խ����˶�Ͷ����У�����Ҳ�е��Ķ��ˡ������š������з��գ���������������������������о�һ�¼򻯰�Ĺ�Ʊ�������⡣
���谢���Ѿ�׼ȷԤ�����ĳֻ��Ʊ��δ�� N ��ļ۸���ϣ���������Σ�ʹ�û�õ�������ߡ�Ϊ�˼�������������ļ��㷽ʽΪ�����ļ۸��ȥ����ļ۸�
ͬһ����Խ��ж�������������ڵ�һ������֮�󣬱���Ҫ��������Ȼ��ſ��Եڶ������롣
���ڣ�������֪���������Ի�ö�������

����
����ĵ�һ����һ������ T (T <= 50) ����ʾһ���� T �����ݡ�
��������ÿ�����ݣ���һ����һ������ N (1 <= N <= 100, 000) ����ʾһ���� N �졣�ڶ����� N �����ո�ֿ�����������ʾÿ��ù�Ʊ�ļ۸񡣸ù�Ʊÿ��ļ۸�ľ���ֵ�����ᳬ�� 1,000,000 ��
���
����ÿ�����ݣ����һ�С����а���һ����������ʾ�����ܹ���õ���������
��������
3
7
5 14 -2 4 9 3 17
6
6 8 7 4 1 -2
4
18 9 5 2
�������
28
2
0
��ʾ
���ڵ�һ���������������Ե� 1 ���ڵ� 1 �����루�۸�Ϊ 5 ����Ȼ���ڵ� 2 ���������۸�Ϊ 14 ������ 2 ���ڵ� 3 �����루�۸�Ϊ -2 ����Ȼ���ڵ� 7 ���������۸�Ϊ 17 ����һ����õ������� (14 - 5) + (17 - (-2)) = 28
���ڵڶ����������������Ե� 1 ���ڵ� 1 �����루�۸�Ϊ 6 ����Ȼ���ڵ� 2 ���������۸�Ϊ 8 ������ 2 ����Ȼ�ڵ� 2 �����룬Ȼ���ڵ� 2 ��������һ����õ������� 8 - 6 = 2
���ڵ��������������ڼ۸�һֱ���µ��������������ѡ��һ������֮��Ѹ����������õ��������Ϊ 0
*/
#include<iostream>
using namespace std;

#define INF 1000000

const int N = 100005;
int price[N];
int delta[N] = {-INF};
long pre[N] = {-INF};	// pre[i] ��ʾ��ͷ�� i ��������� 
long post[N] = {-INF};	// post[i] ��ʾ�� i ��β��������� 

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
//int delta[N] = {-INF};	// ����price�Ĳ�, delta[i] = price[i] - price[i-1], delta[1] = 0
//long dp[N];	// dp[i]��ʾ��delta[i]��β����������к�
//int pos[N];	// pos[i]��ʾdp[i]��ʼ��λ�� 
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
