#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
int search(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 1) {
        printf("n/a\n");

        return 1;
    }

    printf("%d\n", search(data, n));

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) == 0)
        return 1;

    for (int *p = a; p - a < *n; p++)
        if (scanf("%d", p) == 0)
            return 1;
    char trash = getchar();

    while (1) {
        if (trash != ' ' && trash != '\t')
            break;

        trash = getchar();
    }

    if (trash != '\n')
        return 1;

    return 0;
}

int search(int *a, int n) {
    double mean_v = mean(a, n);
    double sigma = sqrt(variance(a, n));
    for (int i = 0; i < n; i++)
        if (a[i] != 0 && a[i] % 2 == 0 && a[i] >= mean_v && a[i] <= mean_v + 3 * sigma)
            return a[i];
    return 0;
}

double mean(int *a, int n) {
    int ans = 0;

    for (int i = 0; i < n; i++)
        ans += a[i];

    return (double) ans / (double) n;
}

double variance(int *a, int n) {
    double mean = 0;
    double ans = 0;

    for (int i = 0; i < n; i++)
        mean += (double) a[i];

    mean /= (double) n;

    for (int i = 0; i < n; i++)
        ans += ((double) a[i] - mean) * ((double) a[i] - mean);

    return ans / (double) n;
}
