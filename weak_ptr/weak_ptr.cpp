/*
 * 1. non-owning weak reference to an object that is managed by std::shared_ptr
 * 
 * 2. std::weak_ptr is used to track the object, and it is converted to 
 *    std::shared_ptr to assume temporary ownership. 
 * 
 * 3. If the original std::shared_ptr is destroyed at this time, the object's 
 *    lifetime is extended until the temporary std::shared_ptr is destroyed as well. 
 * 
 * Observers 
 * use_count : returns the number of shared_ptr objects that manage the object 
 * expired : checks whether the referenced object was already deleted 
 * lock    : creates a shared_ptr that manages the referenced object
 *  owner_before	: provides owner-based ordering of weak pointers 
 * */

#include <iostream>
#include <memory>
 
std::weak_ptr<int> gw;
 
void observe()
{
    std::cout << "use_count == " << gw.use_count() << ": ";
    if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
	std::cout << *spt << "\n";
    }
    else {
        std::cout << "gw is expired\n";
    }
}
 
int main()
{
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
 
        observe();
    }

    observe();
}
