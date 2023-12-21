//By Ingabire Olivier

/*I have used about to 6 functions to do this
* function 1: record_in_file it prompts a user to enter details of the match an then stores it in a file called game.txt
* function 2: display_all_games it reads the game.txt file and prints it to the screen
* Function 3: this is the challlenging function which has to print the teams that has a positive goal difference in all games I am going to explain it below
  @it opens game.txt file with two different pointers ptr1 and ptr so as to read the file in independently
  @ it uses two while loops one nestes in another so as to know  every team's goal difference
  @ it first declares a few variables to store the current team's details
  @ the variables name1 checks  current team name and then if it is the same team it finds the goal difference
  @if the result is positive or greater than zero to prints the team on the screen
  @ it uses another fucntion called check_ex() which checks if the team has not bean checked
*/

#include<stdio.h>
#include<string.h>
struct Team
{
    char name[15];
    int goal_win;
    int goal_conc;
    char date[15];

}team;

//this function ccounts the number of games a team has played and it returns that number
int check_ex(char str[10][15],char str1[15])
{
    int counter=0,i=0;
    for(i=0;i<=10;i++)
    {
        if(strcmp(str[i],str1)==0)
        {
            counter++;
        }

    }
    return counter;
}

//This function displays a team whose goal difference is positive
void display_top()
{
    FILE *ptr;
    FILE *ptr1;

    ptr = fopen("game.txt","r");

     char date1[15];
     char name1[15];
        int goal_w;
        int i=0;
        int goal_c;
        char str[10][15];
        int temp=0;
        int goal_diff=0;
        printf("Team Name\tGoal Difference\n");

    while(fscanf(ptr,"%s\t\t%s\t\t%d\t%d\n",team.name,team.date,&team.goal_win,&team.goal_conc)==4)
    {

        goal_diff =0;
        strcpy(date1,team.date);
        strcpy(name1,team.name);
        goal_w = team.goal_win;
        goal_c = team.goal_conc;
        strcpy(str[i],name1);
        i++;

        ptr1 = fopen("game.txt","r");

        //checking if the team has been checked yet
        if(check_ex(str,name1)<2)
        {
            while(fscanf(ptr1,"%s\t\t%s\t\t%d\t%d\n",team.name,team.date,&team.goal_win,&team.goal_conc)==4)
            {
                if(strcmp(name1,team.name)==0 )
                {
                    temp = team.goal_win -team.goal_conc;
                    goal_diff +=temp;

                }

            }
            fclose(ptr1);
            if(goal_diff>0)
            {

                    printf("%s  %d\n",name1,goal_diff);
            }
        }

    }
    fclose(ptr);
    return;
}
//function to record game
void record_game()
{
    FILE *ptr;
    printf("Enter the team name\n");
    scanf("%s",team.name);
    printf("Enter date\n");
    scanf("%s",team.date);
    printf("ENter goals won\n");
    scanf("%d",&team.goal_win);
    printf("Enter Goals conceded\n");
    scanf("%d",&team.goal_conc);
    ptr = fopen("game.txt","a");
    fprintf(ptr,"%s\t\t%s\t\t%d\t%d\n",team.name,team.date,team.goal_win,team.goal_conc);
    fclose(ptr);
    return;
}
//function to display all games
void display_all_games()
{
    FILE *ptr;
    ptr = fopen("game.txt","r");
    printf("Team Name\t\tGame Date\t\tGoal Won\tGoals Conceded\n");
    while(!feof(ptr))
    {
        fscanf(ptr,"%s\t\t%s\t\t%d\t%d\n",team.name,team.date,&team.goal_win,&team.goal_conc);
        printf("%s\t\t\t%s\t\t%d\t\t%d\n",team.name,team.date,team.goal_win,team.goal_conc);
    }
    fclose(ptr);
    return;
}

//main function
int main()
{
    int choice;
    do
    {
        printf("Press 1 to record game\n");
        printf("Press 2 to Display all games played\n");
        printf("Press 3 to Display teams that have scored more goals\n");
        printf("Enter 0 to exit\n");
        scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        record_game();
        break;

    case 2:
        display_all_games();
        break;
    case 3:
       display_top();
        break;
    case 0:
        return 0;

    default:
        printf("Wrong choice\n");
        break;

    }

    }while(choice!=0);
}



