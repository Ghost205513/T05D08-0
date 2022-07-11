#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 1) {
        printf("n/a\n");
        return 1;
    }

    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

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

void output(int *a, int n) {
    printf("%d", *a);

    for (int i = 1; i < n; i++)
        printf(" %d", *(a + i));

    printf("\n");
}

int max(int *a, int n) {
    int ans = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > ans)
            ans = a[i];

    return ans;
}

int min(int *a, int n) {
    int ans = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] < ans)
            ans = a[i];

    return ans;
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

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("%d %d %.6lf %.6lf\n", max_v, min_v, mean_v, variance_v);
}
