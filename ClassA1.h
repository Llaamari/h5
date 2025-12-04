#ifndef CLASSA1_H
#define CLASSA1_H

#include "ClassB.h"
#include <string>
using namespace std;

class ClassA1 {
private:
    ClassB objectB; // Kopio oliosta B
public:
    ClassA1(ClassB); 
    string getBinfo();
    void setBinfo(string);
};

#endif