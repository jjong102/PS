#include <iostream>
#include <string>
using namespace std;

int main()
{
    int case_;
    int score = 0;
    int plus = 1;
    cin >> case_;
    string ox_result[case_];
    for (int i = 0; i < case_; i++)
    {
        cin >> ox_result[i];
        for (int j = 0; j < ox_result[i].length(); j++)
        {
            if (ox_result[i][j] == 'O')
            {
                score += plus;
                plus++;
            }
            else if (ox_result[i][j] == 'X')
            {
                plus = 1;
            }
        }
        cout << score << endl;
        score = 0;
        plus = 1;
    }
}