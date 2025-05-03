#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string word;
    int sequence = 1;
    int alphabet[26];
    fill(alphabet, alphabet + 26, -1);
    cin >> word;
    for (int i : word)
    {
        alphabet[i - 97] += sequence;
        if (alphabet[i - 97] >= sequence)
        {
            alphabet[i - 97] -= sequence;
        }
        sequence++;
    }

    for (int j = 0; j < 26; j++)
    {
        cout << alphabet[j] << ' ';
    }
}