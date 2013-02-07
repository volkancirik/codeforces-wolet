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

#define LM 2000
using namespace std;

vector<char>a;
vector<bool>toDelete(LM*100+1);
int N,T;
string username;
vector< pair<int,char> >command;
vector< vector<int> >C(26);


void readIN()
{
  cin >> N;
  cin >> username;
  a.resize(N*username.length()+1);
}
void process()
{
  int L = username.length(),index,ccount,k;
  char c;

  for(int i=0;i<N;i++)
      for(int j=0;j<L;j++)
	{
	  index = i*L + j;
	  c = username[j];
	  a[index ] = c;

	  C[c-'a'].push_back(index);
	}
  for(int i=0;i<26;i++)
    sort(C[i].begin(),C[i].end());


  cin >> T;
  vector<int>::iterator ii;
  for(int i=0;i<T;i++)
    {
      cin >> k >> c;
      ii = C[c-'a'].begin();
      toDelete[*(ii+k-1)]= true;
      C[c-'a'].erase(ii+k-1);
    }
  for(int i=0;i<N;i++)
    for(int j=0;j<L;j++)
      {
	index = i*L + j;
	if(!toDelete[index])
	  cout << a[index];
      }
}
int main()
{
  readIN();
  process();
  return 0;
}
