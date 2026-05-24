#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int* FormLPS(char* pat){
    int maxlen = 0;
    int n = strlen(pat);
    int* lp = malloc(n*sizeof(int));
    int i = 1;
    lp[0] = 0;
    while(i<n){
        if(pat[i] == pat[maxlen]){
            maxlen+=1;
            lp[i] = maxlen;
            i+=1;
        }
        else{
            if(maxlen!=0){
                maxlen = lp[maxlen-1];
                i+=1;
            }
            else{
                lp[i] = 0;
                i+=1;
            }
        }
    }

    
    return lp;
}
int main(){

    char s[100] , pat[100];
    printf("Enter string: ");
    scanf("%s" , s);

    printf("Enter pattern: ");
    scanf("%s" , pat);


    int* lps = FormLPS(pat);
    
    int i = 0;
    int j = 0;

    int* res = malloc(strlen(s));
    int* resptr = res;
    int reslen = 0;
    clock_t start = clock();
    while(i<strlen(s)){
        if(s[i] == pat[j]){
            i+=1;
            j+=1;

            if(j == strlen(pat)){
                *resptr = i-j;
                resptr++;
                reslen++;
                j = lps[j-1];
            }
        }
        else{
            if(j!=0){
                j = lps[j-1];
                i+=1;
            }
            else{
                i+=1;
            }
        }
    }
    clock_t end = clock();
    
    for(int i = 0;i<reslen;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
    printf("Time taken to perform scan: %f seconds\n" , (double)(end - start) / CLOCKS_PER_SEC);
    free(res);

    return 1;

}

/*Unlike scanning every character in s , creating a window of strlen(pat) everytime , we can speed up scanning , by continuing the scanning from
 a common suffix , saves signifance processing time , by making the reducing the worst case space time complexity from O(nxm) to O(n+m) */
