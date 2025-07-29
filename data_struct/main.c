#include "recursive.h"
#define MAX 5
int N = MAX;
int visit[5];
int arr[MAX];

void test_14(int visit[], int max, int current_len, int target_len, char sequence[]) {
    if (current_len == target_len) {
        sequence[current_len] = '\0';
        printf("%s\n", sequence);
    }

    for (int i = 1; i <= max; i++) {
        if (visit[i] == 0) {
            visit[i] = 1;

            sequence[current_len] = i + '0';
            test_14(visit, max, current_len + 1, target_len, sequence);

            visit[i] = 0;
        }
    }

}
static void printAry(int L) {
    for (int i = 1; i <= L; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");

    return;
}
void test_13(int * visit, int L) {
    if (L > N) {
        printAry(L);
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visit[i] == 0) {
            visit[i] = 1;

            arr[L] = i;
            test_13(visit, L + 1);

            visit[i] = 0;
        }
    }
}
void test_12() {
    for (int i = 1; i <= 3; i++)
    {
        visit[i] = 1;
        for (int j = 1; j <= 3; j++)
        {
            if (!visit[j]) {
                visit[j] = 1;
                for (int k = 1; k <= 3; k++)
                {
                    if (!visit[k]) {
                        visit[k] = 1;
                        printf("%d %d %d\n", i, j, k);
                        visit[k] = 0;
                    }
                }
                visit[j] = 0;
            }
        }
        visit[i] = 0;
    }
}
void MakeCase() { //P(n,r)
    int cnt = 1;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (j == i) continue;
            for (int k = 1; k <= 4; k++) {
                if (k == j || k == i) continue;
                printf("%d %d %d cnt : %d\n", i, j, k, cnt);
                cnt++;
            }
        }
    }
}
void printStar(int n) {

    for (int i = 0; i < 6 - n; i++) {
        printf(" ");
    }

    for (int i = 0; i < 2 * n - 1; i++) {
        printf("*");
    }
    printf("\n");
}
void test_10(int L)
{
    if (L > 5) return;
    printStar(L);
    test_10(L + 1);
    if(L != 5 ) printStar(L);
}
void test_09(int L)
{
    if (L > 5) return;
    for (int i = 0; i < L; i++)
    {
        printf("*");
    }
    printf("\n");
    test_09(L + 1);
}
void test_08(int L)
{
    if (L > 5) return;
    printf("%d ", L);
    test_08(L + 1);
    printf("%d ", 5 - L + 1);
}
void test_07(int L)
{
    if (L > 5) return;
    printf("%d ", L);
    test_07(L + 1);
    printf("%d ", 6 - L);
}
void test_06(int L)
{
    if (L > 5) return;
    printf("%d ", L);
    test_06(L + 1);
    if (L != 5) printf("%d ", L);

}
void test_05(int L)
{
    if (L > 5) return;
    printf("%d ", L);
    test_05(L + 1);
    printf("%d ", L);
}
void test_04(int L)
{
    if (L > 5) return;
    test_04(L + 1);
    printf("%d ", L);
}
void test_03(int L)
{
    printf("%d ", L);
    if (L >= 5) return;
    test_03(L + 1);
}
void test_03_b(int start) {
    
    if (start == 5) return;
    
    printf("%d ", start);

    test_03_b(start + 1);
}
void test_02(int L)
{
    test_02(L + 1);
    printf("%d ", L);
}
void test_01(int L, int a, int b, double c)
{
    //int a[100] = { 0 }
    printf("%d ", L);
    test_01(L + 1, 1, 2, 3);
}

//
//int main() {
//    //test_10(1);
//    //MakeCase();
//    //test_12();
//    /*int max = 4;
//    char sequence[4];
//    int current_len = 0;
//    int target_len = 3;
//    test_13(visit, max, current_len, target_len, sequence);*/
//    int visit[4] = { 0 };
//    test_13(visit, 5);
//    return 0;
//}