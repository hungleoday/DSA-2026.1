#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int count=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]==0) count++;
    }
    int one=count;
    while(count--) a[count]=0;
    for(int i=0;i<one;i++) a[n-one+i]=1;
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}