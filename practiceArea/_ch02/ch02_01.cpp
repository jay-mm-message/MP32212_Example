#include <iostream>
using namespace std;

int main()
{
    int score[] = {87, 66, 90, 65, 70};
    int score_total = 0;
    int score_count = sizeof(score) / sizeof(score[0]);

    for (size_t i = 0; i < score_count ; i++)
    {
        /* code */
        score_total = score_total + score[i];
        cout << "The " << (i + 1) << " student's score: " << score[i] << endl;
    }

    cout << "score total: " << score_total << endl;

    cout << endl;
    return 0;
}