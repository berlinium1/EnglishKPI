#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Profile
{
public:
    char nickname[100];
    char password[100];
    float score;
    int level = 0;
    
    //temp
    void setUserData(string nickname, string password){
        for (int i = 0; i <= nickname.size(); i++) this->nickname[i] = nickname[i];
        for (int i = 0; i <= password.size(); i++) this->password[i] = password[i];
    }
    
    void getUserData(string& nickname, string& password)
    {
        int i = 0;
        while (this->nickname[i] != '\0')
        {
            nickname.push_back(this->nickname[i]);
            i++;
        }
        i = 0;

        while (this->password[i] != '\0')
        {
            password.push_back(this->password[i]);
            i++;
        }
    }
    
    void setScore(float score){
        this->score += score;
        if (score) (this->level)++;
    }
    
    float getScore(){
        return score;
    }
    
    void print();
};

vector<Profile> read_users(string path); // read all users at the beginning
void write_user(string path, vector<Profile>&, Profile); // write one new user
void update_file(string path, vector<Profile>&);


class Admin
{
    vector<Profile> users;
    void getUserProfile(int index){
        cout << "\n=== Profile № "<<index<<" ===\n";
        users[index].print();
    }
    void seeAllProfiles(){
        int choice;
        cout << "\n=== Profiles ===\n";
        for (int i = 0; i < users.size(); i++) {
            cout << "User[" << i + 1 << "] " << users[i].nickname << endl;
        }
        do {
            cout << "Choose one to show(№ in list): "; cin >> choice;
            if (choice >= 1 && choice <= users.size()) {
                getUserProfile(choice-1);
            }
            else if (choice != 0) cout << "There is no user beneath the №" << choice << endl;
            
        } while (choice != 0);
    }
    
    // need to be done
    bool loadNewLesson(string path){
        string title, line; vector<string> lesson;
        ifstream materials(path);
        if (materials.is_open()) {
            while (getline(materials, line)) {
                lesson.push_back(line);
            }
            materials.close();
            cout << "Exellent! Enter a title for the lesson: "; getline(cin, title);
            //
                ofstream lesson("путь, куда надо сохранить новый урок");
                //..........
            //
            return 1;
        }
        else{
            return 0;
        }
        
    }
    
public:
    Admin(){
        users = read_users(std::__fs::filesystem::current_path().string() + "\\NEWDATA.dat");
    }
    void adminInterface(){
        char choice;
        do{
            cout << "\nChoose what to do:\n0. Exit\n1. See user profiles\n2. Set new material to the system\nYour coice: "; cin >> choice;
            switch (choice) {
                case '1':
                    if (users.size() == 0) cout << "Empty. There's no user\n";
                    else seeAllProfiles();
                    break;
                case '2':{
                    string path; char ch; bool flag = false;
                    do {
                        cout << "Give a path to the lesson material: "; getline(cin, path);
                        if (loadNewLesson(path)){
                            cout << "Well! Want to add another lesson?\nYes - 1\nNo - 0\nYour choice: ";
                            cin >> ch;
                            switch (ch) {
                                case '1':
                                    flag = true;
                                    break;
                                default:
                                    flag = false;
                                    break;
                            }
                        }
                        else{
                            cout << "We cannot find the file in the path You gave\nWant to add another lesson?\nYes - 1\nNo - 0\nYour choice: ";
                            cin >> ch;
                            switch (ch) {
                                case '1':
                                    flag = true;
                                    break;
                                default:
                                    flag = false;
                                    break;
                            }
                        }
                    } while (flag);
                }
                default:
                    break;
            }
        }while(choice != '0');
    }

    
    
};
