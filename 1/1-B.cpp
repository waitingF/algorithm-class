//#include<iostream>
//#include<string>
//#include<string.h>
//#include<stdio.h>
//
//using namespace std;
//
//void encry(char *dst, char *src, int *priKey, int n) {
//	for (int i=0; i<n; i++) {
//		dst[priKey[i]] = src[i];
//	}
//}
//
//void encrypt(char *dst, char *src, int *priKey, int n, int times) {
//	for (int i=0; i<times; i++) {
//		encry(dst, src, priKey, n);
//		memcpy(src, dst, sizeof(src));
//	}
//}
//
//int main(){
//	
//	while(true) {	
//		int n;
//		int privateKey[202];
//		scanf("%d", &n);
//		cout << n << endl;
//		if (n==0) {
//			break;
//		}
//		
//		for (int i=0; i<n; i++) {
//			cin >> privateKey[i];
//			privateKey[i]--;
//		}
//		
//		while(true) {
//			int k;
//			char msg[n+1] = {0};
//			cin >> k;
//			getchar();
//			if (k==0) {
//				break;
//			}
//			
//			cin.get(msg, n+1);
//			for (int i=0; i<n; i++) {
//				if (msg[i] == '\0') {
//					msg[i] = ' ';
//				}
//			} 
//			msg[n] = '\0';
//			
//			char encrpMsg[n+1] = {0};
//			encrypt(encrpMsg, msg, privateKey, n, k);
//			cout << encrpMsg << endl;
//		}
//		cout << endl;
//		
//	}
//} 

#include <stdio.h>
#include <string.h>

int main()
{
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0)
			break;

		int a[201], cycle[201] = {0};
		for(int i=0; i<n; ++i) {
			scanf("%d", &a[i]);
			a[i] -= 1;
		}

		/* 计算密钥每一位的周期 */
		for(int i=0; i<n; ++i) {
			int pos = i;
			while(true) {
				pos = a[pos];
				++cycle[i];
				if(pos == i)
					break;
			}
		}
		/* 加密 */
		char message[201], new_message[201];
		while(true){
			int loop;
			scanf("%d", &loop);
			if(loop == 0)
				break;

			getchar();
			gets(message);

			int len = strlen(message);
			for(int i=len; i<n; ++i)
				message[i] = ' ';
			
			for(int i=0; i<n; ++i) {
				int loop_i = loop % cycle[i];
				int pos_i = i;
				while(loop_i--) {
					pos_i = a[pos_i];
				}
				new_message[pos_i] = message[i];
			}
			new_message[n] = '\0';
			printf("%s\n", new_message);
		}
		printf("\n");	//每一个块后有一个空行
	}
	return 0;
}
