#include<stdio.h>
typedef struct{
    int a;
    char str[50];
}NoBitField;

typedef struct{
    int a:5;
    int b:3;
}BitField;


int main(){

    NoBitField s1;
    printf("Size of no bitfield specified structure: %zu\n" , sizeof(s1));
    //Output here is 6 , since compilers usually pad the size out to make instances of arrays of this structure more aligned
    BitField s2 = {10,10};
    printf("%d %d" , s2.a,s2.b);
    /*You need 4 bytes to represent 10 (1010) , but since the specified bitfield is only 3 , it simply reads the first 3(Following little endian).\
    and is instead stores as (010) , which is 2 , compilers also throw a warning to users when this happens
    
    Additionally , since you can represent numbers from -4 to +3 using bits , 
        (100) -> -4
        (101) -> -3
        (110) -> -2
        (111) -> -1
    
    hence , assigning s2.b to a number like 7 , will result in it storing -1 , as a result of the bitfield constraining the amount of it bits it can store.
    */
    


}