#include "array.h"
#include "array.cc"

int main() {

    assert(test_push());
    assert(test_insert());
    assert(test_resize());
    assert(test_pop());

    cout << "ALL TESTS PASSED." << endl;


    return 0;
}


