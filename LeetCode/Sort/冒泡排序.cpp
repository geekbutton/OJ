// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*

*/

/*ð������
����ʱ�临�Ӷȣ�O(n^2)
�ʱ�临�Ӷȣ�O(n^2)
ƽ��ʱ�临�Ӷȣ�O(n^2)
�ռ临�Ӷȣ�O(1)
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

void swap(int* p, int i, int j) {
	int temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void BubbleSort(int* p, int n) {
	while (n - 1) {
		for (int i = 0; i < n - 1; ++i) {
			if (p[i] > p[i + 1]) {
				swap(p, i, i + 1);
			}
		}
		--n;
	}
}

int main() {
	int A[8] = { 6,5,3,1,8,7,2,4 };
	int n = sizeof(A) / sizeof(int);
	BubbleSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}