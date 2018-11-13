/*
A:平面最近点对

描述
二维平面上有N个点，求最近点对之间的距离。

输入
第一行一个整数T，表示有T组测试数据
每组测试数据第一行一个整数N(2<=N<=1e5)表示平面有N个点
接下来有N行，每行两个整数X Y(-1e9<=X,Y <=1e9)表示点的坐标

输出
输出最近点对的距离，精确到小数点后6位

样例输入
1
3
1 0
1 1
0 1
样例输出
1.000000
*/

#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

const double INF = 1e10;
const int N = 10005;

class Point {
	public:
		int x;
		int y;
};
double computeDistance(const Point& A, const Point& B) {
	return sqrt( pow(A.x-B.x, 2) + pow(A.y-B.y, 2) );
}
bool sortByX(const Point& A, const Point& B) {
	return A.x < B.x;
}
bool sortByY(const Point& A, const Point& B) {
	return A.y < B.y;
}

Point points[N];
Point backup[N];
Point pointsSortByY[N];
double minDistance = INF;
int n;

double divideConquerFind(int l, int r) {
	if(r==l) {
		return INF;
	}
	int mid = (l+r) / 2;
	double leftMin = divideConquerFind(l, mid);
	double rightMin = divideConquerFind(mid+1, r);
	double min = leftMin < rightMin ? leftMin : rightMin;
	
	int i=l, j=mid+1, idx=l;
	while(i<=mid && j<=r) {
		if(points[i].y > points[j].y) {
			pointsSortByY[idx++] = points[j++];
		} else {
			pointsSortByY[idx++] = points[i++];
		}
	}
	while(i<=mid) {
		pointsSortByY[idx++] = points[i++];
	} 
	while(l<=r) {
		pointsSortByY[idx++] = points[j++];
	}
	
	for(i=l; i<=r; i++) {
		for(j=1; j<6&&(i+j)<=r; j++) {
			min = min < computeDistance(pointsSortByY[i], pointsSortByY[i+j]) ? min : computeDistance(pointsSortByY[i], pointsSortByY[i+j]); 
		} 
		for(j=1; j<6&&(i-j)>=l; j++) {
			min = min < computeDistance(pointsSortByY[i], pointsSortByY[i-j]) ? min : computeDistance(pointsSortByY[i], pointsSortByY[i-j]); 
		}
	}
	
	for(int k=l; k<=r; k++) {
		points[k] = pointsSortByY[k];
	}
	return min;
}


int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			points[i].x = x;
			points[i].y = y;
		}
		sort(points, points+n, sortByX);
		printf("%.6lf\n", divideConquerFind(0, n-1));
	}
	return 0;
}
