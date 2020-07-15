#include<bits/stdc++.h>

using namespace std;

void naiveSearchRemove();

string TXT;
list<string> SPELLS;
int MAX_SPELL = 0;


int main(){
  cin>>TXT;
  int t, i;
  scanf("%d", &t);
  for (i = 0; i < t; i++){
    string spell;
    cin>>spell;
    if (spell.length() > MAX_SPELL)
      MAX_SPELL = spell.length();
    SPELLS.push_back(spell);
  }
  naiveSearchRemove();
  cout<<TXT;
  return 0;
}

void naiveSearchRemove(){
  int i,
      j,
      k,
      n = TXT.length();
  list<string> _SPELLS = SPELLS;
  j = 0, k = 0;
  for (i = 0; i < n;){
    for (list<string>::iterator it = _SPELLS.begin(); it != _SPELLS.end(); ++it){
      if (j == it->length()){
        TXT.erase(i, j);
        i -= MAX_SPELL - 1;
        if (i < 0)
          i = -1;
        k = i;
        _SPELLS = SPELLS;
        j = -1;
        break;
      }
      if (i + j >= n || TXT[i + j] != (*it)[j]){
        _SPELLS.erase(it--);
      }
    }
    if (_SPELLS.size() == 0){
      _SPELLS = SPELLS;
      k = ++i;
      j = 0;
    }else{
      j++;
      k++;
    }
  }
}

