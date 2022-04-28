#include <stdio.h>
#define MAX(a,b) ((a>b)?(a):(b)) //a>b�� ���� ? ���� ��� �� : ������ ��� ��
#define MAX_DEGREE 101

typedef struct {
	int degree; //���� ���� ����
	float coef[MAX_DEGREE]; //��� ���� ����(���׽��� ��ü ����� �����ϹǷ� �迭�� ���·�)
}polynomial; //���ο� �ڷ��� ����

polynomial polyAdd(polynomial A, polynomial B) {
	polynomial C;

	int Apos = 0, Bpos = 0, Cpos = 0; //�� ���׽��� ���� ���� ����
	int degreeA = A.degree;
	int degreeB = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree) { //�� ����ϴ� ������ �ִ� �������� Ŀ���� ������ ��� ����
		if (degreeA > degreeB) { //A�� ������ B�� �������� ũ�ٸ�
			C.coef[Cpos] = A.coef[Apos]; //�ش� ������ �ش��ϴ� ��� ���� 
			degreeA--; //�� ���� ���߱�
			Cpos++;
			Apos++;
		}
		else if (degreeA == degreeB) { //������ �����ϴٸ�
			C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos]; //����� �� ���
			degreeA--; //�� ���� ���߱�
			degreeB--; //�� ���� ���߱�
			Cpos++;
			Apos++;
			Bpos++;
		}
		else { //B�� ������ A�� �������� ũ�ٸ�
			C.coef[Cpos] = B.coef[Bpos]; //�ش� ������ �ش��ϴ� ��� ����
			degreeB--; //�� ���� ���߱�
			Cpos++;
			Bpos++;
		}
	}
	return C; //����� ���׽� ��ȯ
}

void printPoly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		if (!p.coef[p.degree - i]) continue; 
		//����� ������ ���� 0�� �� ��� ���(?), �̰� ����� ����� 0�̾ ǥ�õ�(continue�� ������ �ؿ� �ִ� �ڵ带 �������� ����)
		
		printf("%3.1lfx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1lf\n", p.coef[p.degree]); //�����(�迭�� 0��°�� ���� ������ ����� ����ְ� ������ �ε����� ������� ����)
}

int main(void) {
	polynomial a = { 4,{4,3,1,0,2} };
	polynomial b = { 3,{2,6,1,1} };
	polynomial c;

	printPoly(a);
	printPoly(b);
	c = polyAdd(a, b);
	printPoly(c);
	gets();

	return 0;
}