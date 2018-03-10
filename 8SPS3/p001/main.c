#include <stdio.h>
void f(int *p, int tam);
void g(int *b, int *e);

int main() {
	int m[5] = {10,20,30,40,50};
	f(m, 5);
	g(m, m+5);

}

void f(int *p, int tam) {
	for (int i = 0; i < tam; ++i) {
		printf("m[%d] = %d\n", i, p[i]);
	}
}

void g(int *b, int *e) {
	for (int *i = b; i != e; ++i) {
		printf("m[%d] = %d", i - b, *i);
	}
}
