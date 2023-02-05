#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int bagOfTokensScore(vector<int> &tokens, int power) {
  sort(tokens.begin(), tokens.end());

  int i = 0;
  int j = tokens.size() - 1;
  int score = 0;

  while (i <= j) {
    cout << "power: " << power << endl;
    if (tokens[i] <= power) {
      cout << "cousume: " << tokens[i] << endl;
      power -= tokens[i];
      score++;
      i++;
    } else {
      cout << "provide: " << tokens[j] << endl;
      power += tokens[j];
      score--;
      j--;
    }
  }

  return score;
}

int main() {
  vector<int> tokens = {100};
  int power = 50;
  cout << bagOfTokensScore(tokens, power) << endl;

  tokens = {100, 200};
  power = 150;
  cout << bagOfTokensScore(tokens, power) << endl;

  tokens = {100, 200, 300, 400};
  power = 200;
  cout << bagOfTokensScore(tokens, power) << endl;

  // tokens = {26};
  // power = 51;
  // cout << bagOfTokensScore(tokens, power) << endl;
  //
  // tokens = {71, 55, 82};
  // power = 54;
  // cout << bagOfTokensScore(tokens, power) << endl;

  return 0;
}
