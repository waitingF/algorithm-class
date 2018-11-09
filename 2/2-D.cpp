
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

class Segment {
	public:
		double x1;	// 线段左端点 
		double x2;	// 线段右端点 
};

const int N = 1005;
Segment segments[N];
int visit[N];

bool cmp(Segment A, Segment B) {
	if(A.x2 == B.x2) {
		return A.x1 > B.x1;
	}
	return A.x2 < B.x2;
}

int main(){
	int n, d;
	int caseNum = 0;
	while(scanf("%d %d", &n, &d)) {
		caseNum += 1;
		if(n==0 && d==0) {
			break;
		}
		
		for(int i=0; i<N; i++) {
			segments[i].x1 = 0;
			segments[i].x2 = 0;
			visit[i] = 0;
		}
		bool success = true;
		if(d <= 0) {
			success = false;
		}
		
		for(int i=0; i<n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			if(y > d) {
				success = false;
			}
			if(success) {
				segments[i].x1 = x - sqrt(d * d - y * y);
				segments[i].x2 = x + sqrt(d * d - y * y);
			}
		}
		sort(segments, segments+n, cmp);
		
		int sum = 1;
		double maxr = segments[0].x2;
		for(int i=1; i<n; i++) {
			if(segments[i].x1 > maxr) {
				maxr = segments[i].x2;
				sum += 1;
			}
		}
		
		if(success) {
			printf("Case %d: %d\n", caseNum, sum);
		} else {
			printf("Case %d: -1\n", caseNum);
		}
		
	}
	return 0;
} 
