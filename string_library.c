#include<stdio.h>
int my_strlen(const char *);//done
char* my_strcpy(char* , const char* );//done
int my_strcmp(const char *,const char *);//done
char* my_strcat(char*,const char *);//done
int main(){
    const char* str1 = "kathmandu";
    const char* str3 = "homecoming";
    char str4[100]="hello";
    const char* str5="world";
    int length=my_strlen(str1);
    printf("length= %d\n",length);
    char str2[20];
    *my_strcpy(str2,str1);
    printf("str2: %s\n",str2);
    int back=my_strcmp(str3,str1);
    printf("%d\n",back);
  my_strcat(str4,str5);
   printf("%s\n",str4);
    return 0;
}

int my_strlen(const char *str1){
    int count =0;
    const char *s=str1;
    while(*s != '\0'){
      count++;
      s++;
    }
    return (count);
}
char* my_strcpy(char* str2,const char* str1){
char *cp_str2=str2;
printf("%s",cp_str2);
while(*str1!='\0'){
    *str2=*str1;
    str1++;
    str2++;
}
*str2='\0';
return (cp_str2);
}
int my_strcmp(const char *str1,const char *str2){
    while(*str1!='\0'){
        if(*str1!=*str2)
        return 0;
        str1++;
        str2++;
    }
    return 1;
}


char* my_strcat(char* str4,const char *str5){
char* cp_str4=str4;
while(*str4!='\0'){
str4++;
}
*str4=' ';
str4++;
while(*str5!='\0'){
    *str4=*str5;
    str4++;
    str5++;
}
*str4='\0';
return(cp_str4);
}