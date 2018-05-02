// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Simple Text Editor

https://www.hackerrank.com/challenges/simple-text-editor/problem
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int Q;
	cin >> Q;
	stack<string> ss;
	stack<int> is;
	stack<int> len_s;
	int k;
	string temp_s;
	string s;
	
	for (int i = 0; i < Q; ++i) {
		int mode;
		cin >> mode;
		switch (mode) {
		case 1:
			cin >> temp_s;
			s += temp_s;
			ss.push(temp_s);
			is.push(1);
			len_s.push(temp_s.size());
			break;
		case 2:
			cin >> k;
			ss.push(s.substr(s.size() - k, k));
			s = s.substr(0, s.size() - k);
			is.push(2);
			break;
		case 3:
			cin >> k;
			cout << s[k - 1] << endl;
			break;
		case 4:
			if (ss.size() != 0) {			
				mode = is.top();
				is.pop();
				temp_s = ss.top();
				ss.pop();
				int index = 0;
				if (mode == 1) {
					int len = len_s.top();
					len_s.pop();
					s = s.substr(0, s.size() - len);
				}
				else if (mode == 2) {
					s += temp_s;
				}
				
			}
			break;
		}
	}

	return 0;
}