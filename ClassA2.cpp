#include "ClassA2.h"

ClassA2::ClassA2(ClassB &value) : refB(value) {}

string ClassA2::getBinfo() {
    return refB.getInfo();
}

void ClassA2::setBinfo(string value) {
    refB.setInfo(value);
}