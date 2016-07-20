#include "minmax.h"
using namespace std;

int abs(int a) {
    if (a < 0) return -a;
    return a;
}

int max(const int a, const int b) {
    if (a > b) return a;
    return b;
}

int min(const int a, const int b) {
    if (a < b) return a;
    return b;
}
