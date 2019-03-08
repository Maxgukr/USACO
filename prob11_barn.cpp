/*
ID: fangwei1
PROG: barn1
LANG: C++
*/

#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;


/*
pair<vector<int>::iterator, vector<int>::iterator > findMaxGap(vector<int>::iterator begin, vector<int>::iterator end)//找到序列ａ中相邻元素差值最大的位置, 返回
{
    int sub=0;
    //int first=0, second=0;
    //vector<vector<int> > b;
    vector<int>::iterator i=begin, first,second;
    for(;i!=end;i++)
    {
        if(sub<*(i+1)-*(i) && sub>1)
        {
            sub = *(i+1)-*(i);
            first = i;
            second = (i+1);
        }   
    }

    if(first - begin > end - second) //返回较长的一个序列
        return {begin,first};
    else
        return {second,end};

}

vector<int> stalls;

int main()
{
    ifstream in("barn1.in");
    ofstream outfile("barn1.out");

    int M=0, S=0, C=0;

    in>>M>>S>>C;
    int tmp=0;
   
    while(in>>tmp)
    {
        stalls.push_back(tmp); //第ｉ头牛在的牛棚。
    }

    sort(stalls.begin(), stalls.end());

    int sub=0,sum=0;
    if(M>C) //挡板的数量比牛多，则每个牛棚放一个挡板
    {
        sum = stalls.size();
    }
    else //将Ｃ个数据分为Ｍ段
    {

        while(M!=1 && stalls.size()>1)
        {
            vector<int>::iterator i=stalls.begin(), first,second;
            for(;i<stalls.end()-1;i++)
            {
                if(sub<*(i+1)-*(i))
                {
                    sub = *(i+1)-*(i);
                    first = i;
                    second = (i+1);
                }   
            }
            if(sub > 1)
            {
                if(first - stalls.begin() > stalls.end() - second)
                { //返回较长的一个序列
                    sum += stalls.back() - *second + 1;
                    stalls.erase(second, stalls.end());
                }
                else
                {
                    sum += *first - stalls.front() + 1;
                    stalls.erase(stalls.begin(), first+1);
                }
                sub = 0;
            }
            M--;
        }
        sum += stalls.back() - stalls.front() + 1;
        
    }
    

    

    outfile<<sum<<"\n";





}
*/

int M,S,C,sum,stall[201],dif[201];
int main()
{
    ifstream cin("barn1.in");
    ofstream cout("barn1.out");
    int k;
    cin >> M >> S >> C;
    for(int i=0;i!=C;i++)
    {
        cin>> k;
        stall[i]=k;
    }
    if(M>C)
        M=C;
    sort(stall,stall+C);
    sum=stall[C-1]-stall[0]+1;
    for(int i=0;i!=C-1;i++)
        dif[i]=stall[i+1]-stall[i]-1;
    sort(dif,dif+C-1);
    
    for(int i=C-2;i!=C-M-1;i--)
        sum=sum-dif[i];
    cout << sum <<endl; 
    //system("pause");
    return 0;
}