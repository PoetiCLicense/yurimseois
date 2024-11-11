#include <stdio.h>

int Sentinel(int a[], int n, int key) {
    int i = 0;
    a[n] = key;

    while (1) {
        if (a[i] == key)
            break;
        i++;
    }
    return i == n ? -1 : i;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    printf("%d", Sentinel(a, 5, 6));

    return 0;
}