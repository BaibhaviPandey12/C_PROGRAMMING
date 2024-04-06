#include <stdio.h>

int main() {
    int a[10], k, j, temp, min, n, i, loc;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (k = 1; k <= n - 1; k++) {
        min = a[k];
        loc = k;

        for (j = k + 1; j <= n; j++) {
            if (min > a[j]) {
                min = a[j];
                loc = j;
            }
        }

        temp = a[k];
        a[k] = a[loc];
        a[loc] = temp;
    }

    printf("Sorted array in ascending order:\n");
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}

