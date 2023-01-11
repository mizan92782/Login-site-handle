
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct user
{
    char E_mail[200];
    char password[200];
};




void profile(struct user mizan)
{
              printf("\n\t\tYOUR INFORMATION\n");
              printf("E- mail : %s\n",mizan.E_mail);
              printf("password : %s\n",mizan.password);


}


int main()
{

    struct user mizan;


    printf("\t\t TO LOGIN  GIVE YOUR INFORMATION \n");
    printf("ENTER YOUR E-MAIL : "); gets(mizan.E_mail);


    printf("ENTER YOUR PASSWORD : ");
    gets(mizan.password);
    system("cls");


FILE *femail;
    femail=fopen("email.TXT","r");
      char emailread[200];
      fgets(emailread,200,femail);
      int k=strcmp(emailread,mizan.E_mail);
      if(k!=0)
      {

          system("cls");
          printf("E- MAIL IS WRONG %c\n",(char)7);
          exit(0);
      }

fclose(femail);



FILE *fp=fopen("mizan.TXT","r");
    int str[200];
    fgets(str,200,fp);



     int  i=strcmp(str,mizan.password);
    if(i!=0)
    {
     printf("%c",(char)7);
     printf("PASSWORD IS WRONG\n");
     exit(0);
    }

fclose(fp);






       printf("\n\n\t\tWELCOME TO OUR SERVICE  \n");
       int step;
       printf("CHOICE OUR SERVICE :\n1.MY PROFILE\n2.PASSWORD CHANGE \n3.OTHER SERVICE\n");
       printf("CHOICE : ");scanf("%d",&step);
       system("cls");


           if(step !=1 && step !=2 && step!=3)
           {
               printf("WRONG INFORMATION\n");
               exit(0);
           }




          if(step==2)
          {

            char pass1[200];
            char repass1[200];

            printf("\n\nTYPE NEW PASSWPRD  :");
            fgetc(stdin);
            gets(pass1);
            printf("RETYPE NEW PASSWPRD  :");
            gets(repass1);



            int j=strcmp(pass1,repass1);
            if(j==0)
            {
               strcpy(mizan.password,pass1);
               printf("%c",(char)7);


FILE *frecord=fopen("record.TXT","a");
              fputs(str,frecord);
              fputs("\n",frecord);
fclose(frecord);



               system("cls");
               printf("PASSWORD CHANGE SUCCESSFULLY\n");

fp=fopen("mizan.TXT","w");
               fputs(pass1,fp);
fclose(fp);
               profile(mizan);
            }else{
              printf("%c",(char)7);
              system("cls");
               printf("PASSWORd NOT MATCH\nPASSWORD CHANGE FAILD \n");

            }

          }




          if(step==1)
          {

                profile(mizan);
          }




 if(step==3)
          {
              printf("\t\t THANK FOR JOURNEY WITH US\n");

          }






return 0;
}
