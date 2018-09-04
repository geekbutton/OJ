// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
140. 单词拆分 II
https://leetcode-cn.com/problems/word-break-ii/description/

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，
使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：
	分隔时可以重复使用字典中的单词。
	你可以假设字典中没有重复的单词。
*/

/*整体思路是 :	首先利用习题139的单词拆分来判断给出的字符串能否使用字典中的单词组成句子。
若不能则提前退出避免时间开销；若能，则使用DFS遍历所有的可能组合。
*/
#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

struct Edge{
	int l = 0;
	int r = 0;
	int weight = 0;
	friend bool operator< (const Edge& a, const Edge& b) {
		return a.weight > b.weight;
	}
};

int find(int l, vector<int>& iv) {
	if (iv[l] == -1)
		return l;
	return find(iv[l], iv);
}

vector<int> Union(int l, int r, vector<int>& iv) {
	int root1 = find(l, iv);
	int root2 = find(r, iv);
	if (root1 == root2)
		return vector<int>{};
	iv[root2] = root1;
	return vector<int>{l, r};
}

int main() {
	vector<vector<int>> iv;
	iv.push_back(vector<int>{0, 2, 4, 1, 0, 0, 0});
	iv.push_back(vector<int>{2, 0, 0, 3, 10, 0, 0});
	iv.push_back(vector<int>{4, 0, 0, 2, 0, 5, 0});
	iv.push_back(vector<int>{1, 3, 2, 0, 7, 8, 4});
	iv.push_back(vector<int>{0, 10, 0, 7, 0, 0, 6});
	iv.push_back(vector<int>{0, 0, 5, 8, 0, 0, 1});
	iv.push_back(vector<int>{0, 0, 0, 4, 6, 1, 0});
	priority_queue<Edge> eq;
	vector<int> Dis(iv.size(), -1);
	for (int i = 0; i < iv.size(); ++i) {
		vector<int> temp = iv[i];
		for (int j = i; j < temp.size(); ++j) {
			if (iv[i][j] == 0)
				continue;
			Edge a;
			a.l = i;
			a.r = j;
			a.weight = iv[i][j];
			eq.push(a);
		}
	}
	vector<vector<int>> result;
	while (eq.size()) {
		Edge x = eq.top();
		vector<int> LR = Union(x.l, x.r, Dis);
		cout << x.l + 1 << " " << x.r + 1 << " ";
		for (auto x : Dis) {
			cout << x << " ";
		}
		cout << endl;
		if (LR.size() != 0) {
			result.push_back(LR);
		}
		eq.pop();
	}
	for (auto x : result) {
		for (auto y : x)
			cout << y + 1 << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}