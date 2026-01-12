#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

// ANSI color codes
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";

struct RoundStats {
  double wpm;
  double accuracy;
  double time;
};


void showMistakes(string original, string typed) {
  int maxLength = max(original.length(), typed.length());
  bool hasMistakes = false;
  for(int i=0; i<maxLength; i++) {
    if(i >= original.length() || i >= typed.length() || original[i] != typed[i]) {
      hasMistakes = true;
      break;
    }
  }
  if(hasMistakes) {
    cout<<"You typed: ";
    for(int i=0; i<typed.length(); i++) {
      if(i < original.length() && original[i] == typed[i]) {
        cout<<GREEN<<typed[i]<<RESET;
      } else {
        cout<<RED<<typed[i]<<RESET;
      }
    }
    cout<<endl;
  }
}

void printRoundStats(vector<RoundStats>& allRounds) {
  if(!allRounds.empty()) {
    cout<<"==========Overall Stats=========="<<endl;
    double totalWPM = 0, totalAccuracy = 0;
    for(auto& it: allRounds) {
      totalWPM += it.wpm;
      totalAccuracy += it.accuracy;
    }
    cout<<"Total Rounds: "<<allRounds.size()<<endl;
    double finalAccuracy = totalAccuracy / allRounds.size();
    if(finalAccuracy == 100) {
      cout<<GREEN<<"Total Accuracy: "<<finalAccuracy<<"%"<<RESET<<endl;
    } else if(finalAccuracy >= 90) {
      cout<<YELLOW<<"Total Accuracy: "<<finalAccuracy<<"%"<<RESET<<endl;
    } else {
      cout<<RED<<"Total Accuracy: "<<finalAccuracy<<"%"<<RESET<<endl;
    }

    double finalwpm = totalWPM / allRounds.size();
    if(finalwpm >= 60) {
      cout<<GREEN<<"Total words per minute: "<<finalwpm<<RESET<<endl;
     } else if(finalwpm >= 40) {
      cout<<YELLOW<<"Total words per minute: "<<finalwpm<<RESET<<endl;
      } else {
      cout<<RED<<"Total words per minute: "<<finalwpm<<RESET<<endl;
    }

    cout<<"Thank you for playing!!!"<<endl;
    cout<<endl<<endl;
  }
}

void showAccuracy(RoundStats& stats) {

  if(stats.accuracy == 100) {
    cout<<GREEN<<"Accuracy: "<<stats.accuracy<<"%"<<RESET<<endl;
  } else if(stats.accuracy <= 90) {
    cout<<YELLOW<<"Accuracy: "<<stats.accuracy<<"%"<<RESET<<endl;
  } else {
    cout<<RED<<"Accuracy: "<<stats.accuracy<<"%"<<RESET<<endl;
  }
}



void showWPM(RoundStats& stats) {
  if(stats.wpm >= 60) {
    cout<<GREEN<<"Words per minute: "<<stats.wpm<<RESET<<endl;
  } else if(stats.wpm >= 40) {
    cout<<YELLOW<<"Words per minute: "<<stats.wpm<<RESET<<endl;
  } else {
    cout<<RED<<"Words per minute: "<<stats.wpm<<RESET<<endl;
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
  showMistakes(random_sentence, user_input);
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

      showAccuracy(stats);
      showWPM(stats);
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
