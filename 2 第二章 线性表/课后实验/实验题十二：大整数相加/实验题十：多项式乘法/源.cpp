#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
	int num = 0;
	struct list* next;
}List;

void LinkList_reverse(List* L);
void insertList(List* tempList, int num);
void inputNumber();
void addNumber(List* list1, List* list2);
void insertList(List* tempList, int num);
void logList(List* list);
static List* initList();

static List* initList() {
	List* list = NULL;
	list = (List*)malloc(sizeof(List));
	if (list == NULL) {
		//printf("init failed---malloc failed");
		return NULL;
	}
	list->next = NULL;
	return list;
}

void inputNumber() {
	char c;
	List* num[2];
	for (int i = 0; i < 2; i++) {
		num[i] = initList();
		while ((c = getchar()) != '\n') {
			insertList(num[i], c - '0');
		}

	}
	LinkList_reverse(num[0]);
	LinkList_reverse(num[1]);

	printf("输入数据结束\n");
	//for debug
	logList(num[0]);
	logList(num[1]);
	addNumber(num[0], num[1]);

	//free
}

void addNumber(List* list1, List* list2) {
	List* result = initList();
	List* temp1 = list1;
	List* temp2 = list2;

	List* newList = NULL;

	List* temp = result;

	int bitInc = 0;			//进位
	while (temp1->next && temp2->next) {
		newList = initList();
		temp->next = newList;

		//printf("list1->num: %d and list2->num: %d", temp1->next->num, temp2->next->num);
		temp->next->num = (temp1->next->num + temp2->next->num + bitInc) % 10;
		//printf(" temp->num: %d\n", temp->next->num);
		bitInc = (temp1->next->num + temp2->next->num + bitInc) / 10;

		temp1 = temp1->next;
		temp2 = temp2->next;

		temp = temp->next;
	}

	while (temp1->next) {
		newList = initList();
		temp->next = newList;

		temp->next->num = (temp1->next->num + bitInc) % 10;
		bitInc = (temp1->next->num + bitInc) / 10;
		temp1 = temp1->next;

		temp = temp->next;
	}
	while (temp2->next) {
		newList = initList();
		temp->next = newList;

		temp->next->num = (temp2->next->num + bitInc) % 10;
		bitInc = (temp2->next->num + bitInc) / 10;
		temp2 = temp2->next;

		temp = temp->next;
	}

	if (bitInc > 0) {
		newList = initList();
		temp->next = newList;

		temp->next->num = bitInc;
		temp = temp->next;
	}

	//end
	LinkList_reverse(result);
	logList(result);
}

void insertList(List* tempList, int num) {
	List* temp = initList();
	List* head = tempList;

	if (temp != NULL) {
		temp->num = num;
	}

	while (head->next) {
		head = head->next;
	}
	if (head->next == NULL) {
		head->next = temp;
	}
}

void logList(List* list) {
	//printf("进入log......\n");
	List* temp = NULL;
	temp = list;
	if (temp->next == NULL) {
		//printf("list is null-----log\n");
	}
	while (temp->next)
	{
		printf("%d", temp->next->num);
		temp = temp->next;
	}
	printf("\n");
}

void LinkList_reverse(List* L)
{
	List* p = L->next;
	List* q;
	L->next = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		q->next = L->next;
		L->next = q;
	}
}


int main()
{
	inputNumber();

	return 0;
}
