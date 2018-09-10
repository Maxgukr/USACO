/*
ID:fangwei1
LANG:C++
TASK:beads
*/

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string beads;
    string line;
    stringstream ss;
    vector<string> f;
    int len = 0;
    ifstream file("beads.in");
    if(!file.fail())
    {
        while(!file.eof())
        {
            if(file.fail())
                break;
            getline(file,line);
            f.push_back(line);
        }
    }
    file.close();

    ss<<f[0];
    ss>>len;
    ss.clear();
    ss<<f[1];
    ss>>beads;
    ss.clear();

    //f.clear();
    int cnt_left = 0;
    int cnt_right = 0;
    int cnt = 0;
    for(int i=0;i<beads.size();i++)
    {
        f[0] = beads.substr(0,i);
        f[1] = beads.substr(i,beads.size());
        line = f[1]+f[0];
        for(int j=0;j<line.size();j++)
        {
            if(line[j]==line[0] | line[j]=='w')
            {
                cnt_left++;
            }
            else
            {
                break;
            }
        }
        for(int k=line.size()-1;k>=cnt_left;k--)
        {
            if(line[k]==line[len-1] | line[k]=='w')
            {
                cnt_right++;
            }
            else
            {
                break;
            }
        }
        if(cnt < cnt_left + cnt_right)
            cnt = cnt_left + cnt_right;

        cnt_left = 0;
        cnt_right = 0;
    }
    ofstream filew("beads.out");
    filew<<cnt<<"\n";

    return 0;
}