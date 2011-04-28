/*   @JUDGE_ID:   35114NR   10050   C++   "Hartals"  */

#include <iostream>

int *day = NULL;
int *parties = NULL;
int numOfDays;
int numOfParties;

void clearDays(){
    for (int i = 0;i<=numOfDays;i++)
        day[i]=0;
}

void createDays(){
    day = new int[numOfDays+1];
    clearDays();
}

void printDays(){
    cout << numOfDays << endl;
    for (int i = 1;i<=numOfDays;i++)
        cout << day[i] << " ";
    cout << endl;
}

void clearParties(){
    for (int i = 0;i<numOfParties;i++)
        parties[i]=0;
}

void createParties(){
    parties = new int[numOfParties];
    clearParties();
}

void printParties(){
    cout << numOfParties << endl;
    for (int i = 0;i<numOfParties;i++)
        cout << parties[i] << " ";
    cout << endl;
}

void solve(){
    int workdaysMissed = 0;
    //get hartels
    for(int i = 0;i<numOfParties;i++)
    {
        for(int j = parties[i];j<=numOfDays;j+=parties[i])
        {
            if (j%7 == 6 || j%7 == 0) continue;//skip friday and saturday
            day[j]++;
        }
    }
    //count days missed
    for(int i = 1;i<=numOfDays;i++)
        if (day[i]>0) workdaysMissed++;
    //print answer
    cout << workdaysMissed << endl;
}

int main()
{
    int runs;
    //input runs
    cin >> runs;
    //runs
    for (int i = 0;i<runs;i++)
    {
        //input variables
        cin >> numOfDays
            >> numOfParties;
        //create days
        createDays();
        //create parties
        createParties();
        //input parties
        for (int j = 0;j<numOfParties;j++)
            cin >> parties[j];
        //solve
        solve();
        //clean up pointers
        delete day;
        delete parties;
    }


    //system("PAUSE");
    return 0;
}
