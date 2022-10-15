#include<vector>

struct pure_set {
  std::vector<pure_set> children;
};

bool pure_set_equals(pure_set a, pure_set b);
