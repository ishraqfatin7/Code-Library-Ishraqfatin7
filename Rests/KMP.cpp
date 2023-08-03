#define VI vector<int>

VI computeLPSArray(string pat, VI lps)
{
    int len = 0;
    lps[0] = len;
    int i = 1;

    while (i < pat.size())
    {
        if (pat[len] == pat[i])
            ++len, lps[i] = len, i++;
        else
            len != 0 ? (len = lps[len - 1]) : (lps[i] = len, i++);
    }

    return lps;
}

int KMPSearch(string txt, string pat)
{
    int PAT_SIZE = pat.size();
    int TXT_SIZE = txt.size();

    VI lps(PAT_SIZE, 0);

    lps = computeLPSArray(pat, lps);

    int count = 0;

    int i = 0;
    int j = 0;
    while ((TXT_SIZE - i) >= (PAT_SIZE - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == PAT_SIZE)
        {
            count++;
            j = lps[j - 1];
        }

        else if (i < TXT_SIZE && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return count;
}