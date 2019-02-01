#include <iostream>
#include "htable.h"
#include <string>
#include <vector>
#include <list>

using namespace std;

htable::htable(int size)
{
    this->size = 257;
    table.resize(this->size);
    this->inserted = 0;
    this->deleted = 0;
    this->empty = this->size;
    this->single = 0;
    this->max = 0;
    this->maxInd = 0;
    //tests
    /*coeff.push_back(10);
    coeff.push_back(89);
    coeff.push_back(210);
    coeff.push_back(162);*/

    for(int i = 0; i < 4; i++)
    {
        coeff.push_back(rand() % 257);
    }
}

int htable::hash(string ip)
{
    string delimiter = ".";

    size_t pos = 0;
    string num[4];
    string token;
    int ind = 0;
    while ((pos = ip.find(delimiter)) != std::string::npos)
    {
        token = ip.substr(0, pos);
        num[ind] = token;
        ip.erase(0, pos + delimiter.length());
        ind++;
    }
    num[ind] = ip;

    int inder =(stoi(num[3])*(coeff.at(0))
            +(stoi(num[2])*coeff.at(1))
            +(stoi(num[1])*coeff.at(2))
            +stoi(num[0])*coeff.at(3)) 
            %size; 

    return inder;

    
}

void htable::insert(string ip)
{
    if((lookup(ip).find("not"))== std::string::npos){
		std::cout << ip << " already exists" << std::endl;
		return;
	}
	int index = hash(ip);

    table[index].push_back(ip);
    inserted++;
    
    if(table[index].size()==2)
    {
        single--;
    }

    if(table[index].size()==1)
    {
        single++;
        empty--;
    }
    if(table[index].size()==max)
    {
        if (index>maxInd)
        {
            maxInd = index;
        }
    }
    else{
        if(table[index].size()>max)
        {
            maxInd = index;
            max = table[index].size();
        }
    }
	return;
}

void htable::remove(string ip)
{
    int index = hash(ip);
	std::list<std::string>::iterator it;
	for(it = table[index].begin(); it != table[index].end(); it++)
    {
		if(ip.compare(*it) == 0)
        {
			table[index].erase(it);
            deleted++;
            if(table[index].size()==0)
            {
                single--;
                empty++;
            }
            if(table[index].size()==1)
            {
                single++;
            }
            return;

        }

        
			
		
	}
	cout <<"Error : could not delete "<< ip << " because it does not exist." << std::endl;
	return;
}

string htable::lookup(string key)
{
    int index = hash(key);
	std::list<std::string>::iterator it;
	for(it = table[index].begin(); it != table[index].end(); it++){
			if(key.compare(*it) == 0){
				return key+": found";
			}
	}
	return key+": not found";
}

void htable::stat()
{
    for(int i = 0; i<4; i++)
    {
        cout<< coeff[i];
        if(i!=4)
        {
            cout<<" ";
        }
    }
    cout<<endl;
    cout<<inserted<<endl;
    cout<<deleted<<endl;
    cout<<empty<<endl;
    cout<<single<<endl;
    cout<<max<<" "<<maxInd<<endl;
}
