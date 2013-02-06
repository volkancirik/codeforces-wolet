#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <list>
#define NM 10000+1

using namespace std;
int N;
map<string,int>reg;

int main()
{
  string s;
  cin >> N;
  for(int i=0;i<N;i++)
    {
      cin >> s;
      if(reg[s] == 0)
	{
	  cout << "OK" << endl;
	  reg[s] = 1;
	}
      else
	{
	  cout << s << reg[s]<<endl;
	  reg[s] = reg[s] + 1;
	}
    }
}
