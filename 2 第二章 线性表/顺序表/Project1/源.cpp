//顺序表的实现
#include<iostream>
using namespace std;
#define MAX_SIZE 100//默认长度

//定义顺序表
typedef struct {
	int *data;   //顺序表基地址
	int length;  //顺序表长度
	int MaxSize;   //顺序表总空间大小
}sqlist;


//初始化顺序表
void InitList(sqlist& L) {
	L.data = (int*)malloc(MAX_SIZE * sizeof(int));
	L.length = 0;
	L.MaxSize = MAX_SIZE;
}


//动态增加长度
void IncreaseSize(sqlist& L, int len) {//增加长度len
	int* p = L.data;
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));//申请一块更大的连续空间
	for (int i = 0;i < L.length;i++) {//复制数据
		L.data[i] = p[i];
	}
	L.MaxSize += len;
	free(p);//将原来的内存释放
}

//销毁顺序表
void sqlistDestory(sqlist* L) {
	if (L == NULL)return;
	else {
		free(L->data);
		L->data = NULL;
		L->length = 0;
		L->MaxSize = 0;
	}

}


//判断顺序表是否为空表
bool ListEmpty(sqlist* L) {
	return (L->length);
}


//求顺序表的长度
int ListLength(sqlist* L){
	return (L->length);
}


//输出顺序表
void SeqListPrint(const sqlist* L)
{
	
	if (L->length==0)  //判断顺序表是否为空
	{
		printf("顺序表为空,无法输出元素\n");
		return;
	}

	int i = 0;
	for (i = 0; i < L->length; i++)  //打印顺序表
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}


//按元素值查找
int LocateElem(sqlist L, int e) {//找到第一个等于e的元素，返回其位序
	for (int i = 0;i < L.length;i++) 
		if (L.data[i] == e)return i + 1;
	return 0;
}

//插入数据元素
bool ListInsert(sqlist& L, int i, int e) {//将数值为e的值插入到次序为i的后面
	if (i<1 || i>L.length + 1)return false;
	if (L.length >= L.MaxSize)return false;
	for (int j = L.length;j >= i;j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//尾插数据表
void SeqListPushBack(sqlist* L, int x)
{
	if (L->length == L->MaxSize) {//顺序表容量满了
		IncreaseSize(*L, 10);
	}
	
	L->data[L->length] = x;  //尾插数据
	L->length++;  //有效数据个数+1
}


//删除数据元素
bool ListDelete(sqlist& L, int i, int& e) {//删除次序为i的元素
	if (i<1 || i>L.length + 1)return false;
	e = L.data[i - 1];//带回被删除的值
	for (int j = i;j < L.length;j++)
		L.data[j - 1] = L.data[j];//此处直接让后面的数据覆盖前面的数据
	L.length--;//删除最后一个数据
	return true;
}

//主函数

int main() {
	sqlist L;//声明一个顺序表
	InitList(L);//初始化一个顺序表
	for (int i = 1;i < 10;i++) {
		SeqListPushBack(&L, i);
	}

	IncreaseSize(L,10);//顺序表的长度增长n个
	
	bool flag = ListEmpty(&L);//判断顺序表是否为空表
	if (flag)cout << "非空顺序表"<<endl;
	else cout << "空顺序表" << endl;

	
	int len = ListLength(&L);//求顺序表的长度
	cout << "顺序表的长度为" << len<<endl;

	SeqListPrint(&L);//输出顺序表



	int e = LocateElem(L, 4); //找到第一个等于4的元素，返回其位序
	if (e == 0)cout << "在顺序表中没有找到一个等于4的元素"<<endl;
	else cout << "在顺序表中第一个等于4的元素的位序是" << e << endl;

	flag = ListInsert(L, 2, 4);//将数值为4的值插入到次序为2的后面
	if (flag)cout << "插入成功！" << endl;
	else cout << "插入失败！" << endl;

	flag = ListDelete(L, 2, e);//删除次序为i的元素
	if (flag)cout << "删除成功！删除的元素值为"<<e << endl;
	else cout << "删除失败！" << endl;
	

	sqlistDestory(&L);//销毁一个顺序表
}
