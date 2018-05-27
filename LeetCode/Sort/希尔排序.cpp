// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*

*/

/*ϣ�����򣺸��ݴ�˶Ѻ�С�˶ѿ����Խ������������
����ʱ�临�Ӷȣ�O(n)
�ʱ�临�Ӷȣ�O(n^2)
ƽ��ʱ�临�Ӷȣ�Shell������O(N^2),Hibbard����O(n^1.5),Sedgewick������O(N^(7/6))
�ռ临�Ӷȣ�O(1)
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

void ShellSort(int* p, int n) {
	int increment = n / 2;		//�˴����õ���ϣ������
	for (increment; increment > 0; increment /= 2) {
		for (int i = increment; i < n; ++i) {		//ע��i����ʼֵ
			int temp = p[i];
			int j = i;
			for (j; j > increment - 1; j -= increment) {	//ע��j����ʼֵ��Լ������(��ϲ����������)
				if (temp < p[j - increment]) {
					p[j] = p[j - increment];
					continue;
				}
				break;
			}
			p[j] = temp;
		}
	}
}


int main() {
	//int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	ShellSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}