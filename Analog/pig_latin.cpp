#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int elen=0;
    char c,e;
    string str;
    string::iterator it,nit;
    while(getline(cin,str))
    {
        str+='*';
        for(it=str.begin();it!=str.end();it++)
        {
            elen=0;
            if(*it>='a' && *it<='z' || *it>='A' && *it<='Z')
            {
                nit=it;
                while(*nit>='a' && *nit<='z' || *nit>='A' && *nit<='Z')
                {
                    nit++;
                    elen++;
                }
                if(*it=='a' || *it=='e' || *it=='i' || *it=='o' || *it=='u' ||
                *it=='A' || *it=='E' || *it=='I' || *it=='O' || *it=='U')
                {
                    str.insert(nit,'a');
                    str.insert(nit+1,'y');
                    elen+=2;
                }
                else
                {
                    str.insert(nit,*it);
                    str.erase(it);
                    str.insert(nit,'a');
                    str.insert(nit+1,'y');
                    elen+=2;
                }
            }
            it+=elen;
        }
        str.erase(str.end()-1);
        cout<<str<<endl;
    }
}