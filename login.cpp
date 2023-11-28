#include<bits/stdc++.h>
using namespace  std;


struct User
{
    std::string E_mail;
    std::string password;
};

void profile(const User& mizan)
{
    std::cout << "\n\t\tYOUR INFORMATION\n";
    std::cout << "E-mail: " << mizan.E_mail << "\n";
    std::cout << "Password: " << mizan.password << "\n";
}

int main()
{

    
    User mizan;

    std::cout << "\t\t TO LOGIN GIVE YOUR INFORMATION \n";
    std::cout << "ENTER YOUR E-MAIL : ";
    std::getline(std::cin, mizan.E_mail);

    std::cout << "ENTER YOUR PASSWORD : ";
    std::getline(std::cin, mizan.password);

    std::ifstream femail("email.TXT");
    std::string emailread;
    std::getline(femail, emailread);

    if (emailread != mizan.E_mail)
    {
        std::cout << "E-MAIL IS WRONG \a\n";
        main();
        exit(0);
        return 0;
    }

    femail.close();

    std::ifstream fp("pass.TXT");
    std::string str;
    std::getline(fp, str);
    fp.close();

    if (str != mizan.password)
    {
        std::cout << "PASSWORD IS WRONG \a\n";
         main();
       exit(0);
    }

    std::cout << "\n\n\t\tWELCOME TO OUR SERVICE  \n";
    int step;
    std::cout << "CHOICE OUR SERVICE :\n1. MY PROFILE\n2. PASSWORD CHANGE\n3. OTHER SERVICE\n";
    std::cout << "CHOICE : ";
    std::cin >> step;

    if (step<1 && step>3)
    {
        std::cout << "WRONG INPUT\n";
       
        return 0;
    }

    if (step == 2)
    {
        std::string pass1, repass1;

        std::cout << "\n\nTYPE NEW PASSWORD: ";
        std::cin.ignore();
        std::getline(std::cin, pass1);

        std::cout << "RETYPE NEW PASSWORD: ";
        std::getline(std::cin, repass1);

        if (pass1 == repass1)
        {
            mizan.password = pass1;

            std::ofstream frecord("record.TXT", ios::app);
            frecord << mizan.password << "\n";
            frecord.close();

            std::ofstream fp("mizan.TXT");
            fp << mizan.password;
            fp.close();

            std::cout << "\aPASSWORD CHANGE SUCCESSFULLY\n";
            profile(mizan);
        }
        else
        {
            std::cout << "\aPASSWORDS DO NOT MATCH\nPASSWORD CHANGE FAILED\n";
        }
    }

    if (step == 1)
    {
        profile(mizan);
    }

    if (step == 3)
    {
        std::cout << "\t\t THANKS FOR JOURNEYING WITH US\n";
    }

    return 0;
}
