//
//  theory.cpp
//  English
//
//  Created by Берлинский Ярослав Владленович on 12.05.2021.
//

#include "Theory.h"

Test::Test(string task, char rightAnswer){
    this->task = task;
    this->rightAnswer = rightAnswer;
}

bool Test::checkAnswer(char answer){
    return rightAnswer == answer;
}

bool Test::show_test(){
    cout<<task<<endl;
    char ch;
    cout << "Your answer: "; cin >> ch;
    if (!checkAnswer(ch)) cout << "Incorrect!" << endl;
    else cout << "Right!" << endl;
    return checkAnswer(ch);
}


Theory::Theory(string path){
    this->isAlreadyDone = false;
    ifstream source(path);
    if (source.is_open()) {
        string str, task;
        vector <string> tasks;
        int counter = 0;
        
        /// Reading the first part
        do {
            getline(source, str);
            if (counter == 0){
                title = str;
                counter++;
                continue;
            }
            if (str == "#TEST") {
                //theory += "\nTest:\n";
                break;
            }
            theory += str + '\n';
        } while (!source.eof());
        counter = 0;
        /// Reading the second part
        do {
            getline(source, str);
            if (str[0] == '#') {
                if (counter != 0) tasks.push_back(task);
                counter++;
                task = "";
                task += str + '\n';
                if (str == "#RIGHT ANSWERS:") break;
                continue;
            }
            task += str + '\n';
        } while (!source.eof());
        
        /// Reading the third part
        do {
            getline(source, str);
            if (str == "#RIGHT ANSWERS:") continue;
            else for(int i = 0; i<str.size(); i++){
                Test test(tasks[i], str[i]);
                tests.push_back(test);
            }
        } while (!source.eof());
            /*for (int i = 0; i < tests.size(); i++) {
                cout<<tests[i].task;
                cout<<tests[i].rightAnswer<<endl;
            }*/
        source.close();
    }
}

void Theory::show_theory(){
    cout<<theory;
}

void Theory::show_tests(Profile &user){
    float score = 0;
    for (int i = 0; i < tests.size(); i++)
        if (tests[i].show_test() == false)
            isAlreadyDone = true;
    if (isAlreadyDone) user.setScore(score);
    else{
        isAlreadyDone = true;
        if (user.level == level) {
            score = 1;
        }
        user.setScore(score);
    }
}
