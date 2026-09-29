#include<stdio.h>
void Hanoi_tower(int n, char A, char B, char C){
    if(n==0) return ;
    Hanoi_tower(n-1, A, C, B);
    printf("Chuyen dia %d tu cot %c sang cot %c \n", n, A, B);
    Hanoi_tower(n-1, C, B, A);
}
int main(){
    int n;
    scanf("%d", &n);
    Hanoi_tower(n , 'A', 'B', 'C');
    return 0;
}