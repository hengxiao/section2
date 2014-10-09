#include <iostream>

using namespace std;

int gcd(int x, int y);

int main (int argc, char* argv[]) {
  int x, y;
  cout << "Please input value of x: ";
  cin >> x;
  cout << "Please input value of y: ";
  cin >> y;
  int result = gcd(x, y);
  cout << "The greatest common divisor is: " << result << endl;
  return 0;
}

int gcd(int x, int y) {
  int remainder = x % y;
  if (remainder == 0) {
    return y;
  } else {
    return gcd(y, remainder);
  }
}
