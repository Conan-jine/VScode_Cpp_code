#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

string oldCalendar[20]=
{
    "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
    "yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu",
    "uayet"
};

string newCalendar[21]=
{
    "imix","ik","akbal","kan","chicchan",
    "cimi","manik","lamat","muluk","ok",
    "chuen","eb","ben","ix","mem",
    "cib","caban","eznab","canac","ahau"
};

int newCalendarNum[14];

int main()
{
    int n,day,year;
    string month;
    int realDay,realMonth,realYear,sumDay;
    for(int i=0;i<13;i++)   newCalendarNum[i]=i+1;
    cin>>n;
    cout<<n<<endl;
    while(n--)
    {   // day只会读取到数字，英文句号不会读入，故读入两次month把句号覆盖
        sumDay=0;
        cin>>day>>month>>month>>year;
        realDay=day;
        for(int i=0;i<19;i++)   if(oldCalendar[i]==month)   realMonth=i+1;
        realYear=year;
        sumDay+=realDay+(realMonth-1)*20+realYear*365;
        cout<<sumDay%(13*20)%13+1<<' '<<newCalendar[sumDay%(13*20)%20]<<' '<<sumDay/(13*20)<<endl;
    }
    return 0;
}