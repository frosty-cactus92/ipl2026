#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("Enter radius: ");
    scanf("%d" , &n);


    for(int i = 0;i<(2*n)+1;i++){
        for(int j = 0;j<(2*n)+1;j++){
            float dist = pow((i-n),2)+pow((j-n),2);
            if(dist <= n*n) printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
    return 0;
}