class Solution
{
    public:
        int cal(string &date, vector<int> &pre)
        {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3));
            // cout<<date<<" "<<day<<" "<<month<<endl;
            // cout<<pre[month-1]+day<<endl;
            return pre[month-1] + day;
        }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        vector<int> days = { 31,
            28,
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31
        };
        vector<int> pre(13, 0);
        for (int i = 0; i < 12; i++)
        {
            pre[i + 1] = pre[i] + days[i];
        }
       
        int Astart = cal(arriveAlice, pre);
        int Aend = cal(leaveAlice, pre);
        int Bstart = cal(arriveBob, pre);
        int Bend = cal(leaveBob, pre);
        // cout<<Astart<<" "<<Aend<<endl;
        // cout<<Bstart<<" "<<Bend<<endl;
        if (Aend < Bstart || Astart > Bend)
            return 0;
        int mx = max(Astart, Bstart);
        int mn = min(Bend, Aend);
        return mn - mx+1;
    }
};