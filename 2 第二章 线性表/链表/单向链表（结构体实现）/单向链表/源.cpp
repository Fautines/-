#include <iostream>
#include<stdlib.h>
using namespace std;

struct LNode {
	int data;
	LNode* next;
};

//��������β�巨
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

//�������
void DispLNode(LNode** L) {
	LNode* p = *L;
	while (p->next != NULL) {
		cout << p->next->data << " ";
		p = p->next;
	}
	cout << endl;
}

//����
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
//ɾ��
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

//����
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
		cout << "���ҳɹ���" << e << "λ�ڵ�" << count << "λ" << endl;
	}
	else cout << "����ʧ��" << endl;
}

//����
void DesLNode(LNode** L) {
	LNode* p = *L, * q = (*L)->next;
	while (p != NULL) {
		free(p);
		p = q;
		q = q->next;
	}
}

//�ж��Ƿ�Ϊ�մ�
void NullLNode(LNode** L) {
	LNode* p = *L;
	if (p->next == NULL) cout << "�մ�" << endl;
	else cout << "���ǿմ�" << endl;
}

int main() {
	LNode* L;
	int a[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(a) / sizeof(a[0]);

	CreateLNode(&L, a, n);
	DispLNode(&L);
	NullLNode(&L);

	//����
	InsertLNode(&L, 2, 5);
	DispLNode(&L);

	//ɾ��
	DelLNode(&L, 2);
	DispLNode(&L);

	//����
	Sreach(&L, 5);

	//����
	DesLNode(&L);
	//NullLNode(&L);

	return 0;
}