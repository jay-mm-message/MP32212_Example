#include <iostream>
using namespace std;

int main()
{
    int Score[5] = { 87, 66, 90, 65, 70 };    
    //定義整數陣列 Score[5],並設定5筆成績 
    int count, Total_Score = 0;
    for ( count = 0 ; count < 5 ; count++ )   //執行 for 迴圈讀取學生成績 
    {
        cout<< "The " << count+1 << " student's score: "
            << Score[count] << endl;  
        Total_Score += Score[count];  //由陣列中讀取分數計算總合 
    }
    cout << "-------------------------" << endl;
    cout << "The total score of five students: " << Total_Score << endl;  
    //輸出成績總分 
    
    return 0;
}
