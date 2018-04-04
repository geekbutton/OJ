// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Largest Rectangle

https://www.hackerrank.com/challenges/largest-rectangle/problem
*/


#include <bits/stdc++.h>

using namespace std;

long largestRectangle(vector <int> h) {
	// Complete this function
	int min_value = h[h.size()-1];
	long int max_value = 0;
	int l_index = 0, r_index = 0;
	for (int i = 0; i < h.size(); ++i) {
		int min_value = h[i];
		int j = 0;
		for (j = i - 1; j >= 0; --j) {
			if (h[j] < min_value)
				break;
		}
		l_index = j + 1;
		for (j = i + 1; j < h.size(); ++j) {
			if (h[j] < min_value)
				break;
		}
		r_index = j - 1;
		int value = (r_index-l_index + 1)*h[i];
		if (value > max_value)
			max_value = value;
	}
	return max_value;
}

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int h_i = 0; h_i < n; h_i++) {
		cin >> h[h_i];
	}
	long result = largestRectangle(h);
	cout << result << endl;
	return 0;
}
