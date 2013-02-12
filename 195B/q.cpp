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

int N,M;
queue<int>q;
vector<int>ar;
void copyQ()
{
	int i = 0;
	ar.resize(M);
	while(!q.empty())
	{
		ar[i] = q.front();
		//cout << q.front() << " ";
		q.pop();	
		i++;	
	}
}
void READ()
{
	cin >> N >> M;
	int m = M/2,i;
	if(M%2)q.push(M/2 + 1);

	for(i=m;i>=1;i--)
	{
		q.push(i);
		q.push(M+1-i);
	}
	copyQ();
	int k = N/M;
	for(i=0;i<k;i++)
		for(int j=0;j<M;j++)cout << ar[j] << endl;
	k = N%M;
       for(i=0;i<k;i++)
	cout << ar[i] << endl;
}
int main()
{
	READ();
	return 0;
}