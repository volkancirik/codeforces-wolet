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
vector<int>a;
int N;

int main()
{
  int i;

  cin >> N;
  a.resize(N+1);
  a[0] =1;
  for(i=1;i<=N;i++)
    cin >> a[i];

  sort(a.begin(),a.end());

  for(i=0;i<N-1;i++)
    cout << a[i] << " ";
  if(a[i+1] == 1)
    cout << 2;
  else
    cout << a[i];

  return 0;
}
