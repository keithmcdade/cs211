#include <iostream>
#include <iomanip>
using namespace std;

struct Team {
    char name;
    int members = 0;
    double score = 0;
};

void insert_team(string &team_names, char team);
void create_teams(string input, string &team_names, Team teams[]);
bool check_size(string team_names, Team teams[], int member_count);

int main() {
    
    const int WIDTH = 6;
    string input;
    
    cout << "Enter a string of only uppercase letters: ";

    while (cin >> input && input.compare("done") != 0) {

        Team teams[26];
        string team_names = "";

        cout << endl;
        
        if (input.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
            cout << "Invalid character sequence, please try again: ";
            continue;
        }

        create_teams(input, team_names, teams);

        int member_count = teams[team_names[0] - 'A'].members;
        if (!check_size(team_names, teams, member_count)) continue;
        
        cout << "There are " << team_names.length() << " teams." << endl << endl <<
                "Each team has " << member_count << " runners." << endl << endl <<
                setw(WIDTH) << left <<
                "Team" << "Score" << endl;

        for (int i = 0; i < team_names.length(); i++) {

            Team team = teams[team_names[i] - 'A'];
            team.score /= team.members;

            cout << setw(WIDTH) << left << setprecision(3) << 
                    team_names[i] << team.score << endl;
        }

        cout << endl << "Enter a string of only uppercase letters: ";
    }
    return 0;
}

void insert_team(string &team_names, char team) {
    if (team_names.length() == 0) team_names += team;
    else {
        for (int j = 0; j < team_names.length(); j++) {
            if (team < team_names[j]) {
                string s(1, team);
                team_names.insert(j, s);
                break;
            }
            else team_names += team;
            break;
        }
    }
}

void create_teams(string input, string &team_names, Team teams[]) {

    for (int i = 0; i < input.length(); i++) {

        if (team_names.find(input[i]) == string::npos) insert_team(team_names, input[i]);

        Team *team = &teams[input[i] - 'A'];
        team->name = input[i];
        team->members += 1;
        team->score += i + 1;
    }            
}

bool check_size(string team_names, Team teams[], int member_count) {
    for (int i = 0; i < team_names.length(); i++) {
            if (teams[team_names[i] - 'A'].members != member_count) {
                cout << "There must be an equal number of members for each team, please try again: ";
                return false; 
            }
        }
    return true;
}