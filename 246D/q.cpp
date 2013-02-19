#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>

#define NM 100000+1
using namespace std;

int N,M;
vector<int>COLOR;
vector< set<int> >ADJ;

map< int, set<int> >COUNT;

int main()
{
  int i,x,y;

  cin >> N >> M;
  COLOR.resize(N+1);
  ADJ.resize(N+1);

  for(i=1;i<=N;i++)
    {
      cin >> COLOR[i];
      COUNT[COLOR[i]].insert(COLOR[i]);
    }
  for(i=0;i<M;i++)
    {
      cin >> x >> y;
      ADJ[x].insert(y);
      ADJ[y].insert(x);
    }
  for(i=1;i<=N;i++)
    for(set<int>::iterator jj =ADJ[i].begin();jj!=ADJ[i].end();++jj)
    {
      x = i;
      y = (*jj);

      COUNT[COLOR[x]].insert(COLOR[y]);
      COUNT[COLOR[y]].insert(COLOR[x]);
    }

  int maxc,maxv = 0;
  for(map< int, set<int> >::iterator ii = COUNT.begin();ii!=COUNT.end();++ii)
    {
      if(((*ii).second.size())>maxv)
	{
	  maxv = (*ii).second.size();
	  maxc = (*ii).first;
	}
    }
  cout << maxc;
}

