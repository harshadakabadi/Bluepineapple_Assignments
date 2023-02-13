#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


struct book{
    char name[30];
    char author[30];
    int id;
    struct book *next;
};

struct student{
    char name[30];
    char book[20];
    char a[30];
    int id;
    struct student *next;
};

struct book *start_lib=NULL;
struct student *start=NULL;
struct book *initialize_lib(struct book *);
struct student *book_issue(struct student *);
struct student *book_return(struct student *);
struct book *diplay_lib(struct book *);
struct book *delete_book(int);
struct book *add_book(char [],char [],int);
void display(struct student *);
int search_Book_Name(char bookname[30]);
int search_Book_AuthorName(char authorname[30]);
void Test_search_by_authorName(char authorname[20],int expectedOutcome);
void Test_search_by_bookName(char authorname[20],int expectedOutcome);
void DisplayMenu();

int main(){
    start_lib=initialize_lib(start_lib);
    DisplayMenu();
    return 0;
}



void DisplayMenu(){
   /* int choice;
	char bookname[30] , authorname[30];
    do{
        printf("\n\n");
        printf("\n\t\t      MAIN MENU: ");
        printf("\n\t\t     1.ISSUE OF BOOKS ");
        printf("\n\t\t     2.RETURN OF BOOKS ");
        printf("\n\t\t     3.DISPLAY STUDENT DETAILS ");
        printf("\n\t\t     4.SEARCH BOOK BY BOOK NAME ");
        printf("\n\t\t     5.SEARCH BOOK BY AUTHOR NAME ");
        printf("\n\t\t     6.EXIT\n ");
        printf("\n\t      Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                start=book_issue(start);
                break;
            }
            case 2:{
                start=book_return(start);
                break;
            }
            case 3:{
                display(start);
                break;
            }
            case 4:{
            	printf("\n\t\tEnter Book Name:");
				scanf("%s",bookname);
            	search_Book_Name(bookname);
				break;
			}
			case 5:{
            	printf("\n\t\tEnter Author Name:");
				scanf("%s",authorname);
            	search_Book_AuthorName(authorname);
				break;
			}
            case 6:{
                exit(1);
            }
            default:{
                printf("\n\t\t\t\t      ...Invalid Option!...\n");
                printf("\n\t\t\t\t      Press any key to try again: ");
                getch();
            }
        }
    }while(choice!=6);*/
    FILE *ptr;
    ptr = fopen("bookFile.txt", "r");
    int Expectedoutcome;
    char ch[20];
	if (ptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read previleges.\n");
        //exit(1);
    }
	fscanf(ptr,"%s",ch);
    fscanf(ptr, "%d", &Expectedoutcome);
    Test_search_by_bookName(ch,Expectedoutcome);
    //Test_search_by_authorName(ch,Expectedoutcome);
    fclose(ptr); 
}

struct book *initialize_lib(struct book *start){
    struct book *ptr,*new_book1,*new_book2,*new_book3,*new_book4,*new_book5;

    new_book1=(struct book *)malloc(sizeof(struct book));
    new_book1->next=NULL;
    start_lib=new_book1;
    strcpy(new_book1->name,"AConfusedMindStory");
    strcpy(new_book1->author,"SahilSeth");
    new_book1->id=101;
    ptr=new_book1;

    new_book2=(struct book*)malloc(sizeof(struct book));
    new_book2->next=NULL;
    strcpy(new_book2->name,"SheIs-WomenInSTEAM");
    strcpy(new_book2->author,"ElsaMarie");
    new_book2->id=102;
    ptr->next=new_book2;
    ptr=new_book2;

    new_book3=(struct book*)malloc(sizeof(struct book));
    new_book3->next=NULL;
    strcpy(new_book3->name,"TheHeroOfTigerHill");
    strcpy(new_book3->author,"SubedarMajorYadav");
    new_book3->id=103;
    ptr->next=new_book3;
    ptr=new_book3;

