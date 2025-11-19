#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

void addrecord();

void viewrecord();

void editrecord();

void searchrecord();

void deleterecord();

void login();

struct record

{
	char id[10];
    
    char name[30];
    
    char age[6];
    
    char gender[10];
    
    char weight[20];
    
    char height[20];
    
    char haircolor[20];
    
    char eyecolor[20];
    
    char crime[40];
    
    char details[20];
    
    char court[20];
	
	char act[20]; 
    
    char punishment[50];
    
    char faddress[20];
    
    char fir[20];
    
    char emergencyc[20];
    
    char emergencyr[20];
    
    char datearr[20];

} a;

int main()


{
	login();

    int ch;
    printf("\n\n\t====================================\n");
    printf("\t   -POLICE FIR RECORD MANAGEMENT-\n");
    printf("\t====================================");

    while(1)
    {

        printf("\n\n\t\t::MAIN MENU::");
        printf("\n\n\t\tADD FIR RECORD\t[ENTER-1]");
        printf("\n\t\tSEARCH RECORD\t[ENTER-2]");
        printf("\n\t\tMODIFY RECORD\t[ENTER-3]");
        printf("\n\t\tLIST RECORD\t[ENTER-4]");
		printf("\n\t\tDELETE RECORD\t[ENTER-5]");
        printf("\n\t\tEXIT\t\t[ENTER-6]");
        printf("\n\n\t=> ENTER YOUR CHOICE:");
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            addrecord();
            break;

        case 2:
            searchrecord();
            break;

        case 3:
            editrecord();
            break;

        case 4:
            viewrecord();
            break;
            
        case 5:
            deleterecord();
            break;

        case 6:
        	system("cls");
            printf("\n\n\t\tTHANK YOU FOR USING THIS SOFTWARE \n\n\n\n\t\tBROUGHT TO YOU BY code-projects.org\n\n ");
            getch();
            exit(0);

        default:
            printf("\nYOU ENTERED WRONG CHOICE.");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getch();
            break;

        }

        system("cls");

    }
    return 0;

}


//*********************************************************
/**************** ADDING FUNCTION************************/
//*********************************************************
void addrecord( )

{
    system("cls");
    FILE *fp ;
    char another = 'Y' ,id[10];
    char filename[30];
    int choice;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t  - ADD RECORDS -");
    printf("\n\t\t====================================\n");
    printf("\n\n\tENTER FIRST NAME OF CONVICT(To Check whether record exists or not): ");
    fflush(stdin);
    gets(filename);

    fp = fopen ("filename", "ab+" ) ;

    if ( fp == NULL )
    {

        fp=fopen("filename","wb+");
        if(fp==NULL)
        {

            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;

        }
    }

    while ( another == 'Y'|| another=='y' )

    {
        choice=0;
        fflush(stdin);
        
		printf ( "\tENTER CONVICT CODE(To check whether it matches or not): ");
        scanf("%s",id);
        
		rewind(fp);

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.id,id)==0)
            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice=1;

            }

        }

        if(choice==0)
        {

            strcpy(a.id,id);

            printf("\n\tENTER NAME OF CONVICT: ");
            fflush(stdin);
            gets(a.name);
            
			printf("\tENTER SEX: ");
            gets(a.gender);
            fflush(stdin);

            printf("\tENTER AGE: ");
            gets(a.age);
            fflush(stdin);

            printf("\tENTER WEIGHT: ");
            gets(a.weight);
            fflush(stdin);
            
            printf("\tENTER HEIGHT(FT): ");
            gets(a.height);
 			fflush(stdin);
           
            printf("\tENTER HAIRCOLOR: ");
            gets(a.haircolor);
            fflush(stdin);
            
            printf("\tENTER EYECOLOR: ");
            gets(a.eyecolor);
            fflush(stdin);
            
            printf("\tENTER FACE DETAILS: ");
            gets(a.details);
            fflush(stdin);
			
			
			printf("\tENTER CRIME: ");
            gets(a.crime);
            fflush(stdin);
            
            
            printf("\tENTER COURT: ");
            gets(a.court);
            fflush(stdin);
            
            printf("\tACT(under which convicted): ");
            gets(a.act);
            fflush(stdin);
            
            printf("\tENTER CONVICTION: ");
            gets(a.punishment);
            fflush(stdin);
            
            printf("\tCOMPLETE ADDRESS OF POLICE STATION: ");
            gets(a.faddress);
            fflush(stdin);
            
            printf("\tENTER FIR NUMBER: ");
            gets(a.fir);
            fflush(stdin);
            
            printf("\tENTER EMERGENCY CONTACT: ");
            gets(a.emergencyc);
            fflush(stdin);
            
            printf("\tENTER RELATION OF EMERGENCY CONTACT WITH CONVICT: ");
            gets(a.emergencyr);
            fflush(stdin);
            
            printf("\tENTER DATE OF ARREST: ");
            gets(a.datearr);
            
            fwrite ( &a, sizeof ( a ), 1, fp ) ;
            printf("\nYOUR RECORD IS ADDED...\n");

        }

        printf ( "\n\tADD ANOTHER RECORD...(Y/N) \t" ) ;
        fflush ( stdin ) ;
        another = getch( ) ;

    }

    fclose ( fp ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();

}


