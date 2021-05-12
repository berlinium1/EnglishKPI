//
//  Profile.h
//  English
//
//  Created by Берлинский Ярослав Владленович on 12.05.2021.
//

#ifndef Profile_h
#define Profile_h

#include "Header.h"

//temp
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
    Profile(){}
    Profile(string nickname, string password){
        this->user.name = nickname;
        for (int i = 0; i <= nickname.size(); i++) this->nickname[i] = nickname.c_str()[i];
        this->user.password = password;
    }
    //
    
    void print();
};

vector<Profile> read_users(string path); // read all users at the beginning
void write_user(string path, vector<Profile>&, Profile); // write one new user

#endif /* Profile_h */
