#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_TEAMS = 26;

struct Team {
    inline static int team_count;
    inline static int team_size;
    int members = 0;
    double score = 0;
    char name;
};

void create_teams(string input, Team teams[]);
bool check_size(Team (&teams)[MAX_TEAMS]);
void print_winner(Team (&teams)[MAX_TEAMS]);

int main() {
    
    while (true) {

        Team teams[MAX_TEAMS];
        Team::team_count = 0;
        Team::team_size = 0;
        string input;

        cout << "Enter a string of only uppercase letters or 'done' to exit: ";
        if (cin >> input && input.compare("done") == 0) return 0;
    
        if (input.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
            cout << endl << "Invalid character sequence, please try again." << endl;
            continue;
        }

        create_teams(input, teams);
        if (!check_size(teams)) continue;

        print_winner(teams);
    }
    return 0;
}

void create_teams(string input, Team teams[]) {

    for (int i = 0; i < input.length(); i++) {

        Team *team = &teams[input[i] - 'A'];
        if (team->members == 0) Team::team_count++;

        team->name = input[i];
        team->members += 1;
        team->score += i + 1;

        if (team->members > Team::team_size) Team::team_size = team->members;
    }            
}

bool check_size(Team (&teams)[MAX_TEAMS]) {
    for (Team team : teams) {
        if (team.members == 0) continue;
        if (team.members != Team::team_size) {
            cout << endl << "There must be an equal number of members for each team, please try again" << endl;
            return false;
        }
    }
    return true;
}

void print_winner(Team (&teams)[MAX_TEAMS]) {

    const int WIDTH = 6;
    double high_score = 0;
    Team winner;

    cout << endl << "There are " << Team::team_count << " teams." << endl << endl <<
            "Each team has " << Team::team_size << " runners." << endl << endl <<
            setw(WIDTH) << left <<
            "Team" << "Score" << endl;

    for (Team team : teams) {
        
        if (team.members == 0) continue;
        team.score = team.score / team.members;

        if (team.score < high_score || high_score == 0) {
            high_score = team.score;
            winner = team;
        }

        cout << setw(WIDTH) << left << setprecision(3) << 
                team.name << team.score << endl;
    }
    cout << endl << "The winning team is " << winner.name << " with a score of " << winner.score << endl << endl;
}