#include "array.h"
#include "array.cc"

int main() {

    assert(test_push());
    assert(test_insert());
    assert(test_resize());
    assert(test_pop());
    assert(test_delete_element());
    assert(test_find());

    cout << "ALL TESTS PASSED." << endl;


    return 0;
}