    new_book4=(struct book*)malloc(sizeof(struct book));
    new_book4->next=NULL;
    strcpy(new_book4->name,"1857:TheSwordOfMastaan");
    strcpy(new_book4->author,"VineetBajpai");
    new_book4->id=104;
    ptr->next=new_book4;
    ptr=new_book4;

    new_book5=(struct book*)malloc(sizeof(struct book));
    new_book5->next=NULL;
    strcpy(new_book5->name,"QueenOfFire");
    strcpy(new_book5->author,"DevikaRangachari");
    new_book5->id=105;
    ptr->next=new_book5;

    return start_lib;
}

struct student *book_issue(struct student *start){
    struct book *ptr;
    struct student *ptr2,*new_student;
    int i=1,id,flag=0;
    if(start_lib==NULL){
        printf("\n\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n");
    }else{
        system("cls");
        ptr=start_lib;
        printf("\n\t*************** Books Available: ****************\n");
        while(ptr!=NULL){
            printf("\n\t_________________________________________________\n");
            printf("\n\t Book %d",i);
            printf("\n\t Book Title: %s",ptr->name);
            printf("\n\t Name of Author: %s",ptr->author);
            printf("\n\t Book ID: %d",ptr->id);
            printf("\n\t_________________________________________________\n");
            ptr=ptr->next;
            i++;
        }
        printf("\n\n\t Enter the Book ID: ");
        scanf("%d",&id);
        ptr=start_lib;
        while(ptr!=NULL){
            if(ptr->id==id){
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==1){
            ptr=start_lib;
            while(ptr->id!=id){
                ptr=ptr->next;
            }
            new_student=(struct student *)malloc(sizeof(struct student));
            printf("\n\t Enter Student Details:\n ");
            printf("\n\t Enter your Name: ");
            scanf("%s",new_student->name);
            strcpy(new_student->book,ptr->name);
            strcpy(new_student->a,ptr->author);
            new_student->id=ptr->id;
            new_student->next=NULL;
            printf("\n\t Issue of Book ID %d done successfully!\n",new_student->id);
            printf("\n\n\t*************************************************\n");
            if(start==NULL){
                start=new_student;
            }else{
                ptr2=start;
                while(ptr2->next!=NULL){
                    ptr2=ptr2->next;
                }
                ptr2->next=new_student;
            }
            start_lib=delete_book(new_student->id);
            printf("\n\n\t Press any key to go to the main menu: ");
            getch();
            system("cls");
        }else{
            printf("\n\t\t      ...Invalid Option!...\n");
            printf("\n\t\t      Press any key to try again: ");
            getch();
            system("cls");
        }
    }
    return start;
}

struct student *book_return(struct student *start){
    struct student *ptr,*preptr;
    char bookname[30],authorname[30];
    int flag=0,id,identity,c=0,d=1;
    printf("\n\n\t*************** Books Submission: ****************\n");
    printf("\n\n\t Enter your Book ID: ");
    scanf("%d",&identity);
    ptr=start;
    while(ptr!=NULL){
        if(ptr->id==identity){
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==1){
        ptr=start;
        while(ptr!=NULL){
            c++;
            ptr=ptr->next;
        }
        ptr=start;
        while(ptr->id!=identity){
                d++;
            ptr=ptr->next;
        }
        ptr=start;
        if( d==1 ){
            printf("\n\t_________________________________________________\n");
            printf("\n\t Student Name: %s",start->name);
            printf("\n\t Name of Book Issued: %s",start->book);
            printf("\n\t_________________________________________________\n");
            printf("\n\n\t Return of Book ID %d done successfully!\n",identity);
            printf("\n\n\t*************************************************\n");
            strcpy(bookname,start->book);
            strcpy(authorname,start->a);
            id=start->id;
            start=start->next;
            free(ptr);
            add_book(bookname,authorname,id);
        }else{
            ptr=start;
            while(ptr->id!=identity){
                preptr=ptr;
                ptr=ptr->next;
            }
            printf("\n\t_________________________________________________\n");
            printf("\n\t Student Name: %s",ptr->name);
            printf("\n\t Name of Book Issued: %s",ptr->book);
            printf("\n\t Book ID: %d",ptr->id);
            printf("\n\t_________________________________________________\n");
            strcpy(bookname,ptr->book);
            strcpy(authorname,ptr->a);
            id=ptr->id;
            preptr->next=ptr->next;
            free(ptr);
            add_book(bookname,authorname,id);
        }
        printf("\n\t Thank you! \n\t Do visit again! ");
        printf("\n\n\t Press any key to go to the main menu: ");
        getch();
        system("cls");
    }else{
        printf("\n\tSorry the book doesn't exist! Please recheck the entered ID");
        printf("\n\t\t\t\t      Press any key to try again: ");
        getch();
        system("cls");
    }
    return start;
}

void display(struct student *start){
    struct student *ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("\n\t************* Details of Students: **************\n");
        printf("\n\t_________________________________________________\n");
        printf("\n\t\t Student Name: %s",ptr->name);
        printf("\n\t\t Name of Book Issued: %s",ptr->book);
        printf("\n\t\t Book ID: %d",ptr->id);
        printf("\n\t_________________________________________________\n");
        printf("\n\n\t*************************************************\n");
        ptr=ptr->next;
    }
    printf("\n\n\t Press any key to go to the main menu: ");
    getch();
    system("cls");
}

struct book *delete_book(int id){
    struct book *ptr,*preptr;
    int c=0;
    ptr=start_lib;
    while(ptr!=NULL){
        c++;
        ptr=ptr->next;
    }
    if(c==1){
        ptr=start_lib;
        start_lib=NULL;
        free(ptr);
    }else if(start_lib->id==id){
        ptr=start_lib;
        start_lib=start_lib->next;
        free(ptr);
    }else{
        ptr=start_lib;
        while(ptr->id!=id){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    return start_lib;
}

struct book *add_book(char bookname[30],char authorname[30],int id){
    struct book *ptr,*new_book;
    new_book=(struct book *)malloc(sizeof(struct book));
    strcpy(new_book->name,bookname);
    strcpy(new_book->author,authorname);
    new_book->id=id;
    new_book->next=NULL;
    if(start_lib==NULL){
        start_lib=new_book;
    }else{
        ptr=start_lib;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new_book;
    }
    return start_lib;
}

int search_Book_Name(char bookname[30])
{
	int count=0;
    struct book *ptr = (struct book *)malloc(sizeof(struct book));
    ptr=start_lib;
	while(ptr->next != NULL)
	{
		if(!(strcmp(ptr->name,bookname) ))
	    {
	    	count++;
	    	break;
		}
		else
		{
			count=0;
		}
		ptr=ptr->next;
	}
	if(count==1)
	{
		printf("Book Found..");
		return 1;
	}
	else
	{
		printf("Book Not found");
		return 0;
	}
	return;
}

int search_Book_AuthorName(char authorname[30])
{
	int count=0;
    struct book *ptr = (struct book *)malloc(sizeof(struct book));
    ptr=start_lib;
	while(ptr->next != NULL)
	{
		if(!strcmp(ptr->author,authorname))
	    {
	    	count=1;
	    	break;
		}
		
		ptr=ptr->next;
	}
	if(count==1)
	{
		printf("Book Found..");
		return 1;
	}
	else
	{
		printf("Book Not found");
		return 0;
	}
	return;   
}

void Test_search_by_bookName(char bookname[20],int expectedOutcome)
{
	if(search_Book_Name(bookname) == expectedOutcome)
	{
		printf("\nSuccessful\n");
	}
	else
	{		
		printf("\nUnsuccessful\n");
	}
}
void Test_search_by_authorName(char authorname[20],int expectedOutcome)
{
	if(search_Book_AuthorName(authorname)==expectedOutcome)
	{
		printf("\nSuccessful\n");
	}
	else
	{		
		printf("\nUnsuccessful\n");
	}
}
