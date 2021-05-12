#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Profile
{    
    char nickname[100];
    char password[100];
    float score;
    int level;
    
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

    void print();
};

vector<Profile> read_users(string path); // read all users at the beginning
void write_user(string path, vector<Profile>&, Profile); // write one new user
