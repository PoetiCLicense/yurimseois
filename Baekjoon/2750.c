#include <stdio.h>
#include <stdlib.h>

// 비교 함수: 오름차순으로 정렬하기 위해 사용
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // qsort 함수를 사용하여 배열을 오름차순 정렬
    qsort(arr, N, sizeof(int), compare);

    // 정렬된 배열 출력
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
