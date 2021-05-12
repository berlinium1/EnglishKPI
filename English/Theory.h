//
//  Theory.h
//  English
//
//  Created by Берлинский Ярослав Владленович on 12.05.2021.
//

#ifndef Theory_h
#define Theory_h
#include "Header.h"

class Test{
public:
    int points;
    char rightAnswer;
    string task;
    bool checkAnswer(char answer);

public:
    Test(string task, char rightAnswer);
    bool show_test();
    //friend Theory::Theory(string path);
};

class Theory{
    string title;
    string theory;
    vector<Test> tests;
public:
    Theory(string path);
    void show();
};


#endif /* Theory_h */
