#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#define SIZE_CAT 250

static int i = 0;

struct Password{
	char manager_username[25];
	char manager_pw[25];
	
}Acgrant[10];

struct clients_record {
	char clients_fname[25];
	char clients_lname[25];
	char reg_date;
	int reg_no;
	int clients_idno;
	int category[250];
	float Amt_paid;
	
}reg_detail[250];

 
int user_option;

int menuchoice(void);
void systemauthorization();  void login(FILE *asig); void reg(void);
void Addclient (); void searchslot ();
void wrt_Assign_slot(FILE * wrftp);

int main()
{
	//A_grant record;
	int menu_opt;
	FILE *registrationlog =NULL;
	FILE * sysfilept;
	
//	systemauthorization();
/*	if ((registrationlog=fopen("subscription.txt", "rb+"))==NULL){
		printf("File not found!\n");
		
	}else{
*/			while((menu_opt = menuchoice() ) != 4){
		switch (menu_opt){
			case 1:
			//	systemauthorization(record);
				printf("assign parking\n");
						printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
if(getch()==13)
  //clrscr();
XY:
printf("\n\n\n\t\t\t1. LOGIN\t\t2. REGISTER");
printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
scanf("%d",&user_option);
switch(user_option)
  {
    case 1: //clrscr();
        login(registrationlog);
        
       // Addclient ();
        printf("\nProceed by pressing enter to adding client\n");
        break;
    case 2: //clrscr();
        reg();
        break;
    default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice");
        if(getch()==13)
        //clrscr();
        goto XY;
  }
				break;
				
				case 2:
					printf("Search for a slot\n");
					login(registrationlog);
				//	searchslot ();
					break;
					
					case 3:
						login(registrationlog);
					//	wrt_Assign_slot(registrationlog);
						break;
						
						default:
							printf("Invalid\n");
							break;
			
		}
		
	} 
		
//	}

  return 0;
}	


//password for system-user
//void systemauthorization(){

void reg()
  {
    FILE *systemlog = NULL;
    char c, checker[30];
	int z=0;
    systemlog=fopen("storeauthorization.txt","ab+");
    printf("\n\n\t\t\t\tWELCOME TO REGISTER ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");
    for(i=0;i<100;i++)
    {
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);
      
        while(!feof(systemlog)){
        	
          fread(&Acgrant[i],sizeof(Acgrant[i]),1,systemlog);
          if(strcmp(checker,Acgrant[i].manager_username)==0){
            printf("\n\n\t\t\tUSERNAME ALREADY EXISTS");
            //clrscr();
            reg();
            }
          else
          {
            strcpy(Acgrant[i].manager_username,checker);
            break;
          }
        }
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      while((c=getch())!=13)
        {
          Acgrant[i].manager_pw[z++]=c;
          printf("%c",'*');
        }
      fwrite(&Acgrant[i],sizeof(Acgrant[i]),1,systemlog);
      fclose(systemlog);
      printf("\n\n\tPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
        //clrscr();
        printf("\n\n\t\tYou are successfully registered");
        printf("\n\n\t\tTry login your account??\n\n\t\t  ");
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        scanf("%d",&user_option);
        switch(user_option)
          {
              case 1:// clrscr();
                    login(systemlog);
                    break;
              case 2: //clrscr();
                    printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
                    break;
          }
        }
        break;
      }
      
    getch();
  }
  void login(FILE * asig)
    {
      FILE *systemlog;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp, choice_cont;
      systemlog=fopen("storeauthorization.txt","rb");
      printf("\n\n\t\t\t\tWELCOME TO LOG IN ZONE");
      printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");
      for(i=0;i<250;i++)
      {
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
         pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
      while(!feof(systemlog))
        {
        fread(&Acgrant[i],sizeof(Acgrant[i]),1,systemlog);
          checku=strcmp(name,Acgrant[i].manager_username);
          checkp=strcmp(pass,Acgrant[i].manager_pw);
          if(checku==0&&checkp==0)
          {
            //clrscr();
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY\n\n");
            
            	printf("RE-enter your choice to proceed\n");
            	scanf("%d", &choice_cont);
            	
				while ((choice_cont = menuchoice())  !=6){
            		switch(choice_cont){
            		case 1:
            			printf("yes add\n");
            			Addclient (); //function call to add new client
            			break;
            		case 2:
            			printf("yes search\n");
            			//searchslot (); // function call to search for categories
            			break;
            		case 3:
            			printf("yes assign\n");
            			wrt_Assign_slot(systemlog);
            			break;
       				default:
						printf("Invalid\n");
						break;
    
				}
				break;
				}
				
            	break;	
           
          }
        else if(checku==0&&checkp!=0)
          {
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login(systemlog);
          }
        else if(checku!=0)
          {
            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
            if(getch()==13)
            //clrscr();
            reg();
          }
        }
        break;
      }
      getch();

}

