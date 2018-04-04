// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Game of Two Stacks

Output Format

For each of the  games, print an integer on a new line denoting the maximum possible score Nick can achieve without being disqualified.

*/


//#include <bits/stdc++.h>
#include "stdafx.h"
#include <stdio.h>
#include <vector>

using namespace std;

vector<string> split_string(string);

/*
* Complete the twoStacks function below.
*/
int twoStacks(int x, vector<int> a, vector<int> b) {
	/*
	* Write your code here.
	*/
	int sum_a = 0, sum_b = 0,count = 0;
	vector<int> iv_a, iv_b;
	for (int i = 0; i < a.size(); ++i) {
		if (sum_a + a[i] <= x) {
			sum_a += a[i];
			iv_a.push_back(sum_a);
		}
		else break;
	}
	for (int i = 0; i < b.size(); ++i) {
		if (sum_b + b[i] <= x) {
			sum_b += b[i];
			iv_b.push_back(sum_b);
		}
		else break;
	}
	if (iv_a.size() == 0 || iv_b.size() == 0) {
		return iv_a.size() + iv_b.size();
	}
	for (int i = 0; i < iv_a.size(); ++i) {
		int j = (count - 2 - i > 0 ? count - 2 - i : 0);
		if (iv_a[i] + iv_b[j] > x)
			continue;
		for (j; j < iv_b.size(); ++j) {
			if (iv_a[i] + iv_b[j] <= x) {
				int temp_count = i + 1 + j + 1;
				if (temp_count > count)
					count = temp_count;
			}
			else {
				break;
			}
		}
	}
	if (count < iv_a.size() || count < iv_b.size())
		return iv_a.size() > iv_b.size() ? iv_a.size():iv_b.size();
	return count;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int g;
	cin >> g;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int g_itr = 0; g_itr < g; g_itr++) {
		string nmx_temp;
		getline(cin, nmx_temp);

		vector<string> nmx = split_string(nmx_temp);

		int n = stoi(nmx[0]);

		int m = stoi(nmx[1]);

		int x = stoi(nmx[2]);

		string a_temp_temp;
		getline(cin, a_temp_temp);

		vector<string> a_temp = split_string(a_temp_temp);

		vector<int> a(n);

		for (int a_itr = 0; a_itr < n; a_itr++) {
			int a_item = stoi(a_temp[a_itr]);

			a[a_itr] = a_item;
		}

		string b_temp_temp;
		getline(cin, b_temp_temp);

		vector<string> b_temp = split_string(b_temp_temp);

		vector<int> b(m);

		for (int b_itr = 0; b_itr < m; b_itr++) {
			int b_item = stoi(b_temp[b_itr]);

			b[b_itr] = b_item;
		}

		int result = twoStacks(x, a, b);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