//***********************************************************
/**************** SEARCHING FUNCTION************************/
//***********************************************************
void searchrecord( )

{
	system("cls");
    FILE *fp ;
	char id[16],choice,filename[14];
    int ch;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- SEARCH RECORDS -");
    printf("\n\t\t====================================\n\n");

    do
	{
        
		printf("\n\tENTER THE PRISONER NAME TO BE SEARCHED:");
        fflush(stdin);
        gets(filename);

        fp = fopen ( "filename", "rb" ) ;


        //system("cls");
    	
    		printf("\nENTER CONVICT CODE:");
            gets(id);
            system("cls");
            printf("\nTHE WHOLE RECORD IS:");
 
            while ( fread ( &a, sizeof ( a ), 1, fp ) == 1 )

          //{
          if(strcmpi(a.id,id)==0)
               { printf("\n");
                printf("\nCONVICT'S NAME IS: %s",a.name);
                printf("\nCONVICT'S GENDER IS: %s",a.gender);
                printf("\nCONVICT'S AGE IS: %s",a.age);
                printf("\nCONVICT'S WEIGHT IS: %s",a.weight);
                printf("\nCONVICT'S HEIGHT IS: %s",a.height);
                printf("\nCONVICT'S HAIRCOLOR IS: %s",a.haircolor);
				printf("\nCONVICT'S EYECOLOR IS: %s",a.eyecolor);
                printf("\nCONVICT'S CRIME IS: %s",a.crime);
                printf("\nFACE DETAIL: %s",a.details);
                printf("\nCOURT IS: %s",a.court);
                printf("\nACT IS: %s",a.act);
                printf("\nPRISONER'S CONVICTION IS: %s",a.punishment);
                printf("\nADDRESS OF POLICE STATION: %s",a.faddress);
                printf("\nFIR NUMBER IS: %s",a.fir);
                printf("\nCONVICT'S EMERGENCY CONTACT IS: %s",a.emergencyc);
                printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s",a.emergencyr);
                printf("\nARRESTED DATE: %s",a.datearr);
                printf("\n");
            }

           // }
            

        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
        fflush(stdin);

        scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fp) ;
	getch();
    return ;
getch();
}


//*********************************************************
/**************** EDITING FUNCTION************************/
//*********************************************************

void editrecord()

