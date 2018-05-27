// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*

*/

/*�������򣺲�����Ԫ����ֵ��Ϊ��ŦԪ(��Ԫ��Ϊleft,right,center),������ŦԪ����right-1��λ��
����ʱ�临�Ӷȣ�O(nlog(n))
�ʱ�临�Ӷȣ�O(n^2)
ƽ��ʱ�临�Ӷȣ�O(nlog(n))
�ռ临�Ӷȣ�O(log(n))(ʹ�õݹ��㷨ջ�����Ŀռ俪����ƽ��Ϊlog(n),�Ϊn)
�ȶ��ԣ����ȶ�
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

int median3(int* p, int left, int right) {
	int center = (left + right) / 2;
	if (p[left] > p[center])
		swap(p, left, center);
	if (p[center] > p[right])
		swap(p, center, right);
	if (p[left] > p[center])
		swap(p, left, center);

	//������ֵ���������ڶ���λ����
	swap(p, center, right - 1);
	return p[right - 1];
}

void InsertionSort(int* p, int n) {
	for (int i = 1; i < n; ++i) {
		int temp = p[i];
		int j = i;
		for (j; j > 0; --j) {
			if (temp < p[j - 1]) {
				p[j] = p[j - 1];
				continue;
			}
			break;
		}
		p[j] = temp;
	}
}

void QuickSort(int* p, int left, int right) {
	if (left + 3 <= right) {					//��Ԫ����������ֱ�Ӳ��ò�������
		int pivot = median3(p, left, right);	//�����ŦԪ
		int i = left, j = right - 1;			//����λ��

		while (1) {
			while (p[++i] < pivot) {}
			while (p[--j] > pivot) {}
			if (i < j)
				swap(p, i, j);
			else
				break;
		}
		swap(p, i, right - 1);
		//����ʵ��
		QuickSort(p, left, i - 1);
		QuickSort(p, i + 1, right);
	}
	else {
		InsertionSort(p + left, right - left + 1);
	}
}


int main() {
	int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	//int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	QuickSort(A, 0, n - 1);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}