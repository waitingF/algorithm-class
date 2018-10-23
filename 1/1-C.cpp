#include<iostream>
#include<stack>
using namespace std;

int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		
		int n;
		cin >> n;
		int input[n];
		for (int index=0; index<n; index++) {
			cin >> input[index];
		}
		
		int index=0;
		stack<int> tmpS;
		for (int inNum=1; inNum<=n; inNum++) {
			tmpS.push(inNum);
			int top = tmpS.top();
			
			while(top == input[index] && index < n) {
				tmpS.pop();
				index++;
				if (tmpS.empty()){
					break;
				}
				top = tmpS.top();
			}
		}
		
		if (tmpS.empty()) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	
} 
