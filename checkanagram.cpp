// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically //using all the original letters exactly once.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true

#include <iostream>
#include <string>
using namespace std;

bool Anagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    int count[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s = "antats";
    string t = "tantar";
    int ans = Anagram(s, t);
    cout << ans;
    return 0;
}