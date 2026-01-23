#include<stdio.h>
int my_strlen(const char *);//done
char *my_strcpy(char* , const char* );//done
int my_strcmp(const char *,const char *);//done
char* my_strcat(char*,const char *);//done
int main(){
    const char* str1 = "app",*str3 = "apple",*str5=" man";
    char str2[100]="abc",str4[100]="iron";
    int length=my_strlen(str1);
    printf("length= %d\n",length);
    my_strcpy(str2,str1);
    printf("str2: %s\n",str2);
    int back=my_strcmp(str3,str1);
    printf("%d\n",back);
    my_strcat(str4,str5);
    printf("%s\n",str4);
    return 0;
}

int my_strlen(const char *str1){
    int count =0;
    while(*str1 != '\0'){
      count++;
      str1++;
    }
    return (count);
}
char* my_strcpy(char* str2,const char* str1){
char *cp_str2=str2;
while(*str1!='\0'){
    *str2=*str1;
    str1++;
    str2++;
}
*str2='\0';
return (cp_str2);
}
int my_strcmp(const char *str1,const char *str2){
    while((*str1!='\0') && (*str2!='\0')){
        if(*str1!=*str2)
        break;
        str1++;
        str2++;
    }
    if(*str1==*str2)
    return 0;
    else if( *str1 > *str2) 
    return 1;
    else 
    return -1;
}


char* my_strcat(char* str4,const char *str5){
char* cp_str4=str4;
while(*str4!='\0'){
str4++;
}
while(*str5!='\0'){
    *str4=*str5;
    str4++;
    str5++;
}
*str4='\0';
return(cp_str4);
}