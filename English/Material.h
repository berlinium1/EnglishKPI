#include <string>
#include <iostream>
using namespace std;

class Test {
public:
	Test() {}
	void show() {}
};

class Material {
private:
	string text;
	Test test;
public:
	Material(string text, Test test) : text(text), test(test) {}
	void show_material();
};