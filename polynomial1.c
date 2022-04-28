#include <stdio.h>
#define MAX(a,b) ((a>b)?(a):(b)) //a>b가 조건 ? 참일 경우 값 : 거짓일 경우 값
#define MAX_DEGREE 101

typedef struct {
	int degree; //차수 변수 선언
	float coef[MAX_DEGREE]; //계수 변수 선언(다항식의 전체 계수를 저장하므로 배열의 형태로)
}polynomial; //새로운 자료형 선언

polynomial polyAdd(polynomial A, polynomial B) {
	polynomial C;

	int Apos = 0, Bpos = 0, Cpos = 0; //각 다항식의 차수 변수 선언
	int degreeA = A.degree;
	int degreeB = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree) { //각 계산하는 차수가 최대 차수보다 커지기 전까지 계산 진행
		if (degreeA > degreeB) { //A의 차수가 B의 차수보다 크다면
			C.coef[Cpos] = A.coef[Apos]; //해당 차수에 해당하는 계수 대입 
			degreeA--; //한 차수 낮추기
			Cpos++;
			Apos++;
		}
		else if (degreeA == degreeB) { //차수가 동일하다면
			C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos]; //계수의 합 계산
			degreeA--; //한 차수 낮추기
			degreeB--; //한 차수 낮추기
			Cpos++;
			Apos++;
			Bpos++;
		}
		else { //B의 차수가 A의 차수보다 크다면
			C.coef[Cpos] = B.coef[Bpos]; //해당 차수에 해당하는 계수 대입
			degreeB--; //한 차수 낮추기
			Cpos++;
			Bpos++;
		}
	}
	return C; //계산한 다항식 반환
}

void printPoly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		if (!p.coef[p.degree - i]) continue; 
		//계수가 합으로 인해 0이 될 경우 고려(?), 이걸 지우면 계수가 0이어도 표시됨(continue가 있으면 밑에 있는 코드를 실행하지 않음)
		
		printf("%3.1lfx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1lf\n", p.coef[p.degree]); //상수항(배열의 0번째에 높은 차수의 계수가 들어있고 마지막 인덱스에 상수항이 있음)
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