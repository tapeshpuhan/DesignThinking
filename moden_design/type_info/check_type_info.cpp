//
// Created by tapeswar on 3/30/19.
//

#include "check_type_info.h"
#include <map>
#include <memory>
#include <typeindex>
#include <typeinfo>

class StoredShapeObject {
public:
  void SetInstance(const std::shared_ptr<shape> shape) {
    stored_shape_[typeid(*shape)] = shape;
  }

  std::shared_ptr<shape> GetInstance(const std::type_index &info_type) {
    return stored_shape_[info_type];
  }

private:
  std::map<std::type_index, std::shared_ptr<shape>> stored_shape_;
};

int main() {
  std::unique_ptr<shape> obj = std::make_unique<rectangle>();

  std::cout << typeid(*obj).name() << std::endl;

  StoredShapeObject stored_obj;

  stored_obj.SetInstance(std::make_shared<rectangle>());
  stored_obj.SetInstance(std::make_shared<circle>());
  stored_obj.SetInstance(std::make_shared<line>());
  stored_obj.SetInstance(std::make_shared<squair>());
  stored_obj.SetInstance(std::make_shared<point>());

  stored_obj.GetInstance(typeid(point))->ClassName();

  stored_obj.GetInstance(typeid(circle))->ClassName();

  return 0;
}
