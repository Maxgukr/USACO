/*
ID:fangwei1
LANG:C++
TASK:gift1
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

vector<string> split(const string &str, const string &pattern)
{
    vector<string> res;
    if(str=="")
    {
        return res;
    }

    string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while(pos != strs.npos)
    {
        string tmp = strs.substr(0,pos);
        res.push_back(tmp);

        strs = strs.substr(pos+1,strs.size());
        pos = strs.find(pattern);
    }

    return res;
}

int main()
{
    map<string,int> money;
    vector<string> name;
    queue<string> tmp;
    stringstream ss;

    ifstream file;
    file.open("gift1.in");
    string line;
    int cnt = 0;//file row count
    int participantsNum = 0;
    //int money,recieveNum;
    if(file.fail())
    {
        return 0;//file open error
    }
    else
    {
        while(!file.eof())//each row read into value line
        {
            file>>line;//space and \n
            //getline(file, line);
            if(file.fail())
                break;

            cnt++;//file count pointer ++
            if(cnt==1)
            {
                //participantsNum = line[0] - '0';//char to int,refer ASSIC
                ss<<line;
                ss>>participantsNum; //string to int
                ss.clear();
            }
            else if(cnt>=2 && cnt<=participantsNum+1)
            {
                money[line] = 0;//initial each gift of every participant 0
                name.push_back(line);
            }
            else
            {
                tmp.push(line);
            }
        }
    }
    file.close();

    string name_tmp;
    int money_tmp = 0;
    int div_n = 0;
    for(int i=0;i<participantsNum;i++)
    {
        name_tmp = tmp.front();
        tmp.pop();

        ss<<tmp.front();
        ss>>money_tmp;
        ss.clear();
        tmp.pop();

        ss<<tmp.front();
        ss>>div_n;
        ss.clear();
        tmp.pop();

        //self money decrease
        if(div_n!=0)
        {
            money[name_tmp] = money[name_tmp] - money_tmp + money_tmp%div_n;
            //friends money increase
            cnt=div_n;
            while(cnt!=0)
            {
                money[tmp.front()] += money_tmp/div_n;
                tmp.pop();
                cnt--;
            }
        }
        else//don't give
        {
            continue;//if you have money, you can't save
        }
    }
    
    ofstream filew;
    string m;
    filew.open("gift1.out",ios::out);
    for(int i=0;i<name.size();i++)
    {
        ss<<money[name[i]];
        ss>>m;
        ss.clear();
        line = name[i] + " " + m + "\n";
        filew<<line;
    }
    
    return 0;
}

