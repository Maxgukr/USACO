/*
NAME:fangwei1
TASK:dualpal
LANG:C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

vector<int> turnBase(int b, int n)
{
    int c;
    //vector<int> s(4);
    vector<int> s;
    while (n!=0)//数制转换，结果存入数组s[m]
	{
		c=n%b;
		n=n/b;
		//m++;
        if(c>=10)
            s.push_back(c + 55);   //将余数按顺序存入数组s[m]中
        else
            s.push_back(c);
	}
    reverse(s.begin(), s.end());

    return s;
}

bool isPalindromic(vector<int>& p)
{
    //vector<int>::iterator it = p.begin();
    int n=p.size();
    if(p[0]==0 || p[n-1]==0)
        return false;
    for(int i=0;i<=floor(n/2);i++){
        if(p[i]!=p[n-1-i]){
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int n,s;
    cin>>n>>s;
    vector<int> mask(9,0);
    if(s>0 && s<10000)
    {
        //int i=1;
        int cnt=0;
        while(cnt<n)
        {
            s++;
            for(int j=2;j<=10;j++)
            {
                vector<int> p = turnBase(j,s);
                if(isPalindromic(p))
                {
                    mask[j-2] = 1;
                    if(count(mask.begin(),mask.end(),1)>=2)
                    {
                        cout<<s<<"\n";
                        cnt++;
                        //fill(mask.begin(), mask.end(),0);
                        break;
                    }
                    
                }
            } 
            fill(mask.begin(), mask.end(),0);
            //i++;
        }
    }
}
