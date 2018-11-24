/*
A:ƽ��������

����
��άƽ������N���㣬��������֮��ľ��롣

����
��һ��һ������T����ʾ��T���������
ÿ��������ݵ�һ��һ������N(2<=N<=1e5)��ʾƽ����N����
��������N�У�ÿ����������X Y(-1e9<=X,Y <=1e9)��ʾ�������

���
��������Եľ��룬��ȷ��С�����6λ

��������
1
3
1 0
1 1
0 1
�������
1.000000
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

const double INF = 1e10;
const int N = 1e5 + 4;

class Point {
	public:
		int x;
		int y;
};
bool sortByX(const Point& A, const Point& B) {
	return A.x < B.x;
}

Point pointsX[N];
Point backup[N];
double minDistance = INF;
int n;

double divideConquerFind(Point Px[], int n) {
	if(n <= 1) {
		return INF;
	}
	int mid = n / 2;
	Point midPoint = Px[mid];
	
	double leftMin = divideConquerFind(Px, mid);
	double rightMin = divideConquerFind(Px+mid, n-mid);
	double minDis = min(leftMin, rightMin);
	
	// �鲢��y����
	int i=0, j=mid;
	Point tmp[n+1];
	int k=0;
	while(i<mid && j<n) {
		if(Px[i].y <= Px[j].y) {
			tmp[k++] = Px[i++];
		} else {
			tmp[k++] = Px[j++];	
		}
	}
	while(i<mid) {
		tmp[k++] = Px[i++];
	}
	while(j<n) {
		tmp[k++] = Px[j++];	
	}
	for(i=0; i<n; i++) {
		Px[i] = tmp[i];
	}
	
	vector<Point> b;
	for(i=0; i<n; i++) {
		if(fabs(Px[i].x - midPoint.x) >= minDis){
			continue;
		}
		for(j=0; j<b.size(); j++) {
			double dx = Px[i].x - b[b.size()-j-1].x;
			double dy = Px[i].y - b[b.size()-j-1].y;
//			if(dy >= minDis) {
//				continue;
//			}
			minDis = min(minDis, sqrt(dx*dx + dy*dy));
		}
		b.push_back(Px[i]);
	}
	
	return minDis;
}


int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			pointsX[i].x = x;
			pointsX[i].y = y;
		}
		sort(pointsX, pointsX+n, sortByX);
		printf("%.6lf\n", divideConquerFind(pointsX, n));
	}
	return 0;
}
