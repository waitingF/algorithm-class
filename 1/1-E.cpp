#include<iostream>
using namespace std;

class Node {
    public:
        Node* father;
        Node* left;
        Node* right;
        int val;
        Node();
};

Node::Node() {
    this->father = NULL;
    this->left = NULL;
    this->right = NULL;
    this->val = 0;
}

Node* build(int* mid, int midStart, int midEnd, int* post, int postStart, int postEnd) {
    if (midStart >= midEnd) {
        return NULL;
    }

    // cout << "mid: " << endl;
    // for(int i=midStart; i<midEnd; i++) {
    //     cout << mid[i] << " ";
    // }
    // cout << endl;
    // cout << "post: " << endl;
    // for(int i=postStart; i<postEnd; i++) {
    //     cout << post[i] << " ";
    // }
    // cout << endl;

    Node* root = new Node();
    root->val = post[postEnd-1]; // 后序最后一个是当前树的根
    if (midStart+1 == midEnd) {
        return root;
    }
    // cout << "cur root.val " << root->val << endl;
    // 在中序中找根
    int rootIndexInMid = 0;
    for (int i=midStart; i<midEnd; i++) {
        if (mid[i]==root->val) {
            rootIndexInMid = i;
            break;
        }
    }
    // cout << "root index in mid " << rootIndexInMid << endl;

    int leftTreeLen = rootIndexInMid - midStart;
    int rightTreeLen = midEnd - rootIndexInMid;

    int midLeftChildStart = midStart;
    int midLeftChildEnd = midStart + leftTreeLen;
    int midRightChildStart = rootIndexInMid+1;
    int midRightChildEnd = midEnd;
    int postLeftChildStart = postStart;
    int postLeftChildEnd = postStart + leftTreeLen;
    int postRightChildStart = postLeftChildEnd;
    int postRightChildEnd = postEnd-1;
    
    // cout << "mid left start: " << midLeftChildStart << " end: " << midLeftChildEnd << endl;
    // cout << "mid right start: " << midRightChildStart << " end: " << midRightChildEnd << endl;
    // cout << "post left start: " << postLeftChildStart << " end: " << postLeftChildEnd << endl;
    // cout << "post right start: " << postRightChildStart << " end: " << postRightChildEnd << endl;
    // // return NULL;

    root->left = build(mid, midLeftChildStart, midLeftChildEnd, post, postLeftChildStart, postLeftChildEnd);
    root->right = build(mid, midRightChildStart, midRightChildEnd, post, postRightChildStart, postRightChildEnd);

    return root;
}

void preTravel(Node* root) {
    cout << root->val << " ";
    if (root->left != NULL) {
        preTravel(root->left);
    }
    if (root->right != NULL) {
        preTravel(root->right);
    }
}

int main(){
    int maxLen = 65535 + 1;
    int preArray[maxLen] = {0};
    int midArray[maxLen] = {0};
    int postArray[maxLen] = {0};
    int realLen = 0;
    while(cin>>midArray[realLen]){
        realLen++;
        if (cin.get() == '\n') {
            break;
        }
    }
    realLen = 0;
    while(cin>>postArray[realLen]) {
        realLen ++;
        if (cin.get() == '\n') {
            break;
        }
    }

    Node* root = build(midArray, 0, realLen, postArray, 0, realLen);
    // cout << "root built success" << endl;
    preTravel(root);
    cout << endl;
    return 0;
}