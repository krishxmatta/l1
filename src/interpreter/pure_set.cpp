#include <stdio.h>
#include "pure_set.h"
using namespace std;

int pure_set::contains(pure_set x) {
  for(int i = 0; i < children.size(); i++) {
    if(pure_set_equals(children[i], x)) {
      return i;
    }
  }

  return -1;
}

void pure_set::insert(pure_set x) {
  for(int i = 0; i < children.size(); i++) {
    if(pure_set_equals(children[i], x)) {
      return;
    }
  }

  children.push_back(x);
}

void pure_set::remove(pure_set x) {
  for(int i = 0; i < children.size(); i++) {
    if(pure_set_equals(children[i], x)) {
      children.erase(children.begin() + i);
      return;
    }
  }
}

pure_set pure_set::pick() {
  int idx = arc4random_uniform(children.size());
  pure_set ret = children[idx];
  children.erase(children.begin() + idx);
  return ret;
}

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

pure_set pure_set_union(pure_set a, pure_set b) {
  pure_set ret;
  for(int i = 0; i < a.children.size(); i++) {
    if(ret.contains(a.children[i]) == -1) {
      ret.insert(a.children[i]);
    }
  }

  for(int i = 0; i < b.children.size(); i++) {
    if(ret.contains(b.children[i]) == -1) {
      ret.insert(b.children[i]);
    }
  }

  return ret;
}

pure_set pure_set_difference(pure_set a, pure_set b) {
  pure_set ret;
  for(int i = 0; i < a.children.size(); i++) {
    if(b.contains(a.children[i]) == -1) {
      ret.insert(a.children[i]);
    }
  }

  return ret;
}

void pure_set_print(pure_set a) {
  if(!a.children.size()) {
    printf("0 ");
  } else {
    printf("{ ");
    for(int i = 0; i < a.children.size(); i++) {
      pure_set_print(a.children[i]);
    }
    printf("} ");
  }
}
