//
//  main.cpp
//  English
//
//  Created by Берлинский Ярослав Владленович on 11.05.2021.
//

#include "Header.h"
#include "Theory.h"
#include "Interface.h"

int main(int argc, const char * argv[])
{
    //Test test("Task", 5, 1);
    //test.show_test();
    Theory theory("theory2.txt");
    theory.show();
    Interface app;
    app.start();
    return 0;
}