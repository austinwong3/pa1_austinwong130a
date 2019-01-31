#ifndef _TABLE_H_
#define _TABLE_H_

#include <string>
#include <vector>
#include <list>

using namespace std;
class htable
{
    public:
        htable(int size);
        int hash(string ip);
        void insert(string ip);
        void remove(string ip);
        string lookup(string key);
        void stat();

    private:
        vector <int> coeff;
        std::vector<std::list<std::string> > table;
        int size;

        int inserted;
        int deleted;
        int single;
        int empty;
        int maxInd;
        int max;

        



};
#endif