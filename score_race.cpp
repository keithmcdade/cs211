#include <iostream>
#include <iomanip>
using namespace std;

void insert_team(string &teams, char team);

struct Team {
    char name;
    int members = 0;
    double score = 0;
};

int main() {
    
    const int WIDTH = 6;
    string input;
    
    cout << "Enter a string of only uppercase letters: ";

label:
    while (cin >> input && input.compare("done") != 0) {

        Team teams[26];
        string team_names = "";

        cout << endl;
        
        if (input.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
            cout << "Invalid character sequence, please try again: ";
            goto label;
        }

        for (int i = 0; i < input.length(); i++) {
            
            if (team_names.find(input[i]) == string::npos) {
                insert_team(team_names, input[i]);
            }

            teams[input[i] - 'A'].name = input[i];
            teams[input[i] - 'A'].members += 1;
            teams[input[i] - 'A'].score += i + 1;
        }

        int member_count = teams[team_names[0] - 'A'].members;


        for (int i = 0; i < team_names.length(); i++) {
            if (teams[team_names[i] - 'A'].members != member_count) {
                cout << "There must be an equal number of members for each team, please try again: ";
                goto label; 
            }
        }

        cout << "There are " << team_names.length() << " teams." << endl << endl;
        cout << "Each team has " << member_count << " runners." << endl << endl;
        cout << setw(WIDTH) << left;
        cout << "Team" << "Score" << endl;

        for (int i = 0; i < team_names.length(); i++) {

            teams[team_names[i] - 'A'].score /= teams[team_names[i] - 'A'].members;

            cout << setw(WIDTH) << left << setprecision(3);
            cout << team_names[i] << teams[team_names[i] - 'A'].score << endl;
        }

        cout << endl << "Enter a string of only uppercase letters: ";
    }
    return 0;
}

void insert_team(string &teams, char team) {
    if (teams.length() == 0) teams += team;
    else {
        for (int j = 0; j < teams.length(); j++) {
            if (team < teams[j]) {
                string s(1, team);
                teams.insert(j, s);
                break;
            }
            else teams += team;
            break;
        }
    }
}