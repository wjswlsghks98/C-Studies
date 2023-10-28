#include <iostream>
using namespace std;

void Counter()
{
    static int cnt; // 함수 내부에서의 static 선언은 거의 전역변수랑 동일하게 만든다
    //한번만 초기화되고, 지역변수와는 달리, 함수를 빠져나가도 소멸되지 않는다.
    cnt ++;
    cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
    for (int i=0;i<10;i++)
    {
        Counter();
    }
    return 0;
}