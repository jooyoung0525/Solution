## 문제 링크

       https://www.acmicpc.net/problem/4948

-------------------------------------------------------------------------------------------------------------------------

### 접근방법 ( 소수구하기 >> '에라토스테네스의 체' 이용 )



1. 에라토스테네스의 체를 이용해 소수를 배열에 체크

2. 해당범위에 소수가 몇개있는지 체크

--------------------------------------------------------------------------------------------------------------------------

```c
#include<iostream>
#include<cmath>

using namespace std;

bool NNum[250000];

void getSosu()
{
	fill_n(NNum, 250000, true); //c++에서 0이아닌 다른값으로 초기화하는 STL

	for (int i = 2; i <= sqrt((int)250000); i++) //원하는 max값의 제곱근까지만 배수를 지우면 됨! 
	{
		if (NNum[i] == false)continue;
		for (int j = i + i; j <= 250000; j += i)
		{
			if (NNum[j] == false)continue;
			NNum[j] = false;
		}
	}

	NNum[0] = false;
}

int main()
{
	getSosu();

	int n;
	while (1)
	{
		int cnt = 0;

		cin >> n;
		if (n == 0)break;

		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (NNum[i] == true) cnt++;
		}

		cout << cnt << "\n";              //"\n"때문에 계속틀림ㅠㅠ
	}
	 
	return 0;
}
```
