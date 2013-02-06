#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#define NM 10000+2

using namespace std;

vector<int>a;
int N;
int main()
{
  int i,j;
  cin >> N;
  a.resize(N+1);
  for(i=0;i<N;i++)
    cin >> a[i];
  for(i=N-1;i>0;i--)
    if(a[i]<a[i-1])break;
  cout << i;
  return 0;
}
