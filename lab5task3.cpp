#include <iostream>
#include<string>
using namespace std;
int countWays(int numStairs) {
    if (numStairs <= 1)
        return 1;
    return countWays(numStairs - 1) + countWays(numStairs - 2);
}
int main() {
    int stairs;
    cout << "Enter number of stairs: ";
    cin >> stairs;

    cout << "Number of ways to climb " << stairs << " stairs = "
         << countWays(stairs) << endl;

    return 0;
}
