#pragma once

#include <iostream>
#include <queue>
#include <cstddef>
#include <optional>

class MovingAverageCalculator {
public:
  MovingAverageCalculator(std::size_t WindowSize) : windowSize_(WindowSize), runningTotal_(0) {
    std::cout << "[MovingAverageCalculator] created with window size: " << WindowSize << "\n";
  }

  void add(const double& data) {

    if (q_.size() >= windowSize_) {
      // capture the front
      double temp = q_.front();
      // minuse front from total
      runningTotal_ = runningTotal_ - temp;
      // pop front
      q_.pop();
      // add value to total
      runningTotal_ = runningTotal_ + data;
      // push value to front
      q_.push(data);
      // update the moving average per window
      movingAverage_ = runningTotal_ / q_.size();

    } else {
      runningTotal_ = runningTotal_ + data;
      q_.push(data);
      movingAverage_ = runningTotal_ / q_.size();
    }
  }

  std::optional<double> getAverage() {

    if (q_.empty())
      return std::nullopt;

    return movingAverage_;
  }

private:
  std::queue<double> q_;
  std::size_t windowSize_;
  double movingAverage_;
  double runningTotal_;
};