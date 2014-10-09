#include <iostream>

using namespace std;

const static int startI = 6;
int f(int i);
string tab(int i);

int main(int argc, char* argv[]) {
  f(startI);
}

int f(int i) {
  cout << tab(i) << "Start to run f(" << i << ") ... " << endl;
  if (i == 1 || i == 2) {
    cout << tab(i) << "f(" << i << ") = 1, returning ..." << endl;
    return 1;
  }
  int result = f(i - 1) + f(i - 2);
  cout << tab(i) << "f(" << i << ") = " << result << ", returning ..." << endl;
  return result;
}

string tab(int i) {
  if (i == startI) return "";
  return "    " + tab(i + 1);
}
