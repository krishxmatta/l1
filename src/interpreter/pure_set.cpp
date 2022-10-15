#include "pure_set.h"
using namespace std;

bool pure_set_equals(pure_set a, pure_set b) {
  if(a.children.size() != b.children.size()) {
    return false;
  }

  int sz = a.children.size();

  vector<bool> vis(sz, false);

  for(int i = 0; i < sz; i++) {
    bool found = false;
    for(int j = 0; j < sz && !found; j++) {
      if(!vis[j] && pure_set_equals(a.children[i], b.children[j])) {
        found = true;
        vis[j] = true;
      }
    }

    if(!found) {
      return false;
    }
  }
  
  return true;
}
