#include "Interface.h"

bool Interface::userValidation(string name, int* index){
    for (int i = 0; i < users.size(); i++)
    if (users[i].nickname == name){
        if (index != nullptr) *index = i;
        return false;
    }
    return true;
}

void Interface::showaAlert(string alert, int exitCode){
    cout<<alert<<endl;
    
    if (exitCode) {
        update_file(std::filesystem::current_path().string() + "\\NEWDATA.dat", users);
        exit(exitCode);      
    }
}
void Interface::registerUser(){
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
            //cout<<"Matches\n";
            //cout<<"Password1 was: "<<password1<<endl;
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
    write_user(std::filesystem::current_path().string() + "\\NEWDATA.dat", users, user);
    /*for (int i = 0; i<users.size(); i++) {
        string tempName, tempPassword;
        users[i].getUserData(tempName, tempPassword);
        cout<<i<<") Name: "<<tempName<<" <====> Password: "<<tempPassword<<endl;
    }*/
    system("cls");
    cout << "You entered as " << user.nickname << ". Your level: " << user.level << "." << endl << endl;
    userWorkLoop(users[users.size()-1]);
}

bool Interface::authorize(int& index) {
    string inputName;
    string inputPassword;
    cout << "Enter your name: "; getline(cin.ignore(), inputName);
    if (!userValidation(inputName, &index)) {
        cout << "Enter your password: "; getline(cin, inputPassword);
        //cout << "\nEntered password is: " << inputPassword << endl;
        string tempName, tempPassword;
        users[index].getUserData(tempName, tempPassword);
        if (inputPassword == tempPassword) {
            system("cls");
            cout << "You entered as " << tempName << ". Your level: " << users[index].level << "." <<endl << endl;
            //cout << "Done! Your name and password are: " << tempName << " === " << tempPassword << endl;
            return true;
        }
        else
        {
            showaAlert("Password is wrong. Try again");
            _getch();
            start();
        }
    }
    else
    {
        showaAlert("Unfortunately, there's no user with this name");
        _getch();
        start();
    }
    return false;
}

void Interface::userWorkLoop(Profile& user){
    cout<<"Hey! You can go to levels for learning English, sign out or exit\nShow Levels - 2\nSign Out - 1\nExit - 0\n";
    char choice;
    bool flag = 0;

    DirectoryParser parser(user);
    do{
        cout << "Your choice: "; cin >> choice;
        switch (choice) {
            case '2':
                system("cls");
                //cout<<"Levels"<<endl;
                do
                {
                    parser.show_material_list(user);
                    system("cls");
                    cout << "Want more? (y/n) Choice: "; cin >> choice;

                } while (choice == 'y');
                

                flag = 1; break;

            case '1':
                start();
                break;
            case '0':
                showaAlert("GoodBye!", 1);
                break;
            default:
                system("cls");
                showaAlert("Wrong choice. Try again");
                cout << "You entered as " << user.nickname << ". Your level: " << user.level << "." << endl << endl;
                userWorkLoop(user);
        }
        if (flag) break;
    }while(true);
}



void Interface::start() {
    char ch;

    users = read_users(std::filesystem::current_path().string() + "\\NEWDATA.dat");

    int index = -1;
    while (true)
    {
        system("cls");
        cout << "Hello! Already have an account or want to register?\nRegister - 0\nAuthorize - 1\nEnter as teacheristrator - 2\n";
        bool flag = 0;
        cout << "Choice: "; cin >> ch;
        system("cls");
        switch (ch) {
        case '0':
            registerUser();
            flag = 1;
            break;
        case '1':
            if (authorize(index))
            {
                do
                {
                    userWorkLoop(users[index]);
                    cout << "Wonna exit? (y/n) Choice: "; cin >> ch;
                    system("cls");
                    if (ch != 'y') {
                        cout << "You entered as " << users[index].nickname << ". Your level: " << users[index].level << "." << endl << endl;
                    }
                } while (ch != 'y');
            }

            flag = 1;
            break;
        case '2': {
            string code = "";
            bool isTeacher = false;
            while (!isTeacher) {
                cout << "Give the ADMIN-code to enter or press 0: "; cin >> code;
                if (code == "0") break;
                if (code == teacherCode) isTeacher = true;
            }
            flag = 1;
            if (isTeacher) {
                Teacher teacher;
                teacher.teacherInterface();
            }
            break;
        }
        default:
            showaAlert("Try again");
            _getch();
            break;
        }
        if (flag) break;
    }
    update_file(std::filesystem::current_path().string() + "\\NEWDATA.dat", users);
};
