#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

int isKeyword(char b[])
{
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};
    int i, flag = 0;
    for (i = 0; i < 32; i++)
    {
        if (strcmp(keywords[i], b) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    char ch, b[15];
    char opr[] = "+-*/%=";
    ifstream fin("program.txt");
    int i, j, key, id, op = 0;
    if (!fin.is_open())
    {
        cout << "error while opening the file\n";
        exit(0);
    }
    while (!fin.eof())
    {
        ch = fin.get();

        for (i = 0; i < 6; i++)
        {
            if (ch == opr[i])
            {
                cout << ch << " is operator\n";
                op++;
            }
        }

        if (isalnum(ch))
        {
            b[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0))
        {
            b[j] = '\0';
            j = 0;

            if (isKeyword(b) == 1)
            {
                cout << b << " is keyword\n";
                key++;
            }
            else
            {
                cout << b << " is indentifier\n";
                id++;
            }
        }
    }
    fin.close();
    cout << "Keywords : " << key << endl;
    cout << "Identifiers : " << id << endl;
    cout << "Operators : " << op << endl;
    return 0;
}
