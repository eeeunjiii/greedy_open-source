#include <stdio.h>

int multiply(int n); // 입력받은 정수를 함수에 대입

int main(void) {
	int n = 0, testcase = 0;
	int c;

	printf("test case: ");
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {

		printf("N: ");
		scanf("%d", &n);

		c = multiply(n);
		if (c == 0) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
		}
	}
	return 0;
}

int multiply(int n) {

	int count = 0;

	for (int a = 1; a <= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			if (n == a * b) {
				count++;
			}
		}
	}
	return count;
}