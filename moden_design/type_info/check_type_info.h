//
// Created by tapeswar on 3/30/19.
//

#ifndef MODEN_DESIGN_CHECK_TYPE_INFO_H
#define MODEN_DESIGN_CHECK_TYPE_INFO_H

#include <iostream>

class shape {
public:
  virtual void ClassName() = 0;
};

class rectangle : public shape {
public:
  void ClassName() override { std::cout << "rectangel" << std::endl; }
};

class circle : public shape {
public:
  void ClassName() override { std::cout << "circle" << std::endl; }
};

class line : public shape {
public:
  void ClassName() override { std::cout << "line" << std::endl; }
};

class squair : public shape {
public:
  void ClassName() override { std::cout << "squair" << std::endl; }
};

class point : public shape {
public:
  void ClassName() override { std::cout << "point" << std::endl; }
};

#endif // MODEN_DESIGN_CHECK_TYPE_INFO_H
