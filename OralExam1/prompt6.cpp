#include <iostream> 
#include <fstream> 
#include <string>
#include <map> 
#include <sstream>

using namespace std; 

int main()
{
    ifstream inFS;
    string inputFile = "prompt6.txt"; //make it equal to something
    map<string, double> stock;
    inFS.open(inputFile); 
    string header;
    getline(inFS, header); 

    string companyName, stockString;
    while( getline(inFS, companyName, ','))
    {
        getline(inFS, stockString);
        if(stockString[0] == ',')
        {
            stockString = stockString.substr(1);
        }
        istringstream ss(stockString);
        double stockDouble;
        ss >> stockDouble;

        stock[companyName] = stockDouble;
    }

    int numCompanies = stock.size();
    double total = 0.0;
    for(auto s : stock)
    {
        total += s.second;
    }
    double average = total / numCompanies;

    cout << endl;
    cout << "Companies above the mean stock price:" << endl;
    for(auto s : stock)
    {
        if(s.second > average)
        {
            cout << s.first << " " << s.second << endl;
        }
    }
    cout << endl;

    cout << "Companies listed in order:" << endl;
    for(auto s : stock)
    {
        cout << s.first << endl;
    }
    cout << endl;

    inFS.close();
    return 0; 
}