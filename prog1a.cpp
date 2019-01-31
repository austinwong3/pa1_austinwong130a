#include <iostream>
#include "htable.h"

using namespace std;


int main()
{
    int size = 0;
    cin >> size;

    htable t(size);
    
    string line;
    while(cin>>line)
    {
        string ip;
        cin >> ip;
        if(line.compare("insert")==0)
        {
            t.insert(ip);
        }
        else if (line.compare("delete")==0)
        {
            t.remove(ip);
        }
        else if (line.compare("lookup")==0)
        {
            cout<<t.lookup(ip)<<endl;
        }
        else if(line.compare("stat")==0)
        {
            t.stat();
        }
    }

    return 0;
}