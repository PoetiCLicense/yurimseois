#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

long long minEnergy(int arr[], int sortedArr[], int n) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    long long totalEnergy = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || arr[i] == sortedArr[i])
            continue;

        int cycleEnergy = 0;
        int cycleMin = 1000001;
        int cycleSize = 0;
        int x = i;

        while (!visited[x]) {
            visited[x] = 1;
            cycleEnergy += arr[x];
            if (arr[x] < cycleMin)
                cycleMin = arr[x];
            cycleSize++;

            for (int j = 0; j < n; j++) {
                if (arr[x] == sortedArr[j]) {
                    x = j;
                    break;
                }
            }
        }

        int method1 = cycleEnergy + (cycleSize - 2) * cycleMin;
        int method2 = cycleEnergy + cycleMin + (cycleSize + 1) * sortedArr[0];
        totalEnergy += method1 < method2 ? method1 : method2;
    }
    return totalEnergy;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sortedArr[n];
    for (int i = 0; i < n; i++) {
        sortedArr[i] = arr[i];
    }
    qsort(sortedArr, n, sizeof(int), compare);

    printf("%lld\n", minEnergy(arr, sortedArr, n));
    return 0;
}
