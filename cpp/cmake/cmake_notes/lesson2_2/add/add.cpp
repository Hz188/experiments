#include <iostream>
// #define EXPORT
#include "export.h"

CMAKE_STUDY_API int add(int a, int b) {
   return a + b;
}

// __declspec(dllexport) int add(int a, int b) {
//     return a + b;
// }