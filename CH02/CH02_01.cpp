#include <iostream>
using namespace std;

int main()
{
    int Score[5] = { 87, 66, 90, 65, 70 };    
    //�w�q��ư}�C Score[5],�ó]�w5�����Z 
    int count, Total_Score = 0;
    for ( count = 0 ; count < 5 ; count++ )   //���� for �j��Ū���ǥͦ��Z 
    {
        cout<< "The " << count+1 << " student's score: "
            << Score[count] << endl;  
        Total_Score += Score[count];  //�Ѱ}�C��Ū�����ƭp���`�X 
    }
    cout << "-------------------------" << endl;
    cout << "The total score of five students: " << Total_Score << endl;  
    //��X���Z�`�� 
    
    return 0;
}
