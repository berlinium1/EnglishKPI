#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class User{
public:
    string name;
    string password;
};
//

struct Profile
{
    //temp
    User user;
    //
    
    char nickname[100]; // for nickname
    float score; // points
    int level;
    
    //temp
    void setUserData(string nickname, string password){
        this->user.name = nickname;
        this->user.password = password;
        for (int i = 0; i <= nickname.size(); i++) this->nickname[i] = nickname.c_str()[i];
    }
    //
    void print();
};

vector<Profile> read_users(string path); // read all users at the beginning
void write_user(string path, vector<Profile>&, Profile); // write one new user
