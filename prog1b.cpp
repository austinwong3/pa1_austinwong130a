#include <iostream>
#include "htableb.h"
#include <cmath>
#include <fstream>

using namespace std;


int main()
{
    int size = 0;
    cin >> size;

    ifstream myFile("primes1.txt");
    
    if (! myFile)
   	{
     	cerr << "primes1.txt not found\n";
     	return -1;
   	}
    
    int b =log2(size);

    int pnum;
    while(myFile >> pnum)
    {
        if (pnum>size)
        {
            size = pnum;
            break;

        }
    }
    myFile.close();


    htable t(size,b);

    string next;

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