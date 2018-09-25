#include<iostream>
#include<algorithm>
using namespace std;

class Node {
    public:
    int left;
    int right;
};

bool cmp(Node n1, Node n2) {
    return n1.left < n2.left;
}

int main() {
    int n;
    cin >> n;
    Node nodes[n];
    for(int i=0; i<n; i++) {
        int left, right;
        cin >> left >> right;
        nodes[i].left = left;
        nodes[i].right = right;
    }

    sort(nodes, nodes+n, cmp);

    // for(int i=0; i<n; i++) {
    //     cout << nodes[i].left << " " << nodes[i].right << endl;
    // }

    int minLeft = nodes[0].left;
    int maxRight = nodes[0].right;
    for (int i=1; i<n ; i++) {
        if (nodes[i].left <= maxRight) {
            maxRight = maxRight > nodes[i].right ? maxRight : nodes[i].right;
        } else {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << minLeft << " " << maxRight << endl;

}