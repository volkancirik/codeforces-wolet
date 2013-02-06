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
#define NM 1000

using namespace std;
int N,M;
vector<int>maxh;
vector<int>minh;

void debug(int n,int m)
{
  int i,j;
  for(i=0;i<2;i++)
    cout << maxh[i] << " ";
  cout << endl;
  for(i=0;i<2;++i)
    cout << minh[i] << " ";
  cout << endl;

}
int main()
{
  int i,j;

  cin >> N >> M;
  maxh.resize(M);
  minh.resize(M);

  for(i=0;i<M;i++)
    {
      cin >> maxh[i];
      minh[i] = NM - maxh[i];
    }
  make_heap(maxh.begin(),maxh.end());
  make_heap(minh.begin(),minh.end());

  //  debug(M,M);
  int maxv =0, minv=0,v;
  vector<int>::iterator ii,jj;
  for(i=0;i<N;i++)
    {
     

      v = maxh.front();

      //cout << "MAXH " << v <<endl;

      ii = maxh.begin();
      jj = maxh.end();

      pop_heap(ii,jj);
      maxh.pop_back();

      maxv += v;
      v--;

      maxh.push_back(v);
      push_heap(ii,jj);

      v = minh.front();
      //      cout << "MINH " << (NM-v) <<endl << "__________" << endl;

      ii = minh.begin();
      jj = minh.end();

      pop_heap(ii,jj);
      minh.pop_back();

      minv += (NM - v);
      v++;
      if(NM-v <=0)v = 0;

      minh.push_back(v);
      push_heap(ii,jj); 

    }
  cout << maxv << " " << minv;
}

