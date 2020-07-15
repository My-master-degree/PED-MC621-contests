#include <stdio.h>      /* printf */
#include <math.h>       /* ceil */
#include <string.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define pb push_back
#define lb lower_bound
#define ub upper_bound

typedef vector<int> vi;
typedef vector<vi> vv;

int b[1000005];
int n, m;
string s1, s2, s3, T;
string s;
void kmpPre()
{
  int j = b[0] = -1;

  for(int i = 0 ; i < s.size(); )
  {
    while(j >= 0 && s[i] != s[j])
      j = b[j];
    j++;
    i++;
    b[i] = j;
  }
}
int mini  = 0;

bool kmpSearch()   // this is similar as kmpPreprocess(), but on string T
{
  int i = 0, j = 0; // starting values
  while (i < T.size())   // search through string T
  {
    while (j >= 0 && T[i] != s[j]) j = b[j]; // if different, reset j using b
    i++;
    j++; // if same, advance both pointers
    if (j == s.size())   // a match found when j == m
    {
      return true;
      j = b[j]; // prepare j for the next possible match
    }
  }
  return false;
}

int makeString(string s1, string s2, string s3)
{
  int maxL = 0;
  s = s2;
  T = s1;
  kmpPre();
  if(kmpSearch()){
    maxL = s2.size();
  }else{
    s = s2 + s1;
    m = s.size();
    kmpPre();
    int l = s.size();
    do{
      maxL = b[l];
      l = b[l];
    }while(maxL > s1.size());
  }
  s = s1;
  if(maxL == 0)
    s.append(s2);
  else
  {
    for(int i = maxL ; i < s2.size(); i++)
      s += s2[i];
  }
  string ss = s;
  T = ss;
  s = s3;
  kmpPre();
  if(kmpSearch()){
    maxL += s3.size();
  }else{
    s = s3 + ss;
    m = s.size();
    kmpPre();
    int l = s.size();
    int maxL2;
    do{
      maxL2 = b[l];
      l = b[l];
    }while(maxL2 > s1.size());
    maxL += maxL2;
  }

  return s1.size() + s2.size() + s3.size() - maxL;

}

int min(int x, int y)
{
  return x < y ? x : y;
}

int main()
{
  char c[1000005];
  int T;
  int t;

  while(scanf("%s", c) != EOF)
  {
    s1 = c;
    scanf("%s", c);
    s2 = c;
    scanf("%s", c);
    s3 = c;
    mini = makeString(s1, s2, s3);
    mini = min(mini, makeString(s1, s3, s2));
    mini = min(mini, makeString(s2, s1, s3));
    mini = min(mini, makeString(s2, s3, s1));
    mini = min(mini, makeString(s3, s2, s1));
    mini = min(mini, makeString(s3, s1, s2));
    printf("%d\n", mini);
  }
  return 0;
}
