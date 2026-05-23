#include<stdio.h>
#include<stdlib.h>
char* GetBites(int n){
    char *bits = malloc(33);
    char *bitsptr = bits;
    for(int i = 31;i>=0;i--){
        if(n&(1U<<i)) *bitsptr = '1';
        else *bitsptr = '0';
        bitsptr++;
    }
    *bitsptr = '\0';
    return bits;
}
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d" , &n);

    char *res = GetBites(n);
    printf("%s",res);
   

    return 0;
}