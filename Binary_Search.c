// 이진 검색
#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key)
{
    int left = 0;                     // 검색 범위 맨 앞의 인덱스
    int right = n - 1;                 // 검색 범위 맨 끝의 인덱스

    do {
        int center = (left + right) / 2;     // 검색 범위 한가운데의 인덱스
        if (a[center] == key)           // 검색 성공
            return center;
        else if (a[center] < key)
            left = center + 1;            // 검색 범위를 뒤쪽 절반으로 좁힘
        else
            right = center - 1;            // 검색 범위를 앞쪽 절반으로 좁힘
    } while (left <= right);
    return -1;                      // 검색 실패
}

int main(void) {
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int key = 6;

    printf("%d는 %d번째 원소입니다", key, bin_search(a, 7, key));
}