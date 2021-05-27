
#ifndef Interface_h
#define Interface_h

#include "Header.h"
#include "Profile.h"
#include "DirectoryParser.h"
#include <conio.h>
class Interface{
    vector<Profile> users;
    string teacherCode = "1234";
    bool userValidation(string, int* index = 0);
    void showaAlert(string, int code = 0);
    void registerUser();
    bool authorize(int& index);
    void userWorkLoop(Profile& user);
public:
    void start();
};

#endif /* Interface_h */
