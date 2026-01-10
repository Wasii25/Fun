#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
    // 1. Store some sample sentences in a vector
     
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
    // 2. Pick random sentence (use rand() with current time as seed)
    srand(time(0));

    int randomIndex = rand() % sentences.size();

    string random_sentence = sentences[randomIndex];
    // 3. Display it and wait for user input
    cout<<random_sentence<<endl;
    string user_input;
    // 4. Record start time (use time() or clock())
    time_t start = time(0);

    // 5. Get user input
    getline(cin,user_input);
    // 6. Record end time and calculate difference
    time_t end = time(0);
    // 7. Compare strings character by character for accuracy
    int correctChars = 0;
    int totalChars = random_sentence.length();
    for(int i = 0; i<totalChars; i++) {
      if(i<user_input.length() && random_sentence[i] == user_input[i]) {
        correctChars++;
      }
    }

    double accuracy = (correctChars * 100.0) / totalChars;
    cout<<"accuracy: "<<accuracy<<endl;
    // 8. Calculate WPM = (characters / 5) / (seconds / 60)
    double seconds_taken = difftime(end,start);
    double wpm = (correctChars/5) / (seconds_taken/60);
    // 9. Display results!
    cout<<"words per minute: "<<wpm<<endl;
    return 0;
}