{

    system("cls");
    FILE *fp ;
    char id[10],choice,filename[14];
    int num,count=0;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- MODIFY RECORDS -");
    printf("\n\t\t====================================\n\n");

    do
    {

        printf("\n\tENTER THE CONVICT'S' NAME TO BE EDITED:");
        fflush(stdin);
        gets(filename);

        printf("\n\tENTER ID:");
    	gets(id);
        fp = fopen ( "filename", "rb+" ) ;

        /*if ( fp == NULL )
        {

            printf( "\nRECORD DOES NOT EXIST:" ) ;
            printf("\nPRESS ANY KEY TO GO BACK");
            getch();
            return;

        }*/

        while ( fread ( &a, sizeof ( a ), 1, fp ) == 1 )
        {

            if(strcmp(a.id,id)==0)
            {

                printf("\nYOUR OLD RECORD WAS AS:");
                printf("\nCONVICT'S NAME: %s",a.name);
                printf("\nCONVICT'S SEX: %s",a.gender);
                printf("\nCONVICT'S AGE: %s",a.age);
                printf("\nCONVICT'S WEIGHT: %s",a.weight);
                printf("\nCONVICT'S HEIGHT: %s",a.height);
                printf("\nCONVICT'S HAIRCOLOR: %s",a.haircolor);
				printf("\nCONVICT'S EYECOLOR: %s",a.eyecolor);
                printf("\nCONVICT'S CRIME: %s",a.crime);
                printf("\nFACE DETAILS: %s",a.details);
                printf("\nCOURT: %s",a.court);
                printf("\nCONVICT'S ACT: %s",a.act);
                printf("\nCONVICT'S CONVICTION: %s",a.punishment);
                printf("\nADDRESS OF POLICE STATION: %s",a.faddress);
                printf("\nFIR NUMBER: %s",a.fir);
                printf("\nCONVICT'S EMERGENCY CONTACT: %s",a.emergencyc);
                printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT: %s",a.emergencyr);
                printf("\nARRESTED DATE: %s",a.datearr);
                
            
                
                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");
                
                
                
                printf("\n1.NAME.");
                printf("\n2.SEX.");
                printf("\n3.AGE.");
                printf("\n4.WEIGHT.");
                printf("\n5.HEIGHT.");
                printf("\n6.HAIRCOLOR.");
                printf("\n7.EYECOLOR.");
                printf("\n8.CRIME.");
                printf("\n9.FACE DETAILS.");
                printf("\n10.COURT.");
                printf("\n11.ACT.");
                printf("\n12.CONVICTION.");
                printf("\n13.ADDRESS OF POLICE STATION.");
                printf("\n14.FIR NUMBER.");
                printf("\n15.EMERGENCY CONTACT.");
                printf("\n16.RELATION OF EMERGENCY CONTACT.");
                printf("\n17.ARRESTED DATE.");
                printf("\n18.WHOLE RECORD.");
                printf("\n19.GO BACK TO MAIN MENU.");
                
                do
                {

                    printf("\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);
                    
                    switch(num)
                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNAME:");
                        gets(a.name);
                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nSEX:");
                        gets(a.gender);
                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nAGE:");
                        gets(a.age);
                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nWEIGHT:");
                        gets(a.weight);
                        break;

                    case 5:
                        printf("ENTER THE NEW DATA:");
                        printf("\nHEIGHT:");
                        gets(a.height);
                        break;

                    case 6:
                        printf("ENTER THE NEW DATA:");
                        printf("\nHAIRCOLOR:");
                        gets(a.haircolor);
                        break;

                    case 7:
                        printf("ENTER THE NEW DATA:");
                        printf("\nEYECOLOR:");
                        gets(a.eyecolor);
                        break;

                    case 8:
                        printf("ENTER THE NEW DATA:");
                        printf("\nCRIME:");
                        gets(a.crime);
                        break;

                    case 9:
                        printf("ENTER THE NEW DATA:");
                        printf("\nFACE DETAILS:");
                        gets(a.details);
                        break;

                    case 10:
                        printf("ENTER THE NEW DATA:");
                        printf("\nCOURT:");
                        gets(a.court);
                        break;

                    case 11:
                        printf("ENTER THE NEW DATA:");
                        printf("\nACT:");
                        gets(a.act);
                        break;

                    case 12:
                        printf("ENTER THE NEW DATA:");
                        printf("\nCONVICTION:");
                        gets(a.punishment);
                        break;

                    case 13:
                        printf("ENTER THE NEW DATA:");
                        printf("\nADDRESS OF POLICE STATION:");
                        gets(a.faddress);
                        break;

                    case 14:
                        printf("ENTER THE NEW DATA:");
                        printf("\nFIR NUMBER:");
                        gets(a.fir);
                        break;

                    case 15:
                        printf("ENTER THE NEW DATA:");
                        printf("\nEMERGENCY CONTACT:");
                        gets(a.emergencyc);
                        break;

                    case 16:
                        printf("ENTER THE NEW DATA:");
                        printf("\nRELATION OF EMERGENCY CONTACT:");
                        gets(a.emergencyr);
                        break;

                    case 17:
                        printf("ENTER THE NEW DATA:");
                        printf("\nARRESTED DATE:");
                        gets(a.emergencyc);
                        break;

                    case 18:
                    	printf("ENTER THE NEW DATA:");
                        printf("\tCONVICT'S NAME:");
			            gets(a.name);		
						printf("\tSEX:");
			            gets(a.gender);			
			            printf("\tAGE:");
			            gets(a.age);
			            printf("\tWEIGHT:");
			            gets(a.weight);
			            printf("\tHEIGHT:");
			            gets(a.height);
			            printf("\tHAIRCOLOR:");
			            gets(a.haircolor);
			            printf("\tEYECOLOR:");
			            gets(a.eyecolor);
			            printf("\tCRIME:");
			            gets(a.age);
			            printf("\tFACE DETAILS:");
			            gets(a.details);
			            printf("\tCOURT:");
			            gets(a.court);
			            printf("\tACT:");
			            gets(a.act);
			            printf("\tCONVICTION:");
			            gets(a.punishment);
			            printf("\tADDRESS OF POLICE STATION:");
			            gets(a.faddress);
			            printf("\tFIR NUMBER:");
			            gets(a.fir);
			            printf("\tEMERGENCY CONTACT:");
			            gets(a.emergencyc);
			            printf("\tRELATION OF EMERGENCY CONTACT WITH CONVICT:");
			            gets(a.emergencyr);
			            printf("\tARRESTED DATE:");
			            gets(a.datearr);
                        break;

                    case 19:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");
                        getch();
                        return ;
                        break;

                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                        break;

                    }

                }
                while(num<1||num>20);

                fseek(fp,-sizeof(a),SEEK_CUR);

                fwrite(&a,sizeof(a),1,fp);

                fseek(fp,-sizeof(a),SEEK_CUR);

                fread(&a,sizeof(a),1,fp);

                choice=5;

                break;

            }
        }

        if(choice==5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");
            printf("--------------------\n");
            printf("THE NEW RECORD IS:\n");
            printf("--------------------\n");
            printf("\nCONVICT'S NAME IS: %s",a.name);
            printf("\nCONVICT'S SEX IS: %s",a.gender);
            printf("\nCONVICT'S AGE IS: %s",a.age);
            printf("\nCONVICT'S WEIGHT IS: %s",a.weight);
            printf("\nCONVICT'S HEIGHT IS: %s",a.height);
            printf("\nCONVICT'S HAIRCOLOR IS: %s",a.haircolor);
			printf("\nCONVICT'S EYECOLOR IS: %s",a.eyecolor);
            printf("\nCONVICT'S CRIME IS: %s",a.crime);
            printf("\nFACE DETAILS: %s",a.details);
            printf("\nCOURT IS: %s",a.court);
            printf("\nACT: %s",a.act);
    		printf("\nCONVICT'S CONVICTION IS: %s",a.punishment);
        	printf("\nADDRESS OF POLICE STATION: %s",a.faddress);
            printf("\nFIR NUMBER: %s",a.fir);
            printf("\nCONVICT'S EMERGENCY CONTACT IS: %s",a.emergencyc);
            printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s",a.emergencyr);
            printf("\nARRESTED DATE: %s",a.datearr);

            fclose(fp);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
            scanf("%c",&choice);
            count++;

        }
        else
        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
        	scanf("%c",&choice);

        }
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp ) ;
    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    getch();

}

//*********************************************************
/**************** VIEWING FUNCTION************************/
//*********************************************************

void viewrecord()

{
    system("cls");
    FILE *fp;
    //struct record a;
    char filename[30];
    
    printf("\n\n\t\t====================================\n");
    printf("\t\t\t - LIST RECORDS -");
    printf("\n\t\t====================================\n");
    
    fp=fopen("filename","rb");
    rewind(fp);
    while((fread(&a,sizeof(a),1,fp))==1)
    {
        printf("\n\n\t\t::PRESS ENTER TO VIEW MORE RECORDS!::\n");
        printf("\nCONVICT'S NAME IS: %s",a.name);
        printf("\nCONVICT'S SEX IS: %s",a.gender);
        printf("\nCONVICT'S AGE IS: %s",a.age);
        printf("\nCONVICT'S WEIGHT IS: %s",a.weight);
        printf("\nCONVICT'S HEIGHT IS: %s",a.height);
        printf("\nCONVICT'S HAIRCOLOR IS: %s",a.haircolor);
		printf("\nCONVICT'S EYECOLOR IS: %s",a.eyecolor);
        printf("\nCONVICT'S CRIME IS: %s",a.crime);
        printf("\nFACE DETAILS: %s",a.details);
        printf("\nCOURT IS: %s",a.court);
        printf("\nACT: %s",a.act);
        printf("\nCONVICT'S CONVICTION IS: %s",a.punishment);
        printf("\nADDRESS OF POLICE STATION: %s",a.faddress);
        printf("\nFIR NUMBER: %s",a.fir);
        printf("\nCONVICT'S EMERGENCY CONTACT IS: %s",a.emergencyc);
        printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s",a.emergencyr);
        printf("\nARRESTED DATE: %s",a.datearr);
        getch();
        
    }
    fclose(fp);
	getch();
	
}


