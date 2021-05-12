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
    cout<<"Give the right answer: "; cin>>ch;
    cout<<checkAnswer(ch)<<endl;
    return checkAnswer(ch);
}


Theory::Theory(string path){
    path = std::filesystem::current_path().string() + "\\" + path;
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
//            for (int i = 0; i < tests.size(); i++) {
//                cout<<tests[i].task;
//                cout<<tests[i].rightAnswer<<endl;
//            }
        source.close();
    }
}

void Theory::show(){
    cout<<theory;
}
