// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*

*/

/*�����򣺸��ݴ�˶Ѻ�С�˶ѿ����Խ������������
����ʱ�临�Ӷȣ�O(nlog(n))
�ʱ�临�Ӷȣ�O(nlog(n))
ƽ��ʱ�临�Ӷȣ�O(nlog(n))
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

void HeapSort(int* p, int n) {
	priority_queue<int,vector<int>,greater<int>> iq;			//С�˶�
	for (int i = 0; i < n; ++i)
		iq.push(p[i]);
	for (int i = 0; i < n; ++i) {
		p[i] = iq.top();
		iq.pop();
	}
}

int main() {
	int A[] = { 9,8,7,6,5,4,3,2,1,0 };
	//int A[] = { 0,1,2,3,4,5,6,8,7,9 };
	//int A[] = { 8,5,2,6,9,3,1,4,0,7 };
	int n = sizeof(A) / sizeof(int);
	HeapSort(A, n);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;
	system("pause");
}