// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*

*/

/*归并排序：利用分治策略进行求解
最优时间复杂度：O(nlog(n))
最坏时间复杂度：O(nlog(n))
平均时间复杂度：O(nlog(n))
空间复杂度：O(n)(使用递归算法传递的一个额外数组)
稳定性：稳定
*/
#include "stdafx.h"
#include <queue>
#include <iostream>
#include<functional>
using namespace std;

void swap(int* p, int i, int j) {
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void Merge(int* p, int* temp, int left, int center, int right) {			//合并算法，注意左中右位置的变化
	int left_limit = center;
	int n = right - left + 1;
	int temp_left = left;

	++center;
	int index = 0;
	for (left, center; left <= left_limit && center <= right;) {
		temp[index] = (p[left] < p[center]) ? p[left++] : p[center++];
		++index;
	}
	//处理某个数组的剩余元素
	while (left <= left_limit) {						
		temp[index++] = p[left++];
	}
	while (center <= right) {
		temp[index++] = p[center++];
	}

	for (int i = 0; i < n; ++i) {
		p[temp_left + i] = temp[i];				//注意p的起始位置跟left有关
	}
}

//递归版本的归并排序
void MSort(int* p, int* temp, int left, int right) {
	if (left < right) {
		int	center = (left + right) / 2;
		MSort(p, temp, left, center);
		MSort(p, temp, center + 1, right);
		Merge(p, temp, left, center, right);
	}
}
//迭代版本的归并排序，重点理解
void MSort_iter(int* p, int n) {
	int left, center, right;
	int* temp = (int*)malloc(n * sizeof(int));
	for (int increment = 1; increment < n; increment *= 2) {
		left = 0;
		while (left + increment < n) {	//注意理解判断条件，表示当前数组后面还有数组，从而需要合并操作
			//注意这里要先求center再求right，因为必须保证left到center及center到right是有序的
			//如果先求right再求center会导致其中一个不能确保有序。
			center = left + increment - 1;
			right = center + increment < n ? center + increment : n - 1;
			cout <<left<<" "<< center << " " << right << endl;
			Merge(p, temp, left, center, right);
			left = right + 1;
		}
	}
	free(temp);
}

void MergeSort(int* p, int n) {
	int* temp = (int*)malloc(n * sizeof(int));
	//MSort(p, temp, 0, n - 1);
	MSort_iter(p, n);
	free(temp);
}


int main() {
	//int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	MergeSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}