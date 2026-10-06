#include <stdio.h>
#define dia_max 18
typedef struct {
    int n;
    char nguon;
    char giua;
    char dich;
    int buoc;
} sapxep;
void Hanoi_tower(int n, char nguon, char giua, char dich){
    sapxep nganXep[dia_max];
    int dinh = 0;
    nganXep[dinh] = (sapxep){n, nguon, giua, dich, 0};
    while (dinh >= 0){
        sapxep viec = nganXep[dinh];
        if (viec.n == 1){
            printf("Chuyen dia 1 tu cot %c sang cot %c\n", viec.nguon, viec.dich);
            dinh--;
        }
        else if (viec.buoc == 0){
            nganXep[dinh].buoc = 1;
            dinh++;
            nganXep[dinh] = (sapxep){viec.n - 1, viec.nguon, viec.dich, viec.giua, 0};
        }
        else if (viec.buoc == 1){
            printf("Chuyen dia %d tu cot %c sang cot %c\n",
                   viec.n, viec.nguon, viec.dich);
            nganXep[dinh].buoc = 2;
            dinh++;
            nganXep[dinh] = (sapxep){viec.n - 1, viec.giua, viec.nguon, viec.dich, 0};
        } 
        else dinh--;
    }
}
int main(void){
    int n;
    printf("Nhap so dia: ");
    scanf("%d", &n);
    Hanoi_tower(n, 'A', 'B', 'C');
    return 0;
}

