#include<stdio.h>
int my_strlen(char *);
int my_strcpy(char *);
int my_strcmp(char *);
int my_strcat(char *);
int main(){
    char *str1 = "KATHMANDU";
    int length=my_strlen(str1);
    char str2=my_strcpy;
    printf("%s",str2);

    printf("length= %d\n",length);
    return 0;
}

int my_strlen(char *str1){
    int count =0;
     printf("string: %s\n",str1);
     for(int i=0;i<=100;i++){
        if(str1[i]=='\0')
        break;
        count=count+1;
    }
    return count;
}
int my_strcpy(char *str1){
char *str2=str1;
return (*str2);
}
int my_strcmp(char *str1){

}
int my_strcat(char *str1){

}