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
    vector<Profile> users = read_users(std::filesystem::current_path().string() + "\\" + "user.dat");

    bool userValidation(string name, int *index = nullptr){
        for (int i = 0; i < users.size(); i++)
        if (users[i].nickname == name){
            if (index != nullptr) *index = i;
            return false;
        }
        return true;
    }
    void showaAlert(string alert, int exitCode = 0){
        cout<<alert<<endl;
        if (exitCode) exit(exitCode);
    }
    void registerUser(){
        string name;
        string password1;
        string password2;
        bool flag = 0;
        do{
            cout<<"Enter your name: ";
            if (!flag){
                getline(cin.ignore(), name);
                flag = 1;
            }
            else getline(cin, name);
            if (!userValidation(name)) {
                showaAlert("This name's already existed");
                continue;
            }
            cout<<"Enter your password: "; getline(cin, password1);
            cout<<"Enter it again: "; getline(cin, password2);
            if (password1 == password2){
                cout<<"Matches\n";
                cout<<"Password1 was: "<<password1<<endl;
                break;
            }
            else showaAlert("Passwords doesn't match each other. Try again");
            cout<<"Password1 was: "<<password1<<endl;
            cout<<"Password2 was: "<<password2<<endl;
        }
        while(true);

        Profile user;
        user.setUserData(name, password1);
        
        write_user(std::filesystem::current_path().string() + "\\" + "user.dat", users, user);
//MAC: users = read_users("/Users/yaroslav/Desktop/EnglishKPI/English/Sources/UserData/userDATA.dat");
//MAC: write_user("/Users/yaroslav/Desktop/EnglishKPI/English/Sources/UserData/userDATA.dat", users, user);
//        for (int i = 0; i<users.size(); i++) {
//            cout<<i<<") Name: "<<users[i].user.name<<" <====> Password: "<<users[i].user.password<<endl;
//        }
    }
public:
    void start(){
        char ch;
        cout<<"Hello! Already have an account or want to register?\nRegister - 0\nAuthorize - 1\n";
        bool flag = 0;
        bool isInSystem = 0;
        users = read_users("/Users/yaroslav/Desktop/EnglishKPI/English/Sources/UserData/DAT.dat", flag);
        while(true){
            bool flag = 0;
            cin>>ch;
            switch (ch) {
                case '0':
                    registerUser();
                    flag = 1;
                    break;
                case '1':
                    authorize();
                    flag = 1;
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
