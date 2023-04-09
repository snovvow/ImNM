#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
함수 이름: main
기능: 정수 배열 source1[]와 source2[]의 원소를 출력하고 원소 값의 제곱의 차
destination[]를 출력한다. 인자: 없음 반환값: 0 -> 정상 종료 작성 일자:2022/05/10
*/

void get_square_diff(int src1[], int src2[], int destination[], int len);

int main(void) {
    int source1[5] = {3, 2, -2, 8, -5};
    int source2[5] = {-7, -2, 3, -1, 6};
    int destination[5];
    int len = 5;
    int i;

    printf("source1:");
    for (i = 0; i < len; i++) // source1 배열 출력
    {
        printf(" %d", source1[i]);
    }
    printf("\n");

    printf("source2:");
    for (i = 0; i < len; i++) // source2 배열 출력
    {
        printf(" %d ", source2[i]);
    }
    printf("\n");

    get_square_diff(source1, source2, destination, len);

    printf("destination:");
    for (i = 0; i < len; i++) //원소 값의 제곱의 차인 destination 배열 출력
    {
        printf(" %d ", destination[i]);
    }

    return 0;
}

/*
함수 이름: get_square_diff
기능: 두 배열의 원소 값의 제곱의 차를 계산하고 destination[]에 저장한다.
인자: src1[], src2[], destination[], len
반환값: 없음
작성 일자:2022/05/10
*/

void get_square_diff(int src1[], int src2[], int destination[], int len) {
    int i;

    for (i = 0; i < len; i++)
        ;
    {
        destination[i] =
            abs(pow(src1[i], 2) - pow(src2[i], 2)); //각 원소를 제곱해서 뺄셈
    }
    // destination 반환
}