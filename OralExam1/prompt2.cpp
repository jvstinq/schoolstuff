#include <iostream> 
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <stack> 
#include <queue> 
#include <sstream>
#include <sstream>

#define ERROR GENSHIN
#define BUG YAEMIKO

using namespace std; 

int main()
{
    ifstream inFS;
    string inputFile = "prompt2.txt"; //make it equal to something
    //Include Containers
    inFS.open(inputFile); 
    int totalMoney = 0;
    int counter = 0; 

    while(!inFS.eof())
    {
        
    }

    cout << "Total money made: $" << totalMoney << endl; 
    cout << "The amount of people to bring in to make $30 is: " << counter << " people." << endl;

    inFS.close();
    return 0; 
}