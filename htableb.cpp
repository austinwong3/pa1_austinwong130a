#include <iostream>
#include "htableb.h"
#include <string>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

htable::htable(int size, int b)
{
    this->size = size;
    table.resize(this->size);
    this->inserted = 0;
    this->deleted = 0;
    this->empty = this->size;
    this->single = 0;
    this->max = 0;
    this->maxInd = 0;
    this->b = b;
    /*coeff.push_back(9);
    coeff.push_back(24);
    coeff.push_back(55);
    coeff.push_back(9);
    coeff.push_back(20);
    coeff.push_back(58);*/
    /*coeff.push_back(127);
    coeff.push_back(159);
    coeff.push_back(124);
    coeff.push_back(136);*/
    /*coeff.push_back(104);
    coeff.push_back(643);
    coeff.push_back(910);
    coeff.push_back(96);*/
    /*coeff.push_back(10);
    coeff.push_back(11);
    coeff.push_back(5);
    coeff.push_back(14);
    coeff.push_back(3);
    coeff.push_back(8);
    coeff.push_back(2);
    coeff.push_back(13);*/

    int numCo = 32/b;
    if (32%b!=0)
        numCo++;

    for(int i = 0; i < numCo; i++)
    {
        coeff.push_back(rand() % size);
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

    string binIp;
    for( int i =0; i<4; i++)
    {
        binIp += toBin(num[i]);
    }


    std::vector<int> x;
	while(binIp.size()>b)
	{
		std::string temp = binIp.substr(binIp.size()-b,b);
		x.insert(x.begin(), stoi(toDec(temp)));
		binIp.erase(binIp.size()-b,b);
	}
	if (binIp.size()!=0) {
		x.insert(x.begin(), stoi(toDec(binIp)));
	}
    
    int inder = 0;
    for(int i = 0; i<coeff.size();i++)
    {
        inder += x[(coeff.size()-1)-i]*coeff[i];
    }

    return inder%size;

    
}

string htable::toBin(string num)
{
    int dec = stoi(num);
    string bin="";
    while(dec>0)
    {
        bin = to_string(dec%2) + bin;
        dec/=2;
    }
    while(bin.size()!=8)
    {
        bin ="0" +bin;
    }

    return bin;
}

string htable::toDec(string num)
{
    int dec =0;
    for(int i = 0; i<num.size(); i++)
    {
        dec += pow(2,num.size()-1-i)*(num[i]-'0');
    }
    return to_string(dec);

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
	cout << ip << " does not exist" << std::endl;
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
    for(int i = 0; i<coeff.size(); i++)
    {
        cout<< coeff[i];
        if(i!=coeff.size()-1)
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
