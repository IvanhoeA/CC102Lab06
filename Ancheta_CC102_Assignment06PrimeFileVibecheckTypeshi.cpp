#include <iostream>
#include <fstream>
using namespace std;


/*assuming the file already exists
Numbers used:
3 4 5 6 7 8
10
12
13
17
49 51 53 59
Output: 7*/


bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    ifstream file("NUMS.txt");
    int num, count = 0;

    if (!file) {
        cout << "Error opening the file" << endl;
        return 1;
    }

    while (file >> num) {
        if (isPrime(num)) {
            count++;
        }
    }

    file.close();

    cout << "Number of Prime Numbers in the file: " << count << endl;
    return 0;
}
