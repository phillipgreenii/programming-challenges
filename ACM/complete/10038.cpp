/*   @JUDGE_ID:   35114NR   10038   C++   "Jolly Jumpers"  */

#include <iostream>
#include <algo.h>
#include <vector>


int main()
{
    vector<int> diffs;
    int n,x1,x2;
    bool jolly;

    while(cin >> n)
    {
        jolly = true;
        //get numbers
        cin >> x1;
        for (int i = 0; i< n-1; i++)
        {
            cin >> x2;
            diffs.push_back(abs(x1-x2));
            x1 = x2;
        }
        //sort
        sort(diffs.begin(),diffs.end());
        //check for all possible values
        for(int i = 1;i<n && jolly;i++)
            jolly = (diffs[i-1]==i);
        //clear vector
        while(!diffs.empty())
            diffs.pop_back();
        if (jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }


    //system("PAUSE");
    return 0;
}
