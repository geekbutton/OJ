// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*

*/

/*ѡ������ÿ��ѡ����С(���)Ԫ�ؽ�������
����ʱ�临�Ӷȣ�O(n^2)
�ʱ�临�Ӷȣ�O(n^2)
ƽ��ʱ�临�Ӷȣ�O(n^2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

void swap(int* p, int i, int j) {
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void SelectionSort(int* p, int n) {
	int min_index = 0;
	int index = 0;
	while (index < n) {
		for (int i = index; i < n; ++i) {
			if (p[i] < p[min_index]) {
				min_index = i;
			}
		}
		swap(p, index, min_index);
		min_index = ++index;
	}
}

int main() {
	//int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	SelectionSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}