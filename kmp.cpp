#include<bits/stdc++.h>
 
using namespace std;
int kmpBrute(string String, string pattern) {
  int n = String.size(), m = pattern.size();
  for (int i = 0; i < n + 1 - m; i++) {
    int j = 0;
    while (j < m && String[i + j] == pattern[j])
      j++;
    if (j == m) return i;
  }
  return -1;
}
int main() {
  string pattern="aaaaaab", String="aaaaaaaamaaaaaab";

  int index = kmpBrute(String, pattern);
  if (index == -1) cout << "The pattern is not found";
  else cout << "The pattern " << pattern << " is found in the given string " 
  << String << " at " << index;
  return 0;
}
