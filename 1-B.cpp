#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std;

void encry(char *dst, char *src, int *priKey, int n) {
//	cout << "in encry src " << src << endl;
//	for (int i=0; i<n; i++) {
//		cout << priKey[i] <<" ";
//	} cout << endl;
	for (int i=0; i<n; i++) {
		dst[priKey[i]] = src[i];
//		cout << "i="<<i<< " src[i]=" << src[i] << " priKey[i]=" << priKey[i] << endl;
	}
//	cout << "out encry dst " << dst << endl;
}

void encrypt(char *dst, char *src, int *priKey, int n, int times) {
//	cout << "in encrypt " << src << endl;
	for (int i=0; i<times; i++) {
		encry(dst, src, priKey, n);
		memcpy(src, dst, sizeof(src));
	}
}

int main(){
	
	while(true) {	
		int n;
		int privateKey[202];
		scanf("%d", &n);
		cout << n << endl;
		if (n==0) {
			break;
		}
		
		for (int i=0; i<n; i++) {
			cin >> privateKey[i];
			privateKey[i]--;
		}
		
		while(true) {
			int k;
			char msg[n+1] = {0};
			cin >> k;
			getchar();
			if (k==0) {
				break;
			}
			
			cin.get(msg, n+1);
//			cout << "init msg: " << msg << endl;
			for (int i=0; i<n; i++) {
				if (msg[i] == '\0') {
					msg[i] = ' ';
				}
			} 
			msg[n] = '\0';
//			cout << "msg len: " << strlen(msg) << endl;
//			cout << "msg: " << msg << endl;
//			for (int i=0; i<n; i++) {
//				cout << privateKey[i] << " ";
//			}
//			cout <<endl;
			
			char encrpMsg[n+1] = {0};
			encrypt(encrpMsg, msg, privateKey, n, k);
			cout << encrpMsg << endl;
		}
		cout << endl;
		
	}
} 
