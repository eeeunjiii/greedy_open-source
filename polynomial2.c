/*두 다항식의 합을 계산하는 프로그램(배열의 방향과 차수의 방향이 반대임을 유의)*/

#include <stdio.h>
#define MAX(a,b)((a>b)?(a):(b)) //조건식 ? 반환값1(조건식이 참인 경우) : 반환값2(조건식이 거짓인 경우)
#define MAX_DEGREE 10 //배열의 최대 인덱스 설정

typedef struct {
	int degree; //다항식 최대 차수
	float coef[MAX_DEGREE]; //각 차수에 대한 계수
}polynomial; //다항식의 최대 차수와 계수에 대한 구조체

polynomial polyAdd(polynomial A, polynomial B); //다항식의 합을 구하는 함수
void printPoly(polynomial p); //다항식을 출력하는 함수


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

	int degreeA = A.degree; //A의 최대 차수
	int degreeB = B.degree; //B의 최대 차수
	int indexA = 0, indexB = 0, indexC = 0; //0번째 인덱스에 최고차항의 계수가 들어감, 마지막 인덱스에 상수가 들어감

	C.degree = MAX(A.degree, B.degree);

	while (indexA <= A.degree && indexB <= B.degree) {
		if (degreeA > degreeB) {
			C.coef[indexC] = A.coef[indexA];
			degreeA--; //높은 차수 먼저 계산 후, 한 차수 낮추기
			indexC++; //다음 차수에 대한 계수를 저장할 인덱스 증가
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
		if (p.coef[p.degree - i] != 0) { //계수의 합이 0인 경우에는 출력되지 않음
			printf("%3.1lfx^%d + ", p.coef[p.degree - i], i);
		}
	}
	printf("%3.1lf\n\n", p.coef[p.degree]); //상수항
}
