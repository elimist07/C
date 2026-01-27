#include<stdio.h>
int main(){
int option,number,remainder,converted_number=0,place=1;
top:
printf("\n*****NUMBER-SYSTEM-CONVERTER*****\n");
printf("enter a number: ");
scanf("%d",&number);
printf("\n1.Decimal to Binary\n2.Decimal to Octal\n3.Decimal to HexaDecimal\n4.Binary to Decimal\nCHOOSE ANY OPTION: ");
scanf("%d",&option);
switch(option){
    case 1:
        while(number>0)
        {
         remainder=number%2;
         converted_number=converted_number+remainder*place;
         place=place*10;
         number=number/2;
          }
        printf("Binary= %d\n",converted_number);
        break;
    case 2:
        while(number>0){
        remainder=number%8;
        
        converted_number=converted_number+remainder*place;
        place=place*10;
        number=number/8;
        }
        printf("Octal= %d\n",converted_number);
        break;

    case 3:
        int i=0,j;
        char hexa[100];
        while(number>0){
        remainder=number%16;
        if(remainder<10)
        remainder=remainder+48;//useage of ascii characters
        else
        remainder=remainder+55;
        hexa[i++]=remainder;//i increases by 1 everytime and stores remainder
        number=number/16;
        }
        //eg of (1357)10,7 is stored in hexa[0],5 hexa[1],3 hexa[2],1 hexa[3] and i increases to 4 as i=i+1;
        printf("HexaDecimal= ");
        for(j=i-1;j>-1;j--){//this loop access char hexa,
            printf("%c",hexa[j]); 
        }
        printf("\n");
        break;

    case 4:
    while(number>0){
       remainder=number%10;
       converted_number=converted_number+remainder*place;
       place=place*2;
       number=number/10;
    }
    printf("Decimal= %d\n",converted_number);

    break;

    default:
    printf("choose a valid option!\n");
    goto top;
}

}