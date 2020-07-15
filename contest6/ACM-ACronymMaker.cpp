#include<bits/stdc++.h>

#define MAX 150

using namespace std;

int d[MAX][MAX];

int f (string abbr, int abbr_i, string phrase, int phrase_i, int n_words, int word_i, bool matchWord);

int main(){
  int n, 
      n_words,
      n_possible_matchings,
      i,
      j;
  set<string> insignifWords;
  vector<string>::iterator it;
  string tc, 
         abbr, 
         phrase, 
         insignifWord;
  while(scanf("%d", &n), n){
    //read insignificant words
    insignifWords.clear();
    while(n--){
      cin>>insignifWord;
      insignifWords.insert(insignifWord);
    }
    getchar();
    while (true){
      //read test case
      getline(cin, tc);
      //split by spaces
      istringstream iss(tc);
      vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>()); 
      //get first two words
      it = results.begin();
      abbr = *it;
      phrase = *(++it);
      //check if is the last case
      if (abbr == "LAST" && phrase == "CASE")
        break;
      //get remaning phrase
      n_words = 1;
      for (it++; it != results.end(); it++)
        if (insignifWords.find(*it) == insignifWords.end()){
          phrase += " " + *it;
          n_words++;
        }
      //cout cases
      for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
          d[i][j] = -1;
      n_possible_matchings = f(abbr, 0, phrase, 0, n_words, 1, false);
      cout<<abbr;
      if (n_possible_matchings)
        cout<<" can be formed in "<<n_possible_matchings<<" ways"<<endl;
      else
        cout<<" is not a valid abbreviation"<<endl;
    }
  }
  return 0; 
}

int f (string abbr, int abbr_i, string phrase, int phrase_i, int n_words, int word_i, bool matchWord){
  if (abbr_i == abbr.length() && word_i == n_words && matchWord)
      return 1;
  if (phrase[phrase_i] == ' ' && !matchWord)
    return 0;
  if ((abbr.length() - abbr_i < n_words - word_i) ||
      (abbr_i < abbr.length() && phrase_i == phrase.length()) ||
      (abbr_i == abbr.length() && word_i < n_words) || 
      (abbr_i == abbr.length() && word_i == n_words && !matchWord))
      return 0;
  if (phrase[phrase_i] == abbr[abbr_i] - 'A' + 'a'){
    //case 1
    if (d[abbr_i + 1][phrase_i + 1] < 0)
      d[abbr_i + 1][phrase_i + 1] = f(abbr, abbr_i + 1, phrase, phrase_i + 1, n_words, word_i, true);
    //case 2
    if (d[abbr_i][phrase_i + 1] < 0)
      d[abbr_i][phrase_i + 1] = f(abbr, abbr_i, phrase, phrase_i + 1, n_words, word_i, matchWord);
    return d[abbr_i + 1][phrase_i + 1] + d[abbr_i][phrase_i + 1];
  }
  if (phrase[phrase_i] == ' '){
    int a = f(abbr, abbr_i, phrase, phrase_i + 1, n_words, word_i + 1, false);
    return a;
  }
  int b = f(abbr, abbr_i, phrase, phrase_i + 1, n_words, word_i, matchWord);
//  printf("%d,%d: %d\n", abbr_i + 1, phrase_i + 1, b);
  return b;
}
