#include<stdio.h>
#include<math.h>
void clear_buffer() {
    while (getchar() != '\n');
}
float add(float,float );
float subtract(float ,float );
float multiplication(float ,float );
float division(float ,float );
int modulus(int, int);
float power(float , float );
int lcm(int,int);
unsigned long long factorial(int); 
void two_numbers(float(*p)(float a, float b)){
    float a,b;
    printf("enter two numbers: ");
    if(scanf("%f %f",&a,&b)!=2){
    printf("invalid input!\n");
   while (getchar()!='\n');
   return;
    }
    else
    printf("Result= %.2f\n",p(a,b));   
}
void one_number(unsigned long long(*pointer)(int a)){
    int a;
    printf("enter a number: ");
    if(scanf("%d",&a)!=1){
        printf("invalid input!\n");
        while (getchar()!='\n');
        return;
                        }
    else
    printf("Result= %llu\n",pointer(a));
}
int main(){
int a,b;
int cont=1;
    while (cont){ 
    int choice;
    printf("\n-----Calculator-----\n");
    printf("1.Addition\n2.Subtrction\n3.Multiplication\n4.Division\n5.Modulus\n6.Power\n7.LCM\n8.factorial\nChoose your option: ");
    scanf("%d",&choice);
    clear_buffer(); 
    switch(choice){
        case 1:two_numbers(add);break;
        case 2:two_numbers(subtract);break;
        case 3:two_numbers(multiplication);break;
        case 4:two_numbers(division);break;
        case 5:
        printf("enter two numbers: ");
        if(scanf("%d %d",&a,&b)!=2){
        printf("invalid input!\n");
        while (getchar()!='\n');break;
                                    }
        printf("Result= %d\n",modulus(a,b));
        break;
        case 6:two_numbers(power);break;
        case 7:
        printf("enter two numbers: ");
        if(scanf("%d %d",&a,&b)!=2){
        printf("invalid input!\n");
        while (getchar()!='\n');break;
                                    }
        printf("Result= %d\n",lcm(a,b));
        break;
        case 8:one_number(factorial);break;



        default:
        printf("select valid input!\n");

            }
        printf("Press \"1\" to repeat: ");
        scanf("%d",&cont);
        clear_buffer(); 
            }   
return 0;
}

float add(float a,float b){
    return(a+b);
}
float subtract(float a, float b){
    return (a-b);
}
float multiplication(float a, float b){
    return (a*b);
}
float division(float a, float b){
    if(b==0.0f){
        printf("Can't divide by zero!\n");
        return NAN;
            }
    else
        return (a/b);
}
int modulus(int a, int b){
    return (a%b);
}
float power(float a, float b){
    float powr=pow(a,b);
return(powr);
}
int lcm(int a, int b){
    int temp1=a,temp2=b;//euclidean algorithm
    while(temp2!=0){
    int remainder =temp1%temp2;
    temp1=temp2;
    temp2 =remainder;
}
int hcf =temp1;
if (a<0||b<0)
return((-a/hcf)*b);
return ((a/hcf)*b);
}
unsigned long long factorial(int a){
   unsigned long long fact=1;
    if(a==0)
    return 1;
    if(a<0){
    printf("Invalid input");
    return -1;}
for(int i=a;i>=1;i--){
    fact=fact*i;
}
return fact;    
}