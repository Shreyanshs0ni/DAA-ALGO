#include <iostream>
#include <vector>
using namespace std;

vector<int> LPS(string p)
{
    int n = p.size();
    vector<int> lps(n, 0);

    for (int i = 1, len = 0; i < n;)
    {
        if (p[i] == p[len])
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    return lps;
}

void KMP(string txt, string pat)
{
    vector<int> lps = LPS(pat);
    int i = 0, j = 0;

    while (i < txt.size())
    {
        if (txt[i] == pat[j])
            i++, j++;

        if (j == pat.size())
        {
            cout << i - j << " ";
            j = lps[j - 1];
        }
        else if (i < txt.size() && txt[i] != pat[j])
        {
            if (j)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main()
{
    string txt = "ababcabcabababd";
    string pat = "ababd";

    KMP(txt, pat);
}