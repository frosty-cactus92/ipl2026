#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char name[50];
    float gpa;

}Student;


void ReadIntoBinFile(char filename[] ,Student s[],int n){
    FILE *fp = fopen(filename,"wb");
    if(fp==NULL){
        printf("Error opening file");
        exit(1);
    }
    for(int i = 0;i<n;i++){
        fwrite(&s[i],sizeof(Student),1,fp);
    }
    fclose(fp);

}
void ReadFromBinFile(char filename[]){
    FILE *fp = fopen(filename,"rb");
    if(fp==NULL){
        printf("Error opening file");
        exit(1);
    }
    int off;
    printf("Enter the nth record you want: ");
    scanf("%d" , &off);
    fseek(fp,(off-1)*sizeof(Student),SEEK_SET);
    
    Student t;
    if(fread(&t , sizeof(Student) , 1 , fp)==1){
        printf("Name: %s\n",t.name);
        printf("GPA: %.2f\n",t.gpa);
    }
    
}

void DeleteFromBin(char filename[] , Student s[] , int n){
    FILE *fp = fopen(filename,"rb+");
    if(fp==NULL){
        printf("Error opening file");
        exit(1);
    }
    FILE *fdel = fopen("DelStuds.bin","wb");
    if(fdel==NULL){
        printf("Error opening file");
        exit(1);
    }
    char name[50];
    printf("Enter the name you want to delete: ");
    scanf("%s" , name);
    int i = 0;

    while(fread(&s[i] , sizeof(Student) ,1,fp)){
        if(strcmp(s[i].name,name) != 0){
            fwrite(&s[i] , sizeof(Student) , 1 ,fdel);
            
        }
        i+=1;
    }
    fclose(fp);
    fclose(fdel);
    remove("Students.bin");
    rename("DelStuds.bin","Students.bin");
    

}
int main(){
    int n;
    printf("enter number of students: ");
    scanf("%d" , &n);
    Student s[n];
    for(int i = 0;i<n;i++){
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter GPA: ");
        scanf("%f",&s[i].gpa);

    }
    ReadIntoBinFile("Students.bin",s,n);
    ReadFromBinFile("Students.bin");
    DeleteFromBin("Students.bin" , s , n);
    FILE *fp = fopen("Students.bin" , "rb");
    if(fp == NULL){
        printf("error opening file");
        exit(1);
    }
    Student t;
    printf("\nFile content after deletion\n");
    while(fread(&t , sizeof(Student),1,fp)){
        printf("Name: %s\n",t.name);
        printf("GPA: %f\n" ,t.gpa);
    }
    fclose(fp);
    

    return 0;
}