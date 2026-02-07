#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int add(int,int);
int main(int argc,char* argv[]){

int add_result=strcmp(argv[1],"add");
   if(add_result==0&&argc==4){
    int num1=atoi(argv[2]);
    int num2=atoi(argv[3]);
    
   printf("Sum = %d\n",add(num1,num2));
   
}
else{
    printf("Sufficient arguments needed\n");
}
return 0;
}

int add(int a,int b){
    return(a+b);
}