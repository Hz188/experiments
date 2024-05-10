#include "calculator.h"

int main() {
    Calculator cal;
    cal.calcAdd(10, 5);
    return 0;
}

/*
               - add.cpp <-
              /             \
common.cpp <-                calculator.cpp <- main.cpp
              \             /
               - sub.cpp  <-
*/