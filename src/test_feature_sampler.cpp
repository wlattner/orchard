#include <vector>
#include <algorithm>

#include <testthat.h>
#include "feature_sampler.h"

context("FeatureSampler") {
  
  int n_features = 10;
  FeatureSampler fs(n_features, 561);
  
  test_that("it works") {
    int i = fs.step();
    expect_true(i >= 0);
    expect_true(i <= n_features - 1);
  }
  
  test_that("generates all n features when called n times") {
    std::vector<int> values;
    for (int i = 0; i < n_features; i++) {
      int val = fs.step();
      values.push_back(val);
    }
    
    std::sort(values.begin(), values.end());
    int n_uniq = std::unique(values.begin(), values.end()) - values.begin();
    
    expect_true(n_uniq == n_features);
  }
  
  test_that("does not generate n features in sorted order") {
    std::vector<int> values;
    for (int i = 0; i < n_features; i++) {
      int val = fs.step();
      values.push_back(val);
    }
    
    expect_false(std::is_sorted(values.begin(), values.end()));
  }
  
  test_that("is done after step called n_features times") {
    for (int i = 0; i < n_features; i++) {
      fs.step();
    }

    expect_true(fs.done());
  }
  
  test_that("is not done after step called fewer than n_features times") {
    for (int i = 0; i < n_features - 3; i++) {
      fs.step();
    }
    
    expect_false(fs.done());
  }
  
  test_that("we can generate a new sequence after calling reset") {
    for (int i = 0; i < n_features - 4; i++) {
      fs.step();
    }
    
    fs.reset();
    std::vector<int> values;
    for (int i = 0; i < n_features; i++) {
      values.push_back(fs.step());
    }
    
    std::sort(values.begin(), values.end());
    int n_uniq = std::unique(values.begin(), values.end()) - values.begin();
    
    expect_true(n_uniq == n_features);
  }
}