// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*

*/

/*�鲢�������÷��β��Խ������
����ʱ�临�Ӷȣ�O(nlog(n))
�ʱ�临�Ӷȣ�O(nlog(n))
ƽ��ʱ�临�Ӷȣ�O(nlog(n))
�ռ临�Ӷȣ�O(n)(ʹ�õݹ��㷨���ݵ�һ����������)
�ȶ��ԣ��ȶ�
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

void Merge(int* p, int* temp, int left, int center, int right) {			//�ϲ��㷨��ע��������λ�õı仯
	int left_limit = center;
	int n = right - left + 1;
	int temp_left = left;

	++center;
	int index = 0;
	for (left, center; left <= left_limit && center <= right;) {
		temp[index] = (p[left] < p[center]) ? p[left++] : p[center++];
		++index;
	}
	//����ĳ�������ʣ��Ԫ��
	while (left <= left_limit) {						
		temp[index++] = p[left++];
	}
	while (center <= right) {
		temp[index++] = p[center++];
	}

	for (int i = 0; i < n; ++i) {
		p[temp_left + i] = temp[i];				//ע��p����ʼλ�ø�left�й�
	}
}

//�ݹ�汾�Ĺ鲢����
void MSort(int* p, int* temp, int left, int right) {
	if (left < right) {
		int	center = (left + right) / 2;
		MSort(p, temp, left, center);
		MSort(p, temp, center + 1, right);
		Merge(p, temp, left, center, right);
	}
}
//�����汾�Ĺ鲢�����ص����
void MSort_iter(int* p, int n) {
	int left, center, right;
	int* temp = (int*)malloc(n * sizeof(int));
	for (int increment = 1; increment < n; increment *= 2) {
		left = 0;
		while (left + increment < n) {	//ע������ж���������ʾ��ǰ������滹�����飬�Ӷ���Ҫ�ϲ�����
			//ע������Ҫ����center����right����Ϊ���뱣֤left��center��center��right�������
			//�������right����center�ᵼ������һ������ȷ������
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