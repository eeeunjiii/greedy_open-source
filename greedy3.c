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

		quo = m / k; //��(k�� ���� �� �ִ� �� ������ �� �ش��Ѵ�)
		rem = m % k; //������

		if (n < quo + rem) {
			printf("n�� ���� %d �̻� �ø�����\n\n", quo + rem - n);
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

			printf("���ĵ� �迭: ");
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
			printf("�׸��� �˰��� ���: %d\n\n", sum);

			printf("���α׷� ����(Y/N) : ");
			scanf("%c", &c);
			if (getchar() == 'Y') {
				return 0;
			}
			printf("\n");
		}
	}
}

//�������� ����
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