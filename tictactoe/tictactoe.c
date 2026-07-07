#include<stdio.h>
 char game[3][3]={
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
    char player='X';

void print_board(){
    printf("\n\n");
for(int i=0;i<3;i++){
printf("%c |%c  |%c\n",game[i][0],game[i][1],game[i][2]);
if(i!=2)
printf("__|___|__\n");
                    }
                }

int win(){
    //row and column 
    for(int i=0;i<3;i++){
        if(game[i][0]!=' '&& game[i][0]==game[i][1]&& game[i][0]==game[i][2])//row check
        return 1;
        else if(game[0][i]!=' '&& game[0][i]==game[1][i]&& game[0][i]==game[2][i])//column check
        return 1;
    }
//diagonals check
if((game[0][0]==player&&game[0][0]==game[1][1]&&game[0][0]==game[2][2])||
   (game[0][2]==player&&game[0][2]==game[1][1]&&game[0][2]==game[2][0]))
return 1;

else
return 0;
}


int draw(){
    int full=0;
    for(int i=0;i<3;i++){
        if((game[i][0]=='X'||game[i][0]=='O')&&
        (game[i][1]=='X'||game[i][1]=='O')&&
        (game[i][2]=='X'||game[i][2]=='O'))
        full+=1;
        
    }
int win_check=win();
if(win_check==0&& full==3)
return(1);
else 
return(0);
}
int check(int row,int column){
    int no=1;
    
    if(game[row][column]=='X'||game[row][column]=='O')
         no =0;
    
    return no;
}
int turn(int choice){
    int go;
    switch(choice){
        case 1: go=check(0,0);
        if(go==0)
        return(0);
        else 
        game[0][0]=player;break;
        
        case 2:go=check(0,1);
        if(go==0)
        return(0);
        else
        game[0][1]=player;break;
        
        case 3:go=check(0,2);
        if(go==0)
        return(0);
        else
        game[0][2]=player;break;
        
        case 4: go=check(1,0);
        if(go==0)
        return(0);
        else
        game[1][0]=player;break;
        
        case 5: go=check(1,1);
        if(go==0)
        return(0);
        else
        game[1][1]=player;break;
        
        case 6: go=check(1,2);
        if(go==0)
        return(0);
        else
        game[1][2]=player;break;
        
        case 7:go=check(2,0);
        if(go==0)
        return(0);
        else
        game[2][0]=player;break;
        
        case 8: go=check(2,1);
        if(go==0)
        return(0);
        else
        game[2][1]=player;break;
        
        case 9: go=check(2,2);
        if(go==0)
        return(0);
        else
        game[2][2]=player;break;

    }

    }
        

int main()
{
while(1){
         print_board();
        int choice;
        printf("\n\nPlayer %c turn! Enter your place: ",player);
        //input validation
        if(scanf("%d",&choice)!=1){
            printf("invalid input!");
            while(getchar()!='\n');
            continue;
        }
        //checking for existing entry
        if(turn(choice)==0){
            printf("\nINVALID!ALREADY OCCUPIED!\n\n");
            continue;
        }
        //check for win 
        if(win()){
        print_board();
        printf("\nPlayer %c won!\n",player);
        return 0;
        }
        //check for draw
        else if(draw()){
            print_board();
            printf("\nDRAW!\n");
            return 0;
        }
        //change player
        else
        player=(player=='X'?'O':'X');

    }
    }  