//*********************************************************
/**************** DELETING FUNCTION************************/
//*********************************************************

void deleterecord( )

{

    system("cls");
    FILE *fp,*ft ;
    struct record file ;
    char filename[15],another = 'Y' ,id[16];;
    int choice,check;
    int j=0;
    char pass[8];

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- DELETE RECORDS -");
    printf("\n\t\t====================================\n\n");
    
    printf("\nENTER PASSWORD\n");
    int i;
    for(  i=0;i<4;i++)
    {
    	pass[i]=getch();
    	printf("*");
	}
	if (strcmpi(pass,"pass")==0)
	{
	
     printf("\n\t\t*ACCESS GRANTED*\n\n");
   while ( another == 'Y' || another == 'y' )

    {
       
    	printf("\n\tENTER THE NAME OF CONVICT TO BE DELETED:");
		fflush(stdin);
        gets(filename);
        fp = fopen ("filename", "rb" ) ;
        if ( fp == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
				}
				ft=fopen("temp","wb");
				
				if(ft==NULL)
                {
                	printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getch();
                    return ;
                }
                printf("\n\tENTER THE ID OF RECORD TO BE DELETED:");
                fflush(stdin);
                gets(id);

        		while(fread(&file,sizeof(file),1,fp)==1)

                {

                    if(strcmp(file.id,id)!=0)

                        fwrite(&file,sizeof(file),1,ft);

                }
        fclose(ft);
        fclose(fp);
        remove("filename");
        rename("temp","filename");
        printf("\nDELETED SUCCESFULLY...");
        getch();

        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf("%c",&another);

    }
   

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();
}
	else
	{
		printf("\nSorry!Invalid password\n");
		exit(0);
	}

}

void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n  ======================  LOGIN FORM  ======================  \n");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n    WELCOME TO POLICE FIR RECORD MANAGEMENT SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		system("cls");
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}
