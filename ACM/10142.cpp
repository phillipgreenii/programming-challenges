/*   @JUDGE_ID:   35114NR   10142   C++   "Australian Voting"  */

#include <iostream>
#include <string>
#include <queue>
#include <vector>

int numberOfCanidates;
string *canidates;
int *count;
vector< queue<int> > voters;

void clearCount(){
    for (int i = 0;i<numberOfCanidates;i++)
        if (count[i]>0) count[i]=0;
}

void createCanidateList(){
    canidates = new string[numberOfCanidates];
    count = new int[numberOfCanidates];
    for (int i = 0;i<numberOfCanidates;i++)
    {
        count[i]=0;
        cin >> canidates[i];
    }
}

void getVoters(){
    int tmp;
    queue<int> newVoter;
    cin.get();
    while(cin.peek() != '\n')
    {
        newVoter = new queue<int>;
        for (int i = 0;i<numberOfCanidates;i++)
        {
            cin >> tmp;
            newVoter.push(tmp);
        }
        voters.push_back(newVoter);
        cin.get();
    }

}

void solve(){
    clearCount();
    queue<int> voter;
    int max=0,min=2000,total=0;
    //count votes
    for (int i = 0;i<voters.size();i++)
    {
        voter = voters[i];
        //get next good eligiable vote
        while(!voter.empty() && count[voter.front()]<0)
            voter.pop();
        //count vote
        if (!voter.empty())
            count[voter.pop()]++;
    }
    //count total votes and get max and min
    for (int i = 0;i<numberOfCanidates;i++)
    {
        if(count[i]>=0)
        {
            total += count[i];
            max = (count[i]>max?count[i]:max);
            min = (count[i]<min?count[i]:min);
        }
    }

    //tie
    if (max == min) return;
    //>50% winner found
    if (max > total/2)
    {
        for (int i = 0;i<numberOfCanidates;i++)
            if (count[i]!=max) count[i]=-1;
            return;
    }
    //filter out losers
    for (int i = 0;i<numberOfCanidates;i++)
        if (count[i]==min) count[i]=-1;
    //run again for next count
    return solve();

}

void displayWinner(){
    for (int i = 0;i<numberOfCanidates;i++)
        if (count[i]>0) cout << canidates[i] << endl;
    cout << endl;
}

void cleanup(){
    queue<int> tmpVoter;
    while (!voters.empty())
    {
        tmpVoter=voters.pop_back();
        while(!tmpVoter.empty())
            tmpVoter.pop();
        delete tmpVoter;
    }
    delete canidates;
    delete count;
}

int main()
{
    cin >> numberOfCanidates;
    for (int i = 0;i<numberOfCanidates;i++)
    {
        createCanidateList();
        getVoters();
        solve();
        displayWinner();
        cleanup();
    }

    //system("PAUSE");
    return 0;
}
