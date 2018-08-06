#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //string file1=;
    ifstream file;
    file.open("./ride.in");//read file
    vector<string> name;
    string str;
    
    while(!file.eof())
    {
        file>>str;
        if(file.fail())
            break;
        name.push_back(str);
    }
    file.close();

    int prod[2] = {1,1};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<name[i].size();j++)
        {
            prod[i] *= name[i][j] - 64;
        }
    }
    ofstream filew;
    filew.open("./ride.out",ios::out);
    if(prod[0]%47 == prod[1]%47)
    {
        filew<<"GO";
    }
    else
    {
        filew<<"STAY";
    }
    filew.close();
    return 0;
}