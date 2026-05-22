#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>


using namespace std;

class database{
    public:
    void createTable(string tableName) {
        string fileName = tableName + ".csv";
        


        ofstream file(fileName);
        
        if (file.is_open()) {
            cout << "Successfully created storage for: " << tableName << endl;
            file.close();
        } else {
            cout << "Error: Could not create table file." << endl;
        }
    }


    void insertInto(string tableName, string data) {
        string fileName = tableName + ".csv";
        
    

        ofstream file(fileName, ios::app);
        
        if (file.is_open()) {
            file << data << endl;
            cout << "Data inserted into " << tableName << endl;
            file.close();
        } else {
            cout << "Error: Table " << tableName << " does not exist." << endl;
        }
    }
};


vector<string> split(string str) {
    vector<string> tokens;
    stringstream ss(str);
    string temp;
    while (ss >> temp) {
        tokens.push_back(temp);
    }
    return tokens;
}


string toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

int main()
{
    string command,name;
    database db;

    bool run = true;
    while(run)
    {
        cout << "db> ";
        getline(cin, command);

        //split the command into tokensss
        vector<string> tokens = split(command); 
        
        //if the userrr just pressed enter
        if(tokens.empty()) continue;

        //onlyy make the the first word uppercase for checkingg
        string action = toUpper(tokens[0]);

        if(action == "EXIT"){
            cout << "Exiting program..." << endl;
            run = false;
        }
        else if(action == "CREATE")
        {
            if(tokens.size() > 1) {
                db.createTable(tokens[1]); 
            } else {
                cout << "Error: Name your table!" << endl;
            }
        }
        else if(action == "INSERT")
        {
            
            if(tokens.size() >= 3) {
                db.insertInto(tokens[1], tokens[2]);
            } else {
                cout << "Error: Use format 'INSERT tableName data'" << endl;
            }
        }

        else if(action == "SELECT")
        {
            cout << "Reading data from table: " << (tokens.size() > 1 ? tokens[1] : "unknown") << endl;
        }
    }

    return 0;
}