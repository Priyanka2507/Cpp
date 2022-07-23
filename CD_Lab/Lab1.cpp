#include <bits/stdc++.h>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    int states, symbol;
    cin >> states >> symbol;

    char mat[states][symbol][states];
    map<int, string> arr;
    map<char, int> arr1;
    map<int, string> ep;
    char ch;

    for (int i = 0; i < states; i++)
    {
        cin >> ch;
        arr[i] = ch;
        arr1[ch] = i;
    }

    for (int i = 0; i < states; i++)
    {
        for (int j = 0; j < symbol; j++)
        {
            for (int k = 0; k < states; k++)
            {
                cin >> mat[i][j][k];
            }
        }
    }
    cout << "    E-NFA table" << endl;
    for (int i = 0; i < states; i++)
    {
        for (int j = 0; j < symbol; j++)
        {
            for (int k = 0; k < states; k++)
            {
                cout << mat[i][j][k] << " ";
            }
            cout << "| ";
        }
        cout << endl;
    }

    for (int i = 0; i < states; i++)
    {
        ep[i] = arr[i];
        for (int j = 0; j < states; j++)
        {
            if (mat[i][symbol - 1][j] != '0' && ep[i] != to_string(mat[i][symbol - 1][j]))
            {
                ep[i] += mat[i][symbol - 1][j];
            }
        }
    }

    for (int i = 0; i < states; i++)
    {
        for (int j = 1; j < ep[i].length(); j++)
        {
            if (ep[arr1[ep[i][j]]].length() > 1)
            {
                for (int k = 1; k < ep[arr1[ep[i][j]]].length(); k++)
                {
                    if (ep[i].find(ep[arr1[ep[i][j]]][k]) == string::npos)
                    {
                        ep[i] += ep[arr1[ep[i][j]]][k];
                    }
                }
            }
        }
    }

    cout << " Epsilon closure" << endl;
    for (int i = 0; i < states; i++)
    {
        cout << arr[i] << " ---> " << ep[i] << endl;
    }

    map<int, map<int, string>> newstatematc;

    int power = pow(2, states);
    string arrofnewstates[power];
    arrofnewstates[0] = ep[0];

    map<string, int> newstates;
    newstates[ep[0]] = 1;

    vector<char> eachstate;
    int start = 0, end = 1;

    while (start < end)
    {
        for (int x = 0; x < symbol - 1; x++)
        {
            for (int i = 0; i < arrofnewstates[start].length(); i++)
            {
                if (mat[arr1[arrofnewstates[start][i]]][x][0] != '0')
                {
                    for (int j = 0; j < states; j++)
                    {
                        if (mat[arr1[arrofnewstates[start][i]]][x][j] != '0')
                        {
                            eachstate.push_back(mat[arr1[arrofnewstates[start][i]]][x][j]);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            for (int l = 0; l < eachstate.size(); l++)
            {
                for (int k = 0; k < ep[arr1[eachstate[l]]].length(); k++)
                    if (newstatematc[start][x].find(ep[arr1[eachstate[l]]][k]) == string::npos)
                    {
                        newstatematc[start][x] += ep[arr1[eachstate[l]]][k];
                    }
            }

            eachstate.clear();
            if (newstates[newstatematc[start][x]] != 1)
            {
                arrofnewstates[end] = newstatematc[start][x];
                end++;
            }

            newstates[newstatematc[start][x]] = 1;
        }
        start++;
    }
    cout << "    DFA table" << endl;
    for (int i = 0; i < newstates.size(); i++)
    {
        cout << arrofnewstates[i] << " ---> ";
        for (int j = 0; j < symbol - 1; j++)
        {
            cout << newstatematc[i][j] << " |";
        }
        cout << endl;
    }

    return 0;
}