#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char name[50];
    float gpa;
}Student;

void ReadIntoTextFile(char filename[] , Student s[] , int n){
    FILE *fp = fopen(filename , "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    for(int i = 0;i<n;i++){
        fwrite(&s[i] , sizeof(Student) , 1 ,fp);
    }
    fclose(fp);


}
void ReadFromTextFile(char filename[]){
    FILE *fp = fopen(filename , "r");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    Student t;
    int n;
    printf("Enter the nth record you need: ");
    scanf("%d" , &n);
    fseek(fp , (n-1)*sizeof(Student) , SEEK_SET);
    
    fread(&t , sizeof(Student) , 1 , fp);
    printf("Name: %s\n" , t.name);
    printf("GPA %.2f\n" , t.gpa);
}
    


int main(){

    int n;
    printf("Enter number of records: ");
    scanf("%d" , &n);

    if(n<=0){
        printf("Invalid number entered");
        exit(1);
    }
    Student s[n];
    for(int i = 0;i<n;i++){
        printf("Enter name: ");
        scanf("%s" ,s[i].name );
        printf("Enter gpa: ");
        scanf("%f" , &s[i].gpa);
    }
    ReadIntoTextFile("Students.txt" , s , n);
    ReadFromTextFile("Students.txt");
    

}