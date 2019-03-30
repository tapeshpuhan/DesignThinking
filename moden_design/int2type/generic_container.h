//
// Created by tapeswar on 3/30/19.
//

#ifndef MODEN_DESIGN_GENERIC_CONTAINER_H
#define MODEN_DESIGN_GENERIC_CONTAINER_H

#include <iostream>

template<int TYPE>
struct Int2Type
{
    enum {value = TYPE};
};

template<typename CONTAINER, bool IsPolymorphicClone>
class GenericContainer
{
private:

    void DoOperations(const CONTAINER& type, Int2Type<true>)
    {
        std::cout<<"Polymorfigim"<<std::endl;
    }
    void DoOperations(const CONTAINER& type, Int2Type<false>)
    {
        std::cout<<"Non Polymorfigim"<<std::endl;
    }

public:
    void DoOperations(const CONTAINER& type)
    {

        DoOperations(type, Int2Type<IsPolymorphicClone>());
    }
};

#endif //MODEN_DESIGN_GENERIC_CONTAINER_H
