#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
vector<int> initNext(string Pattern) {
    vector<int> next(Pattern.length());

    for(int i=1, j=0; i<Pattern.length(); i++) {
        while(j>0 && Pattern[i] != Pattern[j]) j = next[j-1];
        if(Pattern[i] == Pattern[j]) next[i] = ++j;
    }
    return next;
}
 
vector<int> KMP(string Str, string Pattern) {
    vector<int> Pi = initNext(Pattern), next;
    for(int i=0, j=0; i<Str.length(); i++) {
        while(j>0 && Str[i] != Pattern[j]) j = Pi[j-1];
        if(Str[i] == Pattern[j]) {
            if(j == Pattern.length()-1) {
                next.push_back(i-j);
                j = Pi[j];
            }
            else j++;
        }
    }
    return next;
}
 
int main() {
    string text1 = "ababababcababababcaabbabababcaab";
    string pattern1 = "abababca";
    string text2 = "This class is an algorithm design class. Therefore, students will have time to learn about algorithms and implement each algorithm themselves."; 
    string pattern2 = "algorithm";

    vector<int> Position = KMP(text1, pattern1);
    for (int i = 0; i < Position.size(); i++)
        cout << Position[i] << endl;
    Position = KMP(text2, pattern2);
    for (int i = 0; i < Position.size(); i++)
        cout << Position[i] << endl;
}