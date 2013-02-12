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
string S,P;
int N,M;
set<int>PROB;

vector<int>Count(26);
void READ()
{
  cin >> S;
  cin >> P;
  N = S.length();
  M = P.length();
  for(int i=0;i<M;i++)
    Count[P[i]-'a']++;
}
void process()
{
  int i,j,k,n = N-M,res = 0;
  int state = 0;

  vector<int>counts(Count.begin(),Count.end());
  for(j=0;j<M;j++)
    {
      k = j;
      if(S[k] != '?')
	counts[S[k]-'a']--;
    }
  for(i=0;i<26;i++)
    if(counts[i] < 0)PROB.insert(i);

  if(PROB.size()>0)res = 0;
    else
      res = 1;

  //  cout << res << " " << PROB.size() << endl;
  for(i=1;i<=n;i++)
    {
      if(S[i-1] != '?')
	counts[S[i-1]-'a']++;
      if(S[i-1] != '?' && counts[S[i-1]-'a'] == 0)
	  PROB.erase(S[i-1]-'a');


      if(S[i+M-1] != '?')
	counts[S[i+M-1]-'a']--;
      if(S[i+M-1] != '?' && counts[S[i+M-1]-'a'] < 0)
	  PROB.insert(S[i+M-1]-'a');

      //  cout << counts[S[i-1]-'a'] << " " << counts[S[i+M-1]-'a'] << endl;
      //cout << PROB.size() << " >" << S[i-1] << " " << S[i+M-1] << "< " << endl << endl;
      if(PROB.size() == 0)
	res++;
    }
  cout << res;
}
int main()
{
  READ();
  if(M > N)cout << "0";
  else
    process();
}