int menuchoice(void){
	int menucho; 
	printf("WELCOME TO MENU OPTION\n");
	printf("%s", "\nEnter Your Menu Option\n"
		"1 - Add client\n" 
			"2 - Search for a slot\n" 
				"3 - Add Parking slot\n"
					"4 - Assign a slot\n" 
						"5 - Generate reciept\n"
						);
	
	scanf("%u", &menucho);
	return menucho;
} 

void Addclient (){
		FILE *registrationlog =NULL;
		static int clients_num[250];
		int x, slotnum=0;
		 struct clients_record clrecord; // = { "", "", "", 0, 0, 0, 0.0};
		
		if ((registrationlog=fopen("subscription.txt", "w"))==NULL){
			printf("File to add client not found:\n");
		}else{ 
				printf("Please enter your national id number:\n");
				scanf("%d", &clients_num[i]);
				
				fseek(registrationlog, (clients_num[i] - 1)* sizeof(struct clients_record), SEEK_SET);
				
			//	fread(&clrecord, sizeof(struct clients_record), 1, registrationlog);
				
				while(!feof(registrationlog)){
					fprintf(registrationlog, "%s\t%s\t%d\t%d\t%lf", clrecord.clients_fname,clrecord.clients_lname,clrecord.reg_no,clrecord.category,clrecord.Amt_paid);
					
				/*	if (clrecord.clients_idno !=0){
						printf("The client %d is already registred \n", clrecord.clients_idno);
					}else{
				*/
						clrecord.clients_idno = clients_num[i];
						printf("%s", "Enter Client First Name\n" );
						scanf("%s", &clrecord.clients_fname);
						printf("%s", "Enter Client Last Name\n" );
						scanf("%s", &clrecord.clients_lname);
						printf("%s", "Registration Number\n" );
						scanf("%d",  &clrecord.reg_no);
					//	printf("%s", "Enter Client Identification No..\n" );
					//	scanf("%d", &clrecord.clients_idno);
						printf("%s", "Category\n" );
						scanf(" %d",  &clrecord.category);
						printf("%s", "Amount Paid:\n" );
						scanf("%lf",&clrecord.Amt_paid);
						
						
							fseek(registrationlog, (clrecord.clients_idno - 1)* sizeof(struct clients_record), SEEK_SET);
							
							fwrite(&clrecord, sizeof(struct clients_record), 1, registrationlog);
				//	}					
					
					
				}

			
		}
		fclose(registrationlog);	
	
}
/*
void searchslot (){
			 
			 static int j, subs;
	
			FILE *registrationlog =NULL;
			
				
			
			struct clients_record clrecord[250];
			
				if ((registrationlog=fopen("subscription.txt", "rb+"))==NULL){
					printf("File not found foe search\n");
				}else{
					printf("\nType of Parking category Avialable\n");
					
				//	while (!feof(registrationlog)){
						
					for (j = 0; j<10; j++){
							printf("choose your subscription\n");
							scanf("%d", &subs);
							
								if (clrecord[j].category,250){
									printf("The slots are empty and ready!\n");
								}else
									 if(clrecord[j].category,100){
										printf("Welcome to Ultra Premium!\n");
								}else
									if(clrecord[j].category,50){
										printf("Welcome to VIP Exclusive!\n");
									}else
										if(clrecord[j].category[151],250){
											printf("Welcome to Regular!\n");
										}
							
						}
					
					
						
				//	}
					
				}				
	fclose(registrationlog);
}
*/
void wrt_Assign_slot(FILE * wrftp){
		
		FILE * fwriteclient = NULL;
		
		struct clients_record assignslot;// = { "", "", "", 0, 0, 0, 0.0 };
		
		int holdinfo;
		
		if ((fwriteclient = fopen("customerlist.txt", "w")) == NULL){
			printf("No files for customer list");
		}else {
			rewind(wrftp);
			fprintf(fwriteclient, "%-4s %-10s %-7s %4d %d %d %.2f\n", "client First-name", "client Last-name", "Date of Reg", "Registration Num", "Client identification", "Sub Category" );
			
			while (!feof(wrftp)){
				holdinfo = fread(&assignslot, sizeof(struct clients_record), 1, wrftp);
				
				if (holdinfo != 0 && assignslot.clients_idno !=0){
					fprintf(fwriteclient, "%-4s %-10s %-7s %d %d %d %.2f\n", &assignslot.clients_fname, &assignslot.clients_lname, &assignslot.reg_date, &assignslot.reg_no, &assignslot.clients_idno, &assignslot.category, &assignslot.Amt_paid);
					
				}
			}
			
			fclose(fwriteclient);
		}
	
	
}


