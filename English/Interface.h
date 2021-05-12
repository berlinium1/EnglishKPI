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
    void registerUser(int &index){
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

        //users = read_users(std::__fs::filesystem::current_path().string() + "\\" + "user.dat");
        //write_user(std::__fs::filesystem::current_path().string() + "\\" + "user.dat", users, user);
        write_user("/Users/yaroslav/Desktop/EnglishKPI/English/Sources/UserData/NEWDATA.dat", users, user);
        for (int i = 0; i<users.size(); i++) {
            string tempName, tempPassword;
            users[i].getUserData(tempName, tempPassword);
            cout<<i<<") Name: "<<tempName<<" <====> Password: "<<tempPassword<<endl;
        }
        index = (int)users.size()-1;
        userMainView(index);
    }
bool authorize(int &index){
        string inputName;
        string inputPassword;
        cout<<"Enter your name: "; getline(cin.ignore(), inputName);
        if (!userValidation(inputName, &index)) {
            cout<<"Enter your password: "; getline(cin, inputPassword);
            cout<<"\nEntered password is: "<<inputPassword<<endl;
            string tempName, tempPassword;
            users[index].getUserData(tempName, tempPassword);
            if (inputPassword == tempPassword) {
                cout<<"Done! Your name and password are: "<<tempName<<" === "<<tempPassword<<endl;
                return true;
            }
            else showaAlert("Password is wrong. Try again");
        }
        else showaAlert("Unfortunately, there's no user with this name");
        return false;
    }
    void userMainView(int &index){
        cout<<"Hey! You can go to levels for learning English, sign out or exit\nShow Levels - 2\nSign Out - 1\nExit - 0\nYour choice: ";
        char choice;
        bool flag = 0;
        do{
            cin>>choice;
            switch (choice) {
                case '2':
                    cout<<"Levels"<<endl;
                    flag = 1;
                    break;
                case '1':
                    start();
                    break;
                case '0':
                    showaAlert("GoodBye!", 1);
                    break;
                default:
                    showaAlert("Wrong choice. Try again");
            }
            if (flag) break;
        }while(true);
    }
    void userLevelsView(){}
public:
    void start(){
        char ch;
        cout<<"Hello! Already have an account or want to register?\nRegister - 0\nAuthorize - 1\n";
        bool isInSystem = 0;
        int index = -1;
        users = read_users("/Users/yaroslav/Desktop/EnglishKPI/English/Sources/UserData/NEWDATA.dat");
        while(true){
            bool flag = 0;
            cin>>ch;
            switch (ch) {
                case '0':
                    registerUser(index);
                    flag = 1;
                    break;
                case '1':
                    isInSystem = authorize(index);
                    if (isInSystem) userMainView(index);
                    flag = 1;
                    break;
                default:
                    showaAlert("Try again\n");
                    break;
            }
            if (flag) break;
        }
    }
};

#endif /* Interface_h */
