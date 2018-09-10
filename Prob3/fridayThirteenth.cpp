/*
ID:fangwei1
LANG:C++
TASK:friday
*/

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

bool isLeap(int n)
{
    bool leap = false;
    if((n%4 == 0 && n%100 != 0) || n%400 == 0)
        leap = true;
    return leap;
}

int main()
{
    ifstream file;
    file.open("friday.in");
    string line;
    stringstream ss;
    int N;
    while(getline(file,line))
    {
        ss<<line;
        ss>>N;//read period
        ss.clear();
    }

    //start time 1900.1.1 monday
    int total_days = 0;
    int total = 0;
    map<string,int> freq;//monday to sunday present frequency during period
    map<string,int> mon;

    //initial
    string week[7] = {"sunday","monday","tuesday","wendesday","thusday","friday","saturday"};
    string month1[12] = {"jan","feb","mar","apr","may","jun","juy","aug","sep","oct","nev","dec"};
    int month2[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
    //12 months
    for(int i=0;i<7;i++)
    {
        freq[week[i]] = 0;
    }
    for(int j=0;j<12;j++)
    {
        mon[month1[j]] = month2[j];
    }

    for(int n=1900;n<1900+N;n++)
    {
        //is leap or not
        if(isLeap(n))
            mon[month1[1]] = 29;
        else
            mon[month1[1]] = 28;

        // for each month in n'th year
        for(int k=0;k<12;k++)
        {
            total = total_days + 13;
            freq[week[total%7]]++;
            total_days += mon[month1[k]];
        }
    }

    ofstream filew("friday.out",ios::out);
    string res[7];

    ss<<freq["saturday"];
    ss>>res[0];
    ss.clear();
    //filew<<res[0]+" ";

    ss<<freq["sunday"];
    ss>>res[1];
    ss.clear();
    //filew<<res[1]+" ";

    for(int i=0;i<5;i++)
    {
        ss<<freq[week[i+1]];
        ss>>res[i+2];
        ss.clear();
        //filew<<res[i+2]+" ";
    }

    for(int i=0;i<7;i++)
    {
        if(i<6)
            filew<<res[i]+" ";
        else
            filew<<res[i]+"\n";
    }
    return 0;
}