#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE* next;
};

void addFirst(struct NODE* target, int data);

int main(void)
{
	struct NODE* head = malloc(sizeof(struct NODE));
	head->next = NULL;

	addFirst(head, 10);
	addFirst(head, 20);
	addFirst(head, 30);

	struct NODE* curr = head->next;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	curr = head->next;
	while (curr != NULL)
	{
		struct NODE* next = curr->next;
		free(curr);
		curr = next;
	}
	return 0;

}
void addFirst(struct NODE* target, int data) //�� ��� ���� ù ��°�� target = head
{
	struct NODE* newNode = malloc(sizeof(struct NODE));
	newNode->next = target->next;
	newNode->data = data;

	target->next = newNode; //�� ��带 ����
}