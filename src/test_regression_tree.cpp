#include <testthat.h>
#include "regression_tree.h"


context("RegressionTree hyperparams") {
  
  RegressionTree tr;
  
  test_that("can set max_depth") {
    tr.set_max_depth(10);
    
    expect_true(tr.max_depth == 10);
  }
  
  test_that("can set min_samples_split") {
    tr.set_min_samples_split(9);
    
    expect_true(tr.min_samples_split == 9);
  }
  
  test_that("can set min_samples_leaf") {
    tr.set_min_samples_leaf(99);
    
    expect_true(tr.min_samples_leaf == 99);
  }
  
  test_that("can set max_features") {
    tr.set_max_features(2);
    
    expect_true(tr.max_features == 2);
  }
  
  test_that("can set min_impurity_decrease") {
    tr.set_min_impurity_decrease(9.9);
    
    expect_true(tr.min_impurity_decrease == 9.9);
  }
  
  test_that("can chain hyperparam settings") {
    tr.set_max_depth(9)
      .set_min_samples_split(8)
      .set_min_samples_leaf(7)
      .set_max_features(6)
      .set_min_impurity_decrease(5.1);
    
    expect_true(tr.max_depth == 9);
    expect_true(tr.min_samples_split == 8);
    expect_true(tr.min_samples_leaf == 7);
    expect_true(tr.max_features == 6);
    expect_true(tr.min_impurity_decrease == 5.1);
  }
}