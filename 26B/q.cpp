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

#define NM 10000
using namespace std;

int main()
{
  int cleft = 0,res;
  char c;

  scanf("%c",&c);
  while(c==')' || c=='(')
    {
      if(c == '(')
	cleft++;
      else if(cleft >0)
	{
	  res++;
	  cleft --;
	}
      scanf("%c",&c);
    }
  cout << 2*res;
}
