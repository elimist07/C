#include<stdio.h>
int main(){
    char str[100];
    int count =0;
    printf("enter a string: ");
    fgets(str,10,stdin);
  for(int i=0;i<=100;i++){
        if(str[i+1]=='\0')
        break;
        count=count+1;
    }
    printf("length= %d\n",count);
    return 0;
}

