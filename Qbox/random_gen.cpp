#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime> 

using namespace std;

int main() {
    int n, b;
    cin >> n, b;

    srand(time(0));

    ofstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    while (n--) {
        file << rand() % 901 + 100 << " ";
    }

    file.close();
    return 0;
}