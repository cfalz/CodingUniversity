#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main() {

    std::vector<int> v;
    
    for(int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    
    v.emplace(v.begin(), 100);

    for( auto i : v ) { cout << i << endl; }

    cout << v.size() << endl;
    cout << v.max_size() << endl;

    return 0;

}

