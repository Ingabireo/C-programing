/**Group members
  ---------------
*@ Ingabire Olivier
 @ ISHIMWE Thierry Henry
 @ Akeza Favorite
 @ Dushime Melissa

 *This is a simple program to book a bus transport ticket

*/

#include<stdio.h>
#include<string.h>
struct Bus
{
    char name[20];
    char dest[20];
    int price;
    int num;
};

void get_time(int a,char time[10])
{

	switch(a)
	{
		case 1:
			strcpy(time,"6:00");
			break;
		case 2:
			strcpy(time,"8:00");
			break;
		case 3:
			strcpy(time,"12:00");
			break;
		case 4:
			strcpy(time,"1:00");
			break;
		case 5:
			strcpy(time,"3:00");
			break;
		case 6:
			strcpy(time,"5:00");
			break;
		case 7:
			strcpy(time,"8:00");
			break;
		case 8:
			strcpy(time,"10:00");
			break;
	}
}

void print_ticket(struct Bus bus)
{
    char time[10];
    get_time(bus.num,time);
    printf("|-----------------------------------------------|\n");
	printf("|                                               |\n");
	printf("|              Best Transport Ltd               |\n");
	printf("|             ----------------------            \n");
	printf("| Name:%s                                       \n",bus.name);
    printf("| price:%d                                      \n",bus.price);
	printf("| Destination:%s                                \n",bus.dest);
	printf("| Departure:Kigali                              \n");
	printf("| Departure time:%s                             \n",time);
	printf("|time offered:%s                               \n",__TIME__);
    printf("|                                               |\n");
	printf("|            Thank you Safe Journey!!!!         |\n");
	printf("|-----------------------------------------------|\n");

}

void display_bus()
{
    struct Bus bus;
    FILE *ptr;
    ptr = fopen("passengers.txt","r");
    char str[20];
    int num;
    printf("Enter the Destination\n");
    scanf("%s",str);
    print_time();
    scanf("%d",&num);
    if(check_full(str,num)==0)
    {
        printf("The bus is Empty\n");
        return;
    }
    printf("Name\t\tDestination\t\tPrice\t   Bus number\n");
    while(!feof(ptr))
    {
        fscanf(ptr,"%s\t%s\t%d\t%d\n",bus.name,bus.dest,&bus.price,&bus.num);
        if(strcmp(str,bus.dest)==0 && bus.num==num)
        {
            printf("%-17s%-23s%-15d%-15d\n",bus.name,bus.dest,bus.price,bus.num);
        }

    }
    fclose(ptr);
    return;


}

int check_full(char str[20],int num)
{
    struct Bus bus;
    FILE *ptr;
    ptr = fopen("passengers.txt","r");
    int counter=0;
    while(!feof(ptr))
    {
        fscanf(ptr,"%s\t%s\t%d\t%d\n",bus.name,bus.dest,&bus.price,&bus.num);
        if(strcmp(bus.dest,str)==0 && num == bus.num)
        {
            counter++;
        }
    }
    fclose(ptr);
    return counter;
}

void display_all_pass()
{
    struct Bus bus;
    FILE *ptr;
    ptr = fopen("passengers.txt","r");
    printf("Name\t\tDestination\t\tPrice\t   Bus number\n");
    while(!feof(ptr))
    {
         fscanf(ptr,"%s\t%s\t%d\t%d\n",bus.name,bus.dest,&bus.price,&bus.num);
        printf("%-17s%-23s%-15d%-15d\n",bus.name,bus.dest,bus.price,bus.num);
    }
    fclose(ptr);

    return;


}

