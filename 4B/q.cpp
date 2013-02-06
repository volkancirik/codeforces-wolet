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
#define NM 30+1

using namespace std;
int D,sumTime;

set<pair<int,int> >minmax;
vector < vector<int> >days;
vector <bool>visited(NM);

int findMin()
{
  int i,mmin = 241,mindex=-1;
  for(i=0;i<D;i++)
    if(mmin>days[i][0] && days[i][0]>0  && !visited[i])
      {
	mindex = i;
	mmin = days[i][0];
      }
  return mindex;
}
int findMax()
{
  int i,mmin =-1,mindex=-1;
  for(i=0;i<D;i++)
    if(mmin<days[i][1] && days[i][1]>0  && !visited[i])
      {
	mindex = i;
	mmin = days[i][1];
      }
  return mindex;
}

int main()
{
  int tmin,tmax,index,hours;
  string s;
  cin >> D >> sumTime;
  days.resize(D);
  for(int i=0;i<D;i++)
    {
      days[i].resize(3);
      cin >> tmin >> tmax;
      days[i][0] = tmin;
      days[i][1] = tmax;
      days[i][2] = 0;
    }
  while(sumTime > 0)
    {
      index = findMin();

      if(index == -1)
	{
	  index = findMax();
	  if(index == -1)break;


	  hours =days[index][1];

	  if(hours>sumTime)hours = sumTime;
	  days[index][1] -= hours;
	  days[index][2] += hours;

	  sumTime -=hours;
	  visited[index] = true;
	}
      else
	{
	  hours =days[index][0];

	  if(hours>sumTime)hours = sumTime;

	  days[index][0] -= hours;
	  days[index][1] -= hours;
	  days[index][2] += hours;
	  sumTime -= hours;
	}
    }
  for(int i=0;i<D;i++)
    if(days[i][0]>0)
      {
	cout << "NO";
	return 0;
      }
  if(sumTime>0)
    {
      cout << "NO";
      return 0;
    }
  cout << "YES" << endl;
  for(int i=0;i<D;i++)
    cout << days[i][2] << " ";
}
