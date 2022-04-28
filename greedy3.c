/*n>=quo+rem*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* sort(int array[], int size);

int main(void) {
	int n = 0, m = 0, k = 0;
	int quo = 0, rem = 0;
	int sum = 0;
	char c;

	while(1){

		printf("n(2~1000) m(1~10000) k(1~10000)\n");
		scanf("%d %d %d", &n, &m, &k);

		quo = m / k; //몫(k번 더할 수 있는 총 개수는 몫에 해당한다)
		rem = m % k; //나머지

		if (n < quo + rem) {
			printf("n의 값을 %d 이상 늘리세요\n\n", quo + rem - n);
		}

		else {
			int* arr = malloc(sizeof(int) * n);

			srand((unsigned)time(NULL));

			for (int i = 0; i < n; i++) {
				arr[i] = rand() % 10000 + 1; //1~10,000
				printf("%d ", arr[i]);
			}
			printf("\n");

			*arr = *sort(arr, n);

			printf("정렬된 배열: ");
			for (int i = 0; i < n; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");

			for (int i = 0; i < quo; i++) {
				sum += arr[i] * k;
				if (i == quo - 1) {
					sum += arr[i + 1] * rem;
				}
			}
			printf("그리디 알고리즘 결과: %d\n\n", sum);

			printf("프로그램 종료(Y/N) : ");
			scanf("%c", &c);
			if (getchar() == 'Y') {
				return 0;
			}
			printf("\n");
		}
	}
}

//내림차순 정렬
int* sort(int array[], int size) {
	int temp = 0;

	for (int i = 0; i < size; i++) {
		for (int i = 0; i < size; i++) {
			if (array[i] < array[i + 1]) {
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
	return array;
}