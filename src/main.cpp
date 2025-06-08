
#include <iostream>
#include <memory>
#include "moving_average_calculator.hpp"

int main() {
  std::cout << "sanity check" << std::endl;

  auto calculator = std::make_unique<MovingAverageCalculator>(static_cast<std::size_t>(3));

  double data = 10.0;
  double moreData = 20.0;
  double evenMoreData = 30.0;
  double soMuchData = 40.0;

  auto movingAverage = calculator->getAverage();
  if (movingAverage.has_value()) {
    std::cout << movingAverage.value() << std::endl;
  } else {
    std::cout << "No sensor data in the queue" << std::endl;
  }

  calculator->add(data);
  calculator->add(moreData);
  calculator->add(evenMoreData);

  movingAverage = calculator->getAverage();
  if (movingAverage.has_value()) {
    std::cout << movingAverage.value() << std::endl;
  } else {
    std::cout << "No sensor data in the queue" << std::endl;
  }

  calculator->add(soMuchData);
  movingAverage = calculator->getAverage();
  if (movingAverage.has_value()) {
    std::cout << movingAverage.value() << std::endl;
  } else {
    std::cout << "No sensor data in the queue" << std::endl;
  }
  return 0;
}

