/*�� ���׽��� ���� ����ϴ� ���α׷�(�迭�� ����� ������ ������ �ݴ����� ����)*/

#include <stdio.h>
#define MAX(a,b)((a>b)?(a):(b)) //���ǽ� ? ��ȯ��1(���ǽ��� ���� ���) : ��ȯ��2(���ǽ��� ������ ���)
#define MAX_DEGREE 10 //�迭�� �ִ� �ε��� ����

typedef struct {
	int degree; //���׽� �ִ� ����
	float coef[MAX_DEGREE]; //�� ������ ���� ���
}polynomial; //���׽��� �ִ� ������ ����� ���� ����ü

polynomial polyAdd(polynomial A, polynomial B); //���׽��� ���� ���ϴ� �Լ�
void printPoly(polynomial p); //���׽��� ����ϴ� �Լ�


int main(void) {
	polynomial a = { 4, {3, 1, 5, 0, 0} };
	polynomial b = { 6, {5, 2, 0, 1, 7, 3, 8} };
	polynomial c;

	printPoly(a);
	printPoly(b);
	c = polyAdd(a, b);
	printPoly(c);

	return 0;
}

polynomial polyAdd(polynomial A, polynomial B) {
	polynomial C;

	int degreeA = A.degree; //A�� �ִ� ����
	int degreeB = B.degree; //B�� �ִ� ����
	int indexA = 0, indexB = 0, indexC = 0; //0��° �ε����� �ְ������� ����� ��, ������ �ε����� ����� ��

	C.degree = MAX(A.degree, B.degree);

	while (indexA <= A.degree && indexB <= B.degree) {
		if (degreeA > degreeB) {
			C.coef[indexC] = A.coef[indexA];
			degreeA--; //���� ���� ���� ��� ��, �� ���� ���߱�
			indexC++; //���� ������ ���� ����� ������ �ε��� ����
			indexA++;
		}

		else if (degreeA == degreeB) {
			C.coef[indexC] = A.coef[indexA] + B.coef[indexB];
			degreeA--;
			degreeB--;
			indexC++;
			indexA++;
			indexB++;
		}
		else {
			C.coef[indexC] = B.coef[indexB];
			degreeB--;
			indexC++;
			indexB++;
		}
	}
	return C;
}

void printPoly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		if (p.coef[p.degree - i] != 0) { //����� ���� 0�� ��쿡�� ��µ��� ����
			printf("%3.1lfx^%d + ", p.coef[p.degree - i], i);
		}
	}
	printf("%3.1lf\n\n", p.coef[p.degree]); //�����
}
