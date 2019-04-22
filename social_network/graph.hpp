#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <vector>
#include <set>
#include <cstdint>
#include <algorithm>

enum class Result : std::uint32_t
{
    result_ok,
    value_not_found,
    source_edge_not_found,
    dest_edge_not_found
};
using tVertexIndex = std::uint32_t;
template<typename COMP>
struct Compare
{
    bool operator()(const COMP& compare_sr, const COMP& compare_dr)const
    {
        return (compare_sr != compare_dr);
    }
};

template<typename TYPE>
class Graph
{
    public:
    
    Graph()=default;
    ~Graph() = default;
    Result AddVertex(const TYPE& value);
    //Result RemoveVertex(const TYPE& value);
    Result AddEdge(const TYPE& source, const TYPE& dest);
    //Result RemoveEdge(const TYPE& source, const TYPE& dest);
    //std::vector<TYPE> GetNaiborVertexs(const TYPE& value);
    //std::vector<TYPE> GetEdgedVertexs(const TYPE& value);
    
    private:
    
    std::pair<Result,tVertexIndex> GetVertextIndex(const TYPE& value);
    
    std::map<tVertexIndex,TYPE> vertex_list_;
    std::map<tVertexIndex,std::set<tVertexIndex>> adjucent_edge_;
};

template<typename TYPE>
Result Graph<TYPE>::AddVertex(const TYPE& value)
{
    tVertexIndex end_index = 0;
    
    if(vertex_list_.size() != 0)
    {
        auto end_pos = vertex_list_.crbegin();
        end_index = (end_pos->first + 1);
    }
    
    vertex_list_.insert(std::make_pair(end_index,value));
    
    return Result::result_ok;
}

template<typename TYPE>
std::pair<Result,tVertexIndex> Graph<TYPE>::GetVertextIndex(const TYPE& value)
{
  Result result = Result::value_not_found;
  tVertexIndex index = 0;

  auto get_value = std::find_if(vertex_list_.cbegin(),vertex_list_.cend(),[&](const auto& index_pair)
                                                            {
                                                                return index_pair.second == value;
                                                                
                                                            });
    if(get_value != vertex_list_.cend())
    {
       result =  Result::result_ok;
       index = get_value->first;
    }

  return std::make_pair(result,index);
}

template<typename TYPE>
Result Graph<TYPE>::AddEdge(const TYPE& source, const TYPE& dest)
{
    tVertexIndex source_vertex_index = 0;
    tVertexIndex dest_vertex_index = 0;
    Result result = Result::dest_edge_not_found;
    std::set<tVertexIndex> edge_list;
    
    auto get_source_index = GetVertextIndex(source);
    auto get_dest_index = GetVertextIndex(dest);
    if((get_source_index.first == Result::result_ok ) && 
    (get_dest_index.first == Result::result_ok))
    {
        source_vertex_index = get_source_index.second;
        dest_vertex_index = get_dest_index.second;
        result = Result::result_ok;
    }
    if(result == Result::result_ok)
    {
        if(adjucent_edge_.find(source_vertex_index) == adjucent_edge_.end())
        {
            edge_list.insert(dest_vertex_index);
            adjucent_edge_.insert(std::make_pair(source_vertex_index, edge_list));
        }
        else
        {
            adjucent_edge_.at(source_vertex_index).insert(dest_vertex_index);
        }
    }
    return result;
}

#endif //GRAPH_H_
