#include<conio.h>
#include <assert.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
void displayscore();

struct game
{
    int score;
    char name1[30],name2[30];
}player;

void main()
{
    int op;
    char ch;
    printf("\n\n\n\n\n\t\t*********************************************");
    printf("\n\t\t\t\t   WELCOME      ");
    printf("\n\n\t\t\t      CRICKET KEY GAME");
    printf("\n\t\t*********************************************");
    printf("\n\n\npress any key to continue this game: ");
    getch();
    while(1)
    {
        printf("\n\n\t\t\tCRICKET KEY GAME");
        printf("\n\n\n\t1.) START\t\t\tpress 1");
        printf("\n\n\t2.) INSTRUCTIONS\t\tpress 2");
        printf("\n\n\t3.) High score\t\t\tpress 3");
        printf("\n\n\t4.) EXIT\t\t\tpress 4");
        printf("\n\n\nchose any option:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                select();
                break;
            case 2:
                printf("\t\t\t\tHOW TO PLAY\nWhen game starts you have to press any key when you press any key computer will generate random number and that random  number will be your runs");
                printf("When 7  number is generated than you get out so the game totally depends on your luck. \n\n \n\t\t\t\tENJOY THE GAME\n press any key to continue..............");
                getch();
                break;
            case 3:
                displayscore();
                break;
            case 4:
                exit(1);
            default:
                printf("\nSorry Wrong Choice");
                break;
        }
    }
}
void select()
{
    int yu, m, ye, d, e, i, b, toss, y, aso, we=1000, ew=1000, chose;
    char player1[50], player2[50];
    time_t po;
    (unsigned) time(&po);
    srand(po);
    toss = rand()%2;

    printf("\nEnter First Players Name : ");
    scanf("%s",player.name1);
    printf("\nEnter Second Players Name : ");
    scanf("%s",player.name2);
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    assert(strftime(s, sizeof(s), "%c", tm));
    printf("\nNow date and time are : %s\n",s);
    printf("\nHow many overs to play : ");
    scanf("%d",&e);
    b = e * 6;
    printf("\n%d",b);
    printf(" ball you want to play");
    printf("\n\nNow its time for toss");
    printf("\n\nwho want toss");
    printf("\n1.player %s",player.name1);
    printf("\t\t\t2.player %s",player.name2);
    printf("\n\nplease chose any player:");
    scanf("%d",&chose);
    if(chose==1)
    {
        printf("\n\nPlayer %s Please Choose heads or Tails \n\nPress 1 for heads \n\npress 2 for tails",player.name1);
    }
    else
    {
        printf("\n\nPlayer %s Please Choose heads or Tails \n\nPress 1 for heads \n\npress 2 for tails",player.name2);
    }
    printf("\n\nselect %s your choise:");
    scanf("%d",&aso);
    if(toss==0)
    {
        printf("\n%s Has Won The Toss",player.name1);
        printf(" Select \n\n1.)Batting \t\t\t\tpress 1 \n\n2.)Bowling\t\t\t\tpress 2");
        printf("\n\n what do you want");
        scanf("%d",&y);
        switch(y)
        {
            case 1:
                we=bat1(e,player.name1,ew);
                ew=bat1(e,player.name2,we);
                con(we,ew,player.name1,player.name2);
                break;
            case 2:
                we=bat1(e,player.name2,ew);
                ew=bat1(e,player.name1,we);
                con(we,ew,player.name2,player.name1);
                break;
            default :
                printf("\n\nSorry wrong choice");
                break;
        }
    }
    else
    {
        printf("\n%s Has Won The Toss",player.name2);
        printf(" Select \n\n1.)Batting \t\t\t\tpress 1 \n\n2.)Bowling\t\t\t\tpress 2");
        printf("\n\n what do you want");
        scanf("%d",&y);
        switch(y)
        {
            case 1:
                ew=bat1(e,player.name1,we);
                we=bat1(e,player.name2,ew);
                con(we,ew,player.name2,player.name1);
                break;
            case 2:
                we=bat1(e,player.name1,ew);
                ew=bat1(e,player.name2,we);
                con(we,ew,player.name1,player.name2);
            default :
                printf("\n\nSorry wrong choice");
                break;
        }
    }
}
int score()
{
    int run;
    run=rand()%8;
    if(run<4){
        printf("\n\nYou Score %d runs ",run);
    }
    else
    {
        switch(run)
        {
            case 4:
                printf("\n\nGood Shot! what a boundary you hit");
                break;
            case 5:
                run=0 ;
                printf("\n\nYou Score %d runs ",run);
                break;
            case 6 :
                printf("\n\nGreat Shot !! That's a huge hit  ");
                break;
            case 7:
                printf("\n\nOOPs !! You are out\n");
                break;
        }
    }
    return run;
}
int bat1(int e,char *c,int check)
{
    int i,orig,totalruns=0,we;
    printf("\n%s Get ready to Bat \n\nPress any key to hit the Ball",c);
    e = e * 6;
    for(i=1;i<=e;i++)
    {
        getch();
        if(check<totalruns)
            return totalruns;
        orig=score();
        if(orig==7)
            break;
        else
        {
            totalruns=totalruns+orig;
            printf(" Your total score is %d",totalruns);
        }
    }
    getch();
    return totalruns;
}
void con(int we,int ew)
{
    if(we<ew)
    {
        printf("\n\n\t\t\t*******Congratulation*******\n %s has won the game \nScore of %s is %d\nScore of %s is %d",player.name2,player.name1,we,player.name2,ew);
        FILE *fptr;
        fptr=fopen("shawon.txt", "a");
        if(fptr==NULL)
        {
            printf("\nError");
            exit(1);
        }
        fprintf(fptr, "Name : %s\t",&player.name2);
        fprintf(fptr, "score : %d\n",ew);
        fprintf(fptr, "Name : %s\t",&player.name1);
        fprintf(fptr, "score : %d\n",we);
        fclose(fptr);
    }
    else if(we>ew)
    {
        printf("\n\nTotal score of Player %s is %d",player.name2,ew);
        printf("\n\n\t\t\t\t*******Congratulation*******\n\n%s has won the game \n\nScore of %s is %d\n\nScore of %s is %d",player.name1,player.name1,we,player.name2,ew);
        FILE * fptr;
        fptr=fopen("shawon.txt", "a");
        if(fptr==NULL)
        {
            printf("\nError");
            exit(1);
        }
        fprintf(fptr, "Name : %s\t",&player.name1);
        fprintf(fptr, "score : %s\n",we);
        fprintf(fptr, "Name : %s\t",&player.name2);
        fprintf(fptr, "score : %d\n",ew);
        fclose(fptr);
    }
    else
    {
        printf("\n\nTotal score of Player %s is %d",player.name2,ew);
        printf("\n\n\t\t\t\t*******GAME HAS DRWRAN********\nScore of %s is %d\nScore of %s is %d",player.name1,we,player.name2,ew);
        FILE *fptr;
        fptr=fopen("shawon.txt", "a");
        if(fptr==NULL)
        {
            printf("\nError");
            exit(1);
        }
        fprintf(fptr, "Match drwran");
        fprintf(fptr, "Name : %s\t",&player.name1);
        fprintf(fptr, "score : %d\n",we);
        fprintf(fptr, "Name : %s\t",&player.name2);
        fprintf(fptr, "score : %d\n",ew);
        fclose(fptr);
    }
}
void displayscore()
{
    char filename[] = "shawon.txt";
    FILE *file = fopen ( filename, "r" );
    if ( file != NULL )
    {
        char line [128];
        while ( fgets ( line, sizeof line, file ) != NULL )
        {
            fputs ( line, stdout );
        }
        fclose ( file );
    }
 }
