#include<vector>

struct pure_set {
  std::vector<pure_set> children;

  int contains(pure_set x);
  void insert(pure_set x);
  void remove(pure_set x);
};

bool pure_set_equals(pure_set a, pure_set b);

pure_set pure_set_union(pure_set a, pure_set b);

pure_set pure_set_difference(pure_set a, pure_set b);
