#include <bits/stdc++.h>

bool checkPalindrome(string s)

{

    int start = 0;

    int end = s.length() - 1;

    while (start <= end)

    {

        if (!isalnum(s[start]))

        {

            start++;
        }

        else if (!isalnum(s[end]))

        {

            end--;
        }

        else

        {

            if (tolower(s[start]) != tolower(s[end]))

            {

                return false;
            }

            start++;

            end--;
        }
    }

    return true;
}