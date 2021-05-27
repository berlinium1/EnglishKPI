#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

class Profile
{
public:
    char nickname[100];
    char password[100];
    float score = 0;
    int level = 0;
    
    //temp
    void setUserData(string nickname, string password);
    
    void getUserData(string& nickname, string& password);
    
    void setScore(float score);
    
    float getScore();
    
    void print();
};

vector<Profile> read_users(string path); // read all users at the beginning
void write_user(string path, vector<Profile>&, Profile); // write one new user
void update_file(string path, vector<Profile>&);


class Teacher
{
    vector<Profile> users;
    void getUserProfile(int index);
    void seeAllProfiles();
    
    // в поле аргументов можно убрать путь, т.к. мы всё равно с стд::филэсустем
    void createLesson(string path);
    
    
public:
    Teacher();
    
    void teacherInterface();

    
    
};
