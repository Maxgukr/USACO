/*
ID: fangwei1
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    return a.first<b.first;
}


int main()
{
    int M,N;
    ifstream in("milk.in");
    ofstream out("milk.out");
    in>>N>>M; // N总共需要的牛奶，M奶农数量
    vector<pair<int, int>> farmer;
    int tmp1,tmp2;
    while(in>>tmp1>>tmp2)
    {
        farmer.push_back(make_pair(tmp1,tmp2));
    }
    sort(farmer.begin(),farmer.end(),cmp); //按照单价从低到高排序
    int current_milk = 0;
    int cost = 0;
    for(unsigned i=0;i<farmer.size();i++)
    {
        current_milk += farmer[i].second;
        if(current_milk < N)
        {
            cost += farmer[i].first * farmer[i].second;
        }
        else
        {
            cost += farmer[i].first * (N-(current_milk -farmer[i].second));
            break;
        }
    }
    out<<cost<<"\n";
    return 0;
}