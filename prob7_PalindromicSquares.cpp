/*
NAME:fangwei1
TASK:palsquare
LANG:C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>

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
    for(int i=0;i<=floor(n/2);i++){
        if(p[i]!=p[n-1-i]){
            return false;
        }
    }

    return true;
}

int main()
{
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int b;
    cin>>b;
    for(int i=1;i<=300;i++){
        vector<int> p = turnBase(b,i*i);
        vector<int> n = turnBase(b,i);
        if(isPalindromic(p)){
            for(unsigned i=0;i<n.size();i++){
                if(n[i]>=10)
                    cout<<(char)(n[i]);
                else
                    cout<<n[i];
            }
            cout<<" ";
            for(unsigned i=0;i<p.size();i++){
                if(p[i]>=10)
                    cout<<(char)(p[i]);
                else
                    cout<<p[i];
            }
            cout<<"\n";
        }

    }
    return 0;
}