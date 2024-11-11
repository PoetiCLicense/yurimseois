#include <stdio.h>

int linear_search(const int a[], int n, int key) {
    int i = 0;
    while (1) {
        if (i == n)
            return -1;
        if (a[i] == key)
            return i;
        i++;
    }
}

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    printf("%d", linear_search(a, 5, 4));

    return 0;
}



