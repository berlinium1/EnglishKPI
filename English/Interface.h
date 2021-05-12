//
//  Interface.h
//  English
//
//  Created by Берлинский Ярослав Владленович on 12.05.2021.
//

#ifndef Interface_h
#define Interface_h

#include "Header.h"
#include "Profile.h"

class Interface{
    vector<Profile> users;
    void showaAlert(string alert, int exitCode = 0){
        cout<<alert<<endl;
        if (exitCode) exit(exitCode);
    }
    void registerUser(){
        string name;
        string password1;
        string password2;
        //do{
            cout<<"Enter your name: "; getline(cin, name); cin.ignore();
            cout<<"Enter you password: "; getline(cin, password1); cin.ignore();
            cout<<"Enter it again: "; getline(cin, password2); cin.ignore();
            if (password1 == password2) //break;
            showaAlert("Passwords doesn't match each other. Try again");
        //}
        //while(true);
        Profile user(name, password1);
        write_user(std::__fs::filesystem::current_path().string() + "\\" + "user.dat", users, user);
    }
public:
    void start(){
        char ch;
        cout<<"Hello! Already have an account or want to register?\nRegister - 0\nAuthorize - 1\n";
        while(true){
            bool flag = 0;
            cin>>ch;
            switch (ch) {
                case '0':
                    registerUser();
                    flag = 1;
                    break;
                case '1':
                    // authorization
                    break;
                default:
                    showaAlert("Try again\n");
                    break;
            }
            if (flag) break;
        }
    }
    void userWorkLoop(){
        cout<<"Hey! To start learning English choose one of the available levels:\n";
    }
};

#endif /* Interface_h */
