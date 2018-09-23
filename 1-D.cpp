#include<iostream>
using namespace std;

void moveOne(int index, char src, char dst) {
	cout << index << ":" << src << "->" << dst << endl;
}

void moveAll(int index, int len, char src, char by, char dst) {
	if (len == 1) {
		moveOne(index, src, dst);
		return;
	}
	moveAll(index, len-1, src, dst, by);
	moveOne(index+len-1, src, dst);
	moveAll(index, len-1, by, src, dst);
}

int main() {
	int n;
	char src, by, dst;
	cin >> n >> src >> by >> dst;
	moveAll(1, n, src, by, dst);
}
