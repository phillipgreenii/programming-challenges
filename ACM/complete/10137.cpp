/*   @JUDGE_ID:   35114NR   10137   C++   "The Trip"  */

#include <iostream>
#include <iomanip>
#include <cmath>
#define MAXSTUDENTS 1000
#define rnd(x) floor(((x) * 100)+.5)/100
//#define rnd(x) x*100

double students[MAXSTUDENTS];

int main()
{
    int numOfPeople;
    double total,average,tmp,posTot,negTot;
    //set float display to two places after the zero
    cout << setiosflags(ios::fixed | ios::showpoint)<< setprecision(2);
    while(cin >> numOfPeople)
    {
        //break when numOfPeople equals 0
        if (numOfPeople == 0) break;
        //clear total
        total = 0;
        //get student amounts
        for (int i = 0;i<numOfPeople;i++)
        {
            //input student amount
            cin >> students[i];
            //running total
            total += students[i];
        }
        //get average
        average = (double)total/(double)numOfPeople;
        //clear variables
        posTot = 0;
        negTot = 0;
        for (int i = 0;i<numOfPeople;i++)
        {
            //get difference from average
            if (students[i] > average)
                posTot += rnd(students[i] - average);
            else
                negTot += rnd(average - students[i]);
        }
        //printout minimum
        cout << "$" << (posTot<negTot?posTot:negTot) << endl;
    }

    return 0;
}
