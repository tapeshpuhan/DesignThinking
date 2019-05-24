#include <iostream>
#include <string>
#include <vector>

bool IfFound(const std::string& input, const std::vector<std::string>& dist)
{
    bool found = false;
    
    auto index = std::find(cbegin(dist),end(dist),input);
    if(index ! cend(dist))
    {
        found = true;
    }
    return found;
}

std::string FindString(const std::string& input, const std::vector<std::string>& dist)
{
    if(input.length() == 0)
    {
        return "";
    }
    
} 

int main()
{
    return 0;
}
