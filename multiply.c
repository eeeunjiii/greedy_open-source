#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int n = 0;
	int testcase = 0;
	bool exitLoop = false;

	printf("test case: ");
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		printf("N: ");
		scanf("%d", &n);

		for (int a = 1; a <= 9; a++) {
			for (int b = 1; b <= 9; b++) {
				if (n == a * b) {
					printf("Yes\n");
					exitLoop = true;
					break;
				}
			}
			if (exitLoop == true) {
				break;
			}
		}
		if (exitLoop == false) {
			printf("No\n");
		}
		else exitLoop = false;
	}
	return 0;
}