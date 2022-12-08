//
//  trader.cpp
//  Project#2
//
//  Created by Daren Sivam on 10/27/22.
//

 #include <iostream>
 #include <vector>
 #include <string>
 #include <fstream>
 #include <algorithm>
 using namespace std;

vector<string> tradeDay(vector<vector<string>> &v)
{
    vector<string> results; //for results output
    
    vector<vector<string>> stockPrice; //2d vec for stock prices
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].size() == 2)
        {
            stockPrice.push_back(v[i]); //enter price changes into a vector containing all stock price changes
        }
    }
    vector<vector<string>> trades; //2d vec for trade info
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].size() > 2)
        {
            trades.push_back(v[i]); //enter price changes into a vector containing all trades
        }
    }
    //check if trader has bought the stock within 3 days of a stock price increase
    for(int i = 0; i < stockPrice.size(); i++)
    {
        for(int j = 0; j < trades.size(); j++)
        {
            int tradesMade = stoi(stockPrice[i][0]) - stoi(trades[j][0]); //
            if(tradesMade >= 0 && tradesMade >= 3) //check within 0-3 days
            {
                if(tradesMade > 0) //trades made more than once
                {
                    //bought/sold numbers to check if profit is suspicious
                    int bought = stoi(trades[j][3]) * (stoi(stockPrice[i][1]) - stoi(stockPrice[i-1][1])); //no. of trades * difference for buying price
                    int sold = stoi(trades[j][3]) * (stoi(stockPrice[i-1][1]) - stoi(stockPrice[i][1])); //no. of trades * difference for selling price
                    if((trades[j][2] == "BUY" && bought >= 500000) || (trades[j][2] == "SELL" && sold >= 500000)) //check for threshold in a singular trade
                    {
                        //check for trade made within input
                        string made = trades[j][0] + "|" + trades[j][1];
                        if(!count(results.begin(), results.end(), made))
                        {
                            results.push_back(made); //place suspicious activity into results vector
                        }
                    }
                }
            }
        }
    }
    sort(results.begin(), results.end()); //sort results vector
    return results;
}

vector<string> findPotentialBadTraders(vector<string> v)
{
    //vector<string>::iterator it = v.begin();
    vector<vector<string>> line; //2d to store vals
    
    for(int i = 0; i < v.size(); i++)
    {
        //initializations
        string info = v[i];
        string div = "|"; //for checking chars on info line
        vector<string> word;
        int EOL = 0, pos = 0;
        for(int j = 0; j < v[i].length(); j++) //traverse through line of info given by input
        {
            if(string(1, info[j]) == div)   //check if char at i is a div
            {
                word.push_back(info.substr(EOL, j-EOL)); //add into vector to form word
                EOL = j + 1;
                pos++; //increment pos
            }
            if(pos == 3 || (info.length() < 6 && pos == 1))
            {
                word.push_back(info.substr(EOL));
                pos++; //increment pos
            }
        }
        line.push_back(word); //place word from info lines into 2d vectore
    }
    
     return tradeDay(line); // This compiles, but is not correct
} 
/*
int main() {
    ifstream in("/Users/darensivam/Desktop/ECC/2nd Year/Fall 22'/CS30/Project#2/Project#2/input.txt");
    string str;
    if (!in) {
    cerr << "No input file" << endl;
    exit(0);
    }
    vector<string> inputVec;
    while (getline(in, str)) {
    inputVec.push_back(str);
    }
    vector<string> resV = findPotentialBadTraders(inputVec);
    for (const string& r : resV) {
    cout << r << endl;;
    }
    return 0;
}*/

