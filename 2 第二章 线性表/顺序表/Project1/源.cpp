//˳����ʵ��
#include<iostream>
using namespace std;
#define MAX_SIZE 100//Ĭ�ϳ���

//����˳���
typedef struct {
	int *data;   //˳������ַ
	int length;  //˳�����
	int MaxSize;   //˳����ܿռ��С
}sqlist;


//��ʼ��˳���
void InitList(sqlist& L) {
	L.data = (int*)malloc(MAX_SIZE * sizeof(int));
	L.length = 0;
	L.MaxSize = MAX_SIZE;
}


//��̬���ӳ���
void IncreaseSize(sqlist& L, int len) {//���ӳ���len
	int* p = L.data;
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));//����һ�����������ռ�
	for (int i = 0;i < L.length;i++) {//��������
		L.data[i] = p[i];
	}
	L.MaxSize += len;
	free(p);//��ԭ�����ڴ��ͷ�
}

//����˳���
void sqlistDestory(sqlist* L) {
	if (L == NULL)return;
	else {
		free(L->data);
		L->data = NULL;
		L->length = 0;
		L->MaxSize = 0;
	}

}


//�ж�˳����Ƿ�Ϊ�ձ�
bool ListEmpty(sqlist* L) {
	return (L->length);
}


//��˳���ĳ���
int ListLength(sqlist* L){
	return (L->length);
}


//���˳���
void SeqListPrint(const sqlist* L)
{
	
	if (L->length==0)  //�ж�˳����Ƿ�Ϊ��
	{
		printf("˳���Ϊ��,�޷����Ԫ��\n");
		return;
	}

	int i = 0;
	for (i = 0; i < L->length; i++)  //��ӡ˳���
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}


//��Ԫ��ֵ����
int LocateElem(sqlist L, int e) {//�ҵ���һ������e��Ԫ�أ�������λ��
	for (int i = 0;i < L.length;i++) 
		if (L.data[i] == e)return i + 1;
	return 0;
}

//��������Ԫ��
bool ListInsert(sqlist& L, int i, int e) {//����ֵΪe��ֵ���뵽����Ϊi�ĺ���
	if (i<1 || i>L.length + 1)return false;
	if (L.length >= L.MaxSize)return false;
	for (int j = L.length;j >= i;j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//β�����ݱ�
void SeqListPushBack(sqlist* L, int x)
{
	if (L->length == L->MaxSize) {//˳�����������
		IncreaseSize(*L, 10);
	}
	
	L->data[L->length] = x;  //β������
	L->length++;  //��Ч���ݸ���+1
}


//ɾ������Ԫ��
bool ListDelete(sqlist& L, int i, int& e) {//ɾ������Ϊi��Ԫ��
	if (i<1 || i>L.length + 1)return false;
	e = L.data[i - 1];//���ر�ɾ����ֵ
	for (int j = i;j < L.length;j++)
		L.data[j - 1] = L.data[j];//�˴�ֱ���ú�������ݸ���ǰ�������
	L.length--;//ɾ�����һ������
	return true;
}

//������

int main() {
	sqlist L;//����һ��˳���
	InitList(L);//��ʼ��һ��˳���
	for (int i = 1;i < 10;i++) {
		SeqListPushBack(&L, i);
	}

	IncreaseSize(L,10);//˳���ĳ�������n��
	
	bool flag = ListEmpty(&L);//�ж�˳����Ƿ�Ϊ�ձ�
	if (flag)cout << "�ǿ�˳���"<<endl;
	else cout << "��˳���" << endl;

	
	int len = ListLength(&L);//��˳���ĳ���
	cout << "˳���ĳ���Ϊ" << len<<endl;

	SeqListPrint(&L);//���˳���



	int e = LocateElem(L, 4); //�ҵ���һ������4��Ԫ�أ�������λ��
	if (e == 0)cout << "��˳�����û���ҵ�һ������4��Ԫ��"<<endl;
	else cout << "��˳����е�һ������4��Ԫ�ص�λ����" << e << endl;

	flag = ListInsert(L, 2, 4);//����ֵΪ4��ֵ���뵽����Ϊ2�ĺ���
	if (flag)cout << "����ɹ���" << endl;
	else cout << "����ʧ�ܣ�" << endl;

	flag = ListDelete(L, 2, e);//ɾ������Ϊi��Ԫ��
	if (flag)cout << "ɾ���ɹ���ɾ����Ԫ��ֵΪ"<<e << endl;
	else cout << "ɾ��ʧ�ܣ�" << endl;
	

	sqlistDestory(&L);//����һ��˳���
}
