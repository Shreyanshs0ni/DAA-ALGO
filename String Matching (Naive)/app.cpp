#include <iostream>
using namespace std;

void search(string txt, string pat)
{
    for (int i = 0; i <= txt.size() - pat.size(); i++)
    {
        if (txt.substr(i, pat.size()) == pat)
            cout << i << " ";
    }
}

int main()
{
    string txt = "ababcabcabababd";
    string pat = "ababd";

    search(txt, pat);
}