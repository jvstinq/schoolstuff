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
#include <list> 
#include <sstream>
#include <sstream>

#define ERROR GENSHIN
#define BUG YAEMIKO

using namespace std; 

/**
 * For this, make two strings, then concatentate, then get the int. 
*/

int main()
{
    ifstream inFS;
    string inputFile = "prompt4.txt"; //make it equal to something
    map<string, int> cereal;
    inFS.open(inputFile); 

    string header;
    getline(inFS, header); 

    string cerealName = "";

    while(!inFS.eof())
    {
        int calories;
        string inputLine; 
        string wordVector;

        if( getline(inFS, inputLine) )
        {
            if(!inputLine.empty())
            {
                istringstream ss(inputLine); 
                while(ss >> wordVector)
                {
                    if(isdigit(wordVector[0]))
                    {
                        int numCalories = stoi(wordVector);
                        cereal[cerealName] = numCalories;
                        cerealName.clear();
                    }
                    else
                    {
                        if(cerealName.empty())
                        {
                            cerealName += wordVector;
                        }
                        else
                        {
                            cerealName += " " + wordVector; 
                        }
                    }
                } 
            }
        }
    }

    double numCalories = 0.0;
    double numCereal = 0.0; 
    for(auto c : cereal)
    {
        numCalories += c.second; 
        numCereal++;
    }
    double meanCalories = numCalories / numCereal;
    cout << showpoint << fixed << setprecision(2);
    cout << "Mean number of calories: " << meanCalories << endl << endl; 

    map<string, int> belowMean; 
    map<string, int> aboveMean; 

    for(auto c : cereal)
    {
        if(c.second > meanCalories)
        {
            aboveMean[c.first] = c.second;
        }
        else if(c.second < meanCalories)
        {
            belowMean[c.first] = c.second;
        }
        else
        {
            cout << "Bug found." << endl;
        }
    }

    cout << "Cereal below mean calories:" << endl;
    for(auto b : belowMean)
        cout << b.first << endl;
    cout << endl;
    cout << "Cereal above mean calories:" << endl;
    for(auto a : aboveMean)
        cout << a.first << endl;
    cout << endl;

    inFS.close();
    return 0; 
}