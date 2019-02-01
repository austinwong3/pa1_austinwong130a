#ifndef _TABLE_H_
#define _TABLE_H_

#include <string>
#include <vector>
#include <list>

using namespace std;
class htable
{
    public:
        htable(int size, int b);
        int hash(string address);
        void insert(string ip);
        void remove(string ip);
        string lookup(string key);
        void stat();
        string toBin(string num);
        string toDec(string num);

    private:
        vector <int> coeff;
        std::vector<std::list<std::string> > table;
        int size;
        int b;

        int inserted;
        int deleted;
        int single;
        int empty;
        int maxInd;
        int max;

        



};
#endif