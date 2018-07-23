#include <vector>
#include <random>

class FeatureSampler {
public:
  
  FeatureSampler() = delete;
  FeatureSampler(int n_features, unsigned random_seed);
  
  int step();
  bool done();
  void reset();
  
private:
  std::vector<int> features;
  int current_pos;
  int n_features;
  
  std::mt19937 rng;
};