// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
Waiter

https://www.hackerrank.com/challenges/waiter/problem
*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
* Complete the waiter function below.
*/
vector<int> waiter(vector<int> number, int q) {
	/*
	* Write your code here.
	*/
	vector<int> result_iv;
	int iter = 1;

	int prime = 2;
	vector<int> res_A = number;
	while (iter <= q) {
		vector<int> temp_B;
		vector<int> temp_res_A;
		if (iter == 1) {
			for (int i = res_A.size() - 1; i >= 0; --i) {
				if (res_A[i] % prime == 0)
					temp_B.push_back(res_A[i]);
				else
					temp_res_A.push_back(res_A[i]);
			}
			res_A = temp_res_A;
			temp_res_A.clear();
			++iter;
		}
		else {
			//Get prime
			int flag = 0;
			while (!flag) {
				++prime;
				flag = 1;
				int max_num = ceil((sqrt(prime)));
				for (int i = 2; i <= max_num; ++i) {
					if (prime%i == 0) {
						flag = 0;
						break;
					}
				}
			}
			for (int i = res_A.size() - 1; i >= 0; --i) {
				if (res_A[i] % prime == 0)
					temp_B.push_back(res_A[i]);
				else
					temp_res_A.push_back(res_A[i]);
			}
			res_A = temp_res_A;
			temp_res_A.clear();
			++iter;
		}
		for (int i = temp_B.size() - 1; i >= 0; --i)
			result_iv.push_back(temp_B[i]);

	}

	for (int i = res_A.size() - 1; i >= 0; --i)
		result_iv.push_back(res_A[i]);

	return result_iv;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string nq_temp;
	getline(cin, nq_temp);

	vector<string> nq = split_string(nq_temp);

	int n = stoi(nq[0]);

	int q = stoi(nq[1]);

	string number_temp_temp;
	getline(cin, number_temp_temp);

	vector<string> number_temp = split_string(number_temp_temp);

	vector<int> number(n);

	for (int number_itr = 0; number_itr < n; number_itr++) {
		int number_item = stoi(number_temp[number_itr]);

		number[number_itr] = number_item;
	}

	vector<int> result = waiter(number, q);

	for (int result_itr = 0; result_itr < result.size(); result_itr++) {
		fout << result[result_itr];

		if (result_itr != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

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
