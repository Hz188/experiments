#include "calculator.h"
#include "add.h"
#include "sub.h"

int Calculator::calcAdd(int x, int y) {
   return add(x, y); 
}

int Calculator::calcSub(int x, int y) {
    return sub(x, y);
}