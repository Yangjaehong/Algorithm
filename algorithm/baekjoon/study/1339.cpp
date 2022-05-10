/*#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include <functional>

using namespace std;


int main() {
   int N = 0;
   string word;
   char abc[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
               'H', 'I', 'J', 'K', 'L', 'M', 'N', 
               'O', 'P', 'Q', 'R', 'S', 'T', 'U',
               'V', 'W', 'X', 'Y', 'Z'};
   int max = 9;
   int total = 0;

   vector<pair<int, char> > abc_int;
   for (int i = 0; i < 26; i++) {
      abc_int.push_back(make_pair(0, abc[i]));
   }

   cin >> N;

   for (int i = 0; i < N; i++) {
      cin >> word;
      for (int j = 0; j < word.size(); j++) {
         for (int k = 0; k < 26; k++) {
            if (abc[k] == word[j])
            {
               abc_int[k].first += pow(10, (word.size() - 1) - j);
               break;
            }
         }
      }
   }

   sort(abc_int.begin(), abc_int.end(), greater<> ());
   for (int i = 0; i < abc_int.size(); i++) {
      total += abc_int[i].first * max;
      max--;
      if (abc_int[i].first == 0) break;
   }

   cout << total << endl;

   for (int i = 0; i < 10; i++) {
      cout << abc_int[i].first << "  " << abc_int[i].second << endl;
   }

   return 0;
}*/