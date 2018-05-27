// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*

*/

/*�Ľ���ð�����������⵽ĳ��������Ϊ��������ֱ���˳�
����ʱ�临�Ӷȣ�O(n)
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
		int count = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (p[i] > p[i + 1]) {
				swap(p, i, i + 1);
				++count;
			}
		}
		if(count==0){
			break;
		}
		--n;
	}
}

int main() {
	int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	int n = sizeof(A) / sizeof(int);
	BubbleSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}