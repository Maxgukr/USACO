/*
ID:fangwei1
TASK:combo
LANG:C++
*/

#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int ans=0;
int farmer[3], master[3];

bool ok(int a, int b) {
    if(abs(a-b) <= 2 || abs(a-b) >= N-2) return true;
    return false;
}
int main()
{
    ifstream infile("combo.in");
    ofstream outfile("combo.out");
    
    infile>>N>>farmer[0]>>farmer[1]>>farmer[2]>>master[0]>>master[1]>>master[2];
    vector<vector<vector<int> > > mask(101, vector<vector<int> >(101, vector<int>(101,0)));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=N;k++)
            {
                if(!mask[i][j][k])
                {
                    if((ok(i, farmer[0]) && ok(j, farmer[1]) && ok(k, farmer[2]))
                        || (ok(i, master[0]) && ok(j, master[1]) && ok(k, master[2]))) {
                            ans++;
                            mask[i][j][k] = 1;
                        }
                }
            }
        }
    }
    outfile<<ans<<"\n";
    return 0;
}