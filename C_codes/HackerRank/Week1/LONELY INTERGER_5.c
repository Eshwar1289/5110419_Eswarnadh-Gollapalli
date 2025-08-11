LONELY INTERGER

#include <stdio.h>

int lonelyinteger(int a_count, int* a){
    int result = 0;
    for (int i = 0; i < a_count; i++){
    result ^= a[i];
    }
    return result;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int result = lonelyinteger(n,arr);
    printf("%d\n", result);
    return 0;
}