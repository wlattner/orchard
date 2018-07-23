#include <algorithm>
#include <numeric>
#include "feature_sampler.h"


FeatureSampler::FeatureSampler(int n_features, unsigned random_seed) : features(n_features), current_pos(n_features - 1), n_features(n_features), rng(random_seed) {
  std::iota(features.begin(), features.end(), 0);
}

int FeatureSampler::step() {
  // TODO: This is not safe at all... if step is called too many times, we will
  // probably segfault. The caller *must* check `done()`.
  
  std::uniform_int_distribution<> dist(0, current_pos);
  int j = dist(rng);
  int next_feature = features[j];
  
  std::swap(features[current_pos], features[j]);
  current_pos--;
  
  return next_feature;
}

bool FeatureSampler::done() {
  return current_pos == -1;
}

void FeatureSampler::reset() {
  current_pos = n_features - 1;
}