#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;
int N;

string result(int degree)
{
  if(360%(180-degree) == 0)
    return "YES";
  return "NO";
}
int main()
{
  int i,degree;
  cin >> N;
  for(i=0;i<N;i++)
    {
      cin >> degree;
      cout << result(degree) << endl;
    }
}
