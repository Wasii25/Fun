#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

struct RoundStats {
  double wpm;
  double accuracy;
  double time;
};

void printRoundStats(vector<RoundStats>& allRounds) {
  if(!allRounds.empty()) {
    cout<<"==========Overall Stats=========="<<endl;
    double totalWPM = 0, totalAccuracy = 0;
    for(auto& it: allRounds) {
      totalWPM += it.wpm;
      totalAccuracy += it.accuracy;
    }
    cout<<"Total Rounds: "<<allRounds.size()<<endl;
    cout<<"Total Accuracy: "<<totalAccuracy / allRounds.size() <<endl;
    cout<<"Total Words Per Minute: "<<totalWPM / allRounds.size() <<endl;
    cout<<"Thank you for playing!!!"<<endl;
    cout<<endl<<endl;
  }
}

RoundStats playRound(vector<string>& sentences) {
  RoundStats stats;

  int randomIndex = rand() % sentences.size();

  string random_sentence = sentences[randomIndex];
  cout<<random_sentence<<endl;
  string user_input;
  time_t start = time(0);

  getline(cin,user_input);
  time_t end = time(0);
  int correctChars = 0;
  int totalChars = random_sentence.length();
  for(int i = 0; i<totalChars; i++) {
    if(i<user_input.length() && random_sentence[i] == user_input[i]) {
      correctChars++;
    }
  }
  stats.accuracy = (correctChars * 100.0) / totalChars;
  stats.time = difftime(end,start);
  stats.wpm = (correctChars/5) / (stats.time/60);
 return stats; 
}

int main() {
  srand(time(0));
     
    vector<string> sentences = {
        "the quick brown fox jumps over the lazy dog",
        "practice makes perfect with daily effort",
        "coding is fun when you solve problems",
        "never give up on your dreams and goals",
        "coffee fuels programmers around the world",
        "debugging is twice as hard as writing code",
        "algorithms and data structures are important",
        "always write clean and readable code",
        "testing your code saves time later",
        "open source software powers the internet",
        "version control makes collaboration easier",
        "learn something new every single day",
        "keyboard shortcuts boost your productivity",
        "compilers transform code into machine language",
        "recursion is a powerful programming technique",
        "memory management requires careful attention",
        "optimization should come after correctness",
        "documentation helps future developers understand code",
        "pair programming can improve code quality",
        "refactoring improves code without changing behavior",
        "edge cases often reveal hidden bugs",
        "unit tests catch bugs before deployment",
        "continuous integration automates the build process",
        "code reviews help teams share knowledge",
        "technical debt accumulates without regular maintenance"
    };
    vector<RoundStats> allRounds;

    char continueRound = 'y';

    while(true) {
    
      if(tolower(continueRound) != 'y') break;
      else {      
      RoundStats stats = playRound(sentences);
      allRounds.push_back(stats);

      cout<<"Accuracy: "<<stats.accuracy<<endl;
      cout<<"Words per minute: "<<stats.wpm<<endl;
      cout<<endl<<endl;
      cout<<"Do you want to continue? (y/n) "<<endl;
      cin>>continueRound;
      cin.ignore();
      cout<<endl<<endl;
      }
    }
    printRoundStats(allRounds);
   return 0;
}
