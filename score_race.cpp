#include <iostream>
#include <iomanip>
#include <regex>
using namespace std;

bool valid(string s);
void fill_teams(string input, string &teams, int members[], double scores[]);
void insert_team(string &teams, char team);

int main() {
    
    const int WIDTH = 6;
    string input;
    
    cout << "Enter a string of only uppercase letters: ";

label:
    while (cin >> input && input.compare("done") != 0) {

        int member_count = 0, members[26] = {0};
        double scores[26] = {0};
        string teams = "";
        
        cout << endl;
        
        if (!valid(input)) {
            cout << "Invalid character sequence, please try again: ";
            goto label;
        }

        for (int i = 0; i < input.length(); i++) {
            if (teams.find(input[i]) == string::npos) {
                insert_team(teams, input[i]);
            }
            members[input[i] - 'A'] += 1;
            scores[input[i] - 'A'] += i + 1;
        }

        member_count = members[teams[0] - 'A'];

        for (int i = 0; i < teams.length(); i++) {
            if (members[teams[i] - 'A'] != member_count) {
                cout << "There must be an equal number of members for each team, please try again: ";
                goto label; 
            }
        }

        cout << "There are " << teams.length() << " teams." << endl << endl;
        cout << "Each team has " << member_count << " runners." << endl << endl;
        cout << setw(WIDTH) << left;
        cout << "Team" << "Score" << endl;

        for (int i = 0; i < teams.length(); i++) {

            scores[teams[i] - 'A'] /= members[teams[i] - 'A'];

            cout << setw(WIDTH) << left << setprecision(3);
            cout << teams[i] << scores[teams[i] - 'A'] << endl;
        }

        cout << endl << "Enter a string of only uppercase letters: ";
    }
    return 0;
}

bool valid(string s) {
    return true;
}

void fill_teams(string input, string &teams, int members[], double scores[]) {
    return;
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