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
#define NM 20000+1

using namespace std;
int N;
char inp[1<<20];
list<char>a;


int main()
{
  int i;
  char c;
  list<char>::iterator it;

  int N;
  cin.getline(inp,1<<20);

  for(i=0;;i++)
    {
      c = inp[i];
      if(c < 'a' || c>'z')break;
      it = a.end();
      --it;
      if(*it == c)
	  a.erase(it);
      else
	a.push_back(c);
    }
  for(it = a.begin();it!=a.end();++it)
    cout << *it;
}
