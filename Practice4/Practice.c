#include <stdio.h>
#include <conio.h>
#include <math.h>

const double PI = 3.14159265358979323846;

void sinus();
void cosinus();

float radian(float x) {
	return (x * PI / 180);
}

void clearInputBuffer() {
	char c;
	while ((c = getchar()) != '\n');
}

int main() {
	char ex, choice, err, c;
	do {
		do {
			err = 0;
			printf("Choice 1-sin, 2-cos: ");
			if (scanf_s("%hhd", &choice) != 1) {
				err = 1;
				printf("Invalid input, enter only numbers\n");
				clearInputBuffer();
				continue;
			}
			while ((c = getchar()) == ' ' || c == '\t');
			if (c != '\n') {
				err = 1;
				printf("Invalid input, enter only numbers\n");
				clearInputBuffer();
				continue;
			}
			switch (choice)
			{
			case 1:
				sinus();
				break;
			case 2:
				cosinus();
				break;
			default:
				printf("You have selected a non-existent option.\n");
				err = 1;
				break;
			}
		} while (err != 0);
		printf("\nEnter ESC to Exit(Enter to continue)\n");
		ex = _getch();
	} while (ex != 27);
	return 0;
}

void sinus() {
	char err, c;
	int n;	
	float x1, x2, dx, e, delta, x, rad, sum, real;

	do {
		err = 0;
		printf("x1=");
		if (scanf_s("%f", &x1) != 1) {
			err = 1;
			printf("Invalid input, enter only numbers\n");
			clearInputBuffer();
			continue;
		}
		while ((c = getchar()) == ' ' || c == '\t');
		if (c != '\n') {
			err = 1;
			printf("Invalid input, enter only numbers\n");
			clearInputBuffer();
			continue;
		}
	} while (err != 0);

	do {
		err = 0;
		printf("x2=");
		if (scanf_s("%f", &x2) != 1) {
			err = 1;
			printf("Invalid input, enter only numbers\n");
			clearInputBuffer();
			continue;
		}
		while ((c = getchar()) == ' ' || c == '\t');
		if (c != '\n') {
			err = 1;
			printf("Invalid input, enter only numbers\n");
			clearInputBuffer();
			continue;
		}
	} while (err != 0);

	do {
		err = 0;
		printf("dx=");
		if (scanf_s("%f", &dx) != 1) {
			err = 1;
			printf("Invalid input, enter only numbers\n");
			clearInputBuffer();
			continue;
		}
		while ((c = getchar()) == ' ' || c == '\t');
		if (c != '\n') {
			err = 1;
			printf("Invalid input, enter only numbers\n");
			clearInputBuffer();
			continue;
		}
		else if (x1 != x2 && dx == 0) {
			err = 1;
			printf("dx can't be zero when x1 is not equal to x2\n");
		}
		else if (x1 > x2 && dx > 0) {
			err = 1;
			printf("When x1>x2, dx must be negative\n");
		}
		else if (x1 < x2 && dx < 0) {
			err = 1;
			printf("When x1<x2, dx must be positive\n");
		}
	} while (err != 0);

	do {
		err = 0;
		printf("epsilon=");
		if (scanf_s("%f", &e) != 1) {
			err = 1;
			printf("Invalid input, enter only numbers\n");
			clearInputBuffer();
			continue;
		}
		while ((c = getchar()) == ' ' || c == '\t');
		if (c != '\n') {
			err = 1;
			printf("Invalid input, enter only numbers\n");
			clearInputBuffer();
			continue;
		}
		else if (e <= 0) {
			err = 1;
			printf("epsilon must be greater than zero\n");
		}
	} while (err != 0);

	printf("\t\t---x---\t\t---sin(x)---\t\t---sin_t---\t\t---sin_x-sin_t---\n");

	for (x = x1; (dx > 0) ? (x <= x2 + 1e-4f) : (x >= x2 - 1e-4f); x += dx) {
		rad = radian(x);
		delta = rad;
		sum = rad;
		n = 1;
		do {
			delta = delta * (-rad * rad) / ((n + 1) * (n + 2));
			sum += delta;
			n += 2;
		} while (fabs(delta) >= e);

		real = sinf(rad);
		printf("\t\t%f\t\t%f\t\t%f\t\t%f\n", x, real, sum, real - sum);

		if (dx == 0) break;
	}
}


void cosinus() {
	return;
}