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

/**
 * Conversions:
 * 48 teaspoons = 1 cup
 * 8 oz = 1 cup
 * 1 cup = 1 cup
*/

int main()
{
    ifstream inFS;
    string inputFile = "prompt3.txt"; //make it equal to something
    map<pair<string,string>, double> veganCookies; 
    inFS.open(inputFile);
    string header;
    getline(inFS, header);  

    int iterator = 0;
    // 0 % 2 = 0 : pair<string,string> measure, ingredient iterator++;
    // 0 % 2 != int measureNum iterator = 0;
    string measureDevice, ingredient;

    while(!inFS.eof())
    {
        string inputLine;
        if ( getline(inFS, inputLine) )
        {
            if(!inputLine.empty())
            {
                if(iterator % 2 == 0)
                {
                    iterator++;
                    size_t spaceSeperator = inputLine.find(' ');
                    istringstream s1(inputLine.substr(0, spaceSeperator));
                    s1 >> measureDevice;
                    istringstream s2(inputLine.substr(spaceSeperator + 1));
                    getline(s2, ingredient); 
                }
                else
                {
                    iterator = 0;
                    double measureNum; 
                    istringstream ss(inputLine);
                    ss >> measureNum;
                    veganCookies[make_pair(measureDevice, ingredient)] =  measureNum;
                    measureDevice.clear();
                    ingredient.clear();
                }
            }
        }
    }

    int numIngredients = veganCookies.size(); 
    double numCup = 0.0; 
    for(auto v : veganCookies)
    {
        if(v.first.first == "cups")
        {
            numCup += v.second;
        }
        else if(v.first.first == "oz")
        {
            numCup += (v.second / 8.0);
        }
        else if(v.first.first == "teaspoon")
        {
            numCup += (v.second / 48.0); 
        }
    }
    cout << endl;
    cout << "Quantity of Ingredients: " << numIngredients << endl;
    cout << "Total amount of cups required for everything: " << numCup << endl << endl;

    cout << "Shopping list below:" << endl;
    for(auto v : veganCookies)
        cout << v.second << " " << v.first.first << " of " << v.first.second << endl;
    cout << endl;
    inFS.close();
    return 0; 
}