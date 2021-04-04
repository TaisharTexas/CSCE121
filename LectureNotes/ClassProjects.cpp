#include <iostream>

using namespace std;
using std::cout;
using std::cin;

//total goals, total behinds, total pts
//home team reported first
//HomeName g.b (total) [defeated, defeated by, drew with] AwayName g.b (total)

//need a score class that holds team names, # goals, # behinds each team

class Score
{
private:
    string teamName1;
    string teamname2;
    int goalsTeam1;
    int goalsTeam2;
    int behindsTeam1;
    int behindsTeam2;

    friend ostream& operator << (ostream& os, const Score& s);

public:
    Score(string teamName1, int goalsTeam1, int behindsTeam1,
          string teamName2, int goalsTeam2, int behindsTeam2) :
            teamName1(teamName1), goalsTeam1(goalsTeam1), behindsTeam1(behindsTeam1),
            teamName2(teamName2), goalsTeam2(goalsTeam2), behindsTeam2(behindsTeam2) {}

    int getTotalScore(string theTeam, int goals, int behinds)
    {
        int totalScore = (goals * 6) + (behinds);
        return totalScore
    }

    string winner(string teamName1, string teamName2)
    {
        int team1Total = getTotalScore(teamName1, goalsTeam1, behindsTeam1);
        int team2Total = getTotalScore(teamName2, goalsTeam2, behindsTeam2);
        string winnerMsg;
        if(team1Total > team2Total)
        {
            winnerMsg = teamName1 + " defeated " + teamName2;
        }
        else if(team1Total == team2Total)
        {
            winnerMsg = teamName1 + " drew with " + teamName2;
        }
        else
        {
            winnerMsg = teamName1 + " was defeated by " + teamName2;
        }

        return winnerMsg;
    }
};

ostream& operator << (ostream& os, const Scare& s)
{
    cout << s.teamName1 << " " << s.goalsTeam1 << "." << s.behindsTeam1
          << " (" << s.getTotalScore(teamName1, s.goalsTeam1, s.behindsTeam1) << ") "
          << s.winner(teamName1, teamName2) << " "
          << s.teamName2 << " " << s.goalsTeam2 << "." << s.behindsTeam2
          << " (" << s.getTotalScore(teamName2, s.goalsTeam2, s.behindsTeam2) << ") " ;
    return os;
}
