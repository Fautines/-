#include <iostream>
#include<stdlib.h>
using namespace std;

struct LNode {
	int data;
	LNode* next;
};

//创建链表：尾插法
void CreateLNode(LNode** L, int a[], int n) {
	LNode* s, * r;
	*L = (LNode*)malloc(sizeof(LNode));
	r = *L;
	for (int i = 0;i < n;i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

//输出链表
void DispLNode(LNode** L) {
	LNode* p = *L;
	while (p->next != NULL) {
		cout << p->next->data << " ";
		p = p->next;
	}
	cout << endl;
}

//插入
void InsertLNode(LNode** L, int n, int e) {
	LNode* p = *L;
	for (int i = 0;i < n - 1 && p != NULL;) {
		p = p->next;
		i++;
	}
	if (p == NULL) cout << "error!" << endl;
	else {
		LNode* q, * s = (LNode*)malloc(sizeof(LNode));
		s->data = e;

		q = p->next;
		s->next = q;
		p->next = s;
	}
}
//删除
void DelLNode(LNode** L, int n) {
	LNode* p = *L;
	for (int i = 0;i < n - 1 && p != NULL;) {
		p = p->next;
		i++;
	}
	if (p == NULL) cout << "error!" << endl;
	else {
		LNode* q = p->next;
		p->next = q->next;
	}
}

//查找
void Sreach(LNode** L, int e) {
	LNode* p = *L;
	int count = 0, flag = 0;
	while (p->next != NULL) {
		if (p->next->data == e) {
			flag = 1;
			break;
		}
		else p = p->next;
		count++;
	}
	if (flag != 0) {
		cout << "查找成功，" << e << "位于第" << count << "位" << endl;
	}
	else cout << "查找失败" << endl;
}

//销毁
void DesLNode(LNode** L) {
	LNode* p = *L, * q = (*L)->next;
	while (p != NULL) {
		free(p);
		p = q;
		q = q->next;
	}
}

//判断是否为空串
void NullLNode(LNode** L) {
	LNode* p = *L;
	if (p->next == NULL) cout << "空串" << endl;
	else cout << "不是空串" << endl;
}

int main() {
	LNode* L;
	int a[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(a) / sizeof(a[0]);

	CreateLNode(&L, a, n);
	DispLNode(&L);
	NullLNode(&L);

	//插入
	InsertLNode(&L, 2, 5);
	DispLNode(&L);

	//删除
	DelLNode(&L, 2);
	DispLNode(&L);

	//查找
	Sreach(&L, 5);

	//销毁
	DesLNode(&L);
	//NullLNode(&L);

	return 0;
}