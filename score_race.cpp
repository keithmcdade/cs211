#include <iostream>
#include <iomanip>
using namespace std;

bool check_size(int teams[][2], int n, int team_size);

int main() {

    const int WIDTH = 6, MAX_TEAMS = 26;
    
    while(true) {
        int teams[26][2] = {0}, team_count = 0, team_size = 0;
        double best_score = 0;
        string input, winners;

        cout << "Enter a string of only uppercase letters or 'done' to exit: ";
        if (cin >> input && input.compare("done") == 0) return 0;
        // validate input for only char A-Z
        if (input.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
            cout << endl << "Invalid character sequence, please try again." << endl;
            continue;
        }
    
        // iterate through input, teams[i][0] == no. of runners, teams[i][1] == score
        for (int i = 0; i < input.length(); i++) {
            
            char t = input[i] - 'A';
            if (teams[t][0] == 0) team_count++;

            teams[t][0]++;
            teams[t][1] += i + 1;

            if (teams[t][0] > team_size) team_size++;
        }
        
        // check if each team is the same size
        if (!check_size(teams, MAX_TEAMS, team_size)) continue;
        cout << endl << "There are " << team_count << " teams." << endl << endl <<
            "Each team has " << team_size << " runners." << endl << endl << setw(WIDTH) << 
            left << "Team" << "Score" << endl;       

        // iterate through teams add team to winners if score == best_score, clear other winners if better
        for (int i = 0; i < MAX_TEAMS; i++) {

            if (teams[i][0] == 0) continue;
        
            double score = (double)teams[i][1] / teams[i][0];
            if (best_score == 0 || score < best_score) {
                best_score = score;
                winners = "";
            }
            if (score <= best_score) winners += (char)i + 'A';

            cout << setw(WIDTH) << left << setprecision(3) << 
                (char)(i + 'A') << score << endl;
        }

        // print results
        cout << endl;
        for (int i = 0; i < winners.length(); i++) 
            cout << "The winning team is " << winners[i] << " with a score of " << best_score << endl;
        cout << endl;
    }
    return 0;
}

bool check_size(int teams[][2], int n, int team_size) {
    for (int i = 0; i < n; i++) {
        if (teams[i][0] == 0) continue;
        if (teams[i][0] != team_size) {
            cout << endl << "There must be an equal number of members for each team, please try again" << endl;
            return false;
        }
    }
    return true;
}