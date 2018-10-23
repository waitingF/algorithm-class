#include<iostream>
#include<string>

using namespace std;

int main() {
	char in[501];
//	input = "hello world  haha";
	cin.get(in, 500);

	
	string input = string(in);
	string reverse;
	string tmp;
	
	for (int i=0; i<input.length(); i++) {
		if (input[i] == ' ') {
			reverse = reverse.append(tmp);
			reverse = reverse.append(" ");
			tmp = "";
		} else {
			tmp.insert(tmp.begin(), input[i]);
			if (i == input.length()-1) {
				reverse = reverse.append(tmp);
				tmp = "";
			}
		}
	}
	
	cout<< reverse << endl;
}