void record_in_file(struct Bus bus1)
{
    FILE *ptr;
    ptr = fopen("passengers.txt","a");
    if(ptr == NULL)
    {
        printf("Unable to open a file\n");
        return;
    }
    if(check_full(bus1.dest,bus1.num)>30)
    {
        printf("The bus is full please choose another\n");
        return;
    }
    fprintf(ptr,"%s\t%s\t%d\t%d\n",bus1.name,bus1.dest,bus1.price,bus1.num);

    printf("Passenger recorded successfully!!!!\n\n");
    fclose(ptr);
    return;
}
void print_place()
{
    printf("|------------------------------------------------|\n");
    printf("|    Please choose Where You want to go          |\n");
    printf("|                                                |\n");
	printf("|Press 1 if you are going Nyaruguru              |\n");
	printf("|Press 2 if you are going Nyanza                 |\n");
	printf("|Press 3 if you are going Muhanga                |\n");
	printf("|Press 4 if you are going Ruhango                |\n");
	printf("|Press 5 if you are going Huye                   |\n");
	printf("|Press 0 to exit                                 |\n");
	printf("|------------------------------------------------|\n");
}
void print_time()
{
    printf("bus 1 4:00\n");
	printf("bus 2 6:00\n");
	printf("bus 3 9:00\n");
	printf("bus 4 12:00\n");
	printf("bus 5 2:00\n");
	printf("bus 6 4:00\n");
	printf("bus 7 8:00\n");

}
void book_ticket()
{
    struct Bus bus;
    int choice;
    print_place();
	scanf("%d",&choice);
	switch(choice)
	{
    case 1:
        strcpy(bus.dest,"Nyaruguru");
        bus.price = 5000;
        printf("Please enter the bus number\n");
        print_time();
        scanf("%d",&bus.num);
        printf("Enter your name\n");
        scanf("%s",bus.name);
        record_in_file(bus);
        break;
    case 2:
        strcpy(bus.dest,"Nyanza");
        bus.price = 3000;
        printf("Please enter the bus number\n");
        print_time();
        scanf("%d",&bus.num);
        printf("Enter your name\n");
        scanf("%s",bus.name);
        record_in_file(bus);
        break;
    case 3:
        strcpy(bus.dest,"Ruhango");
        bus.price = 2500;
        printf("Please enter the bus number\n");
        print_time();
        scanf("%d",&bus.num);
        printf("Enter your name\n");
        scanf("%s",bus.name);
        record_in_file(bus);
        break;
    case 4:
        strcpy(bus.dest,"Ruhango");
        bus.price = 2500;
        printf("Please enter the bus number\n");
        print_time();
        scanf("%d",&bus.num);
        printf("Enter your name\n");
        scanf("%s",bus.name);
        record_in_file(bus);
        break;
    case 5:
        strcpy(bus.dest,"Huye");
        bus.price = 4000;
        printf("Please enter the bus number\n");
        print_time();
        scanf("%d",&bus.num);
        printf("Enter your name\n");
        scanf("%s",bus.name);
        record_in_file(bus);
        break;
    default:
        printf("Wrong choice \n");
        break;
	}
	int n;
	printf("press 1 to print the tickect and 2 if not \n");
	scanf("%d",&n);
	if(n==1)
    {
        print_ticket(bus);
    }

}

int main()
{
    int number; char name[20];
    int choice;
    do
    {
    printf("|------------------------------------------|\n");
    printf("|                                          |\n");
    printf("|            Best transport ltd            |\n");
    printf("|     ------------------------------       |\n");
    printf("|  Press 1 to Book a ticket                |\n");
    printf("|  press 2 to Display all booked tickets   |\n");
    printf("|  Press 3 Display a list of  certain Bus  |\n");
    printf("|  Press 4                                 |\n");
    printf("|  Press 0 to exit                         |\n");
    printf("|                                          |\n");
    printf("|------------------------------------------|\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
       book_ticket();
        break;

    case 2:
        display_all_pass();
        break;
    case 3:
        display_bus();
        break;
    case 0:
        printf("Byee Byeeee!!!!! \n");
        return;

        printf("seee(%d)the bus has %d places\n",strcmp(name,"Nyauguru"),check_full(name,number));
        break;
    default:
        printf(" Wrong choice\n");
        break;
    }
    }while(choice!=0);
}
