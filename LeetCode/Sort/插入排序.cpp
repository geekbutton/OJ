// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
*/

/*�������򣺸��ݴ�˶Ѻ�С�˶ѿ����Խ������������
����ʱ�临�Ӷȣ�O(n)
�ʱ�临�Ӷȣ�O(n^2)
ƽ��ʱ�临�Ӷȣ�O(n^2)
�ռ临�Ӷȣ�O(1)
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

void InsertionSort(int* p, int n) {
	int index = 1;
	for (int i = 1; i < n; ++i) {
		int temp = p[i];
		int j = i;
		//ע���������δ���ý����ķ�ʽ�����ǽ���Ŀ��ֵ���Ԫ��һ�κ���һλ��
		//���ղ��������Ԫ�ء�
		for (j; j > 0; --j) {				
			if (temp < p[j - 1]) {			//��Ŀ��ֵ�����һλ
				p[j] = p[j - 1];
				continue;
			}
			break;
		}
		p[j] = temp;				//p[j-1]С�ڵ���temp����˲���temp��p[j]������㷨�ȶ�
	}
}

int main() {
	//int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	InsertionSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}