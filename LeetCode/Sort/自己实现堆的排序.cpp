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
using namespace std;

void swap(int* p, int l, int r) {
	int temp = p[l];
	p[l] = p[r];
	p[r] = temp;
}

void precolate_up(int* p, int index) {
	int parent = (index - 1) / 2;
	int value = p[index];
	while (parent > 0) {
		if (p[parent] < value) {
			p[index] = p[parent];
			index = parent;
			parent = (index - 1) / 2;
			continue;
		}
		break;
	}
	if (p[parent] < value) {
		p[index] = p[parent];
		index = parent;
	}
	p[index] = value;
}

void precolate_down(int* p, int index, int n) {
	int rchild = 2 * index + 2;
	int lchild = 2 * index + 1;
	if (lchild > n - 1)
		return;
	int value = p[index];
	while (rchild <= n - 1) {
		if (p[lchild] >= p[rchild] && p[lchild] > value) {
			p[index] = p[lchild];
			index = lchild;
		}
		else  if (p[rchild] > p[lchild] && p[rchild] > value) {
			p[index] = p[rchild];
			index = rchild;
		}
		else {
			p[index] = value;
			return;
		}
		lchild = 2 * index + 1;
		rchild = 2 * index + 2;
	}
	if (lchild <= n - 1) {
		if (p[lchild] > value) {
			p[index] = p[lchild];
			index = lchild;
		}
	}
	p[index] = value;
}

void creat_heap(int* p, int n) {
	int index = 0;
	if (n % 2)
		index = (n - 1) / 2;
	else index = (n - 2) / 2 + 1;
	for (int i = index - 1; i >= 0; --i) {
		precolate_down(p, i, n);
	}
}

void HeapSort(int* p, int n) {
	//creat_heap(p, n);		//(1) 先统一构造所有数，再通过从最后一个非叶节点下滤来构造堆
	//(2) 每插入一个元素按照上滤构造堆
	for (int i = 1; i < n; ++i) {
		precolate_up(p, i);
	}

	for (int i = 0; i < n - 1; ++i) {
		swap(p, 0, n - i - 1);
		precolate_down(p, 0, n - i - 1);
	}

}

int main() {
	int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	//int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	HeapSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;
	system("pause");
}