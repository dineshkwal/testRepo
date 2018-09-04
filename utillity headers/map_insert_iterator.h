#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

template <typename Container>
class map_insert_iterator
{  
public:
    using iterator_category = std::output_iterator_tag;

    explicit map_insert_iterator(Container& container)
        : mContainer(container)
    {
    }
    
    map_insert_iterator& operator=(const typename Container::value_type& value)
    {
        mContainer.insert(value);
        return *this;
    }
    
    map_insert_iterator& operator* () { return *this; }
    map_insert_iterator& operator++ () { return *this; }

private:
    Container& mContainer;  
};

template <typename Container>
map_insert_iterator<Container> map_inserter(Container& container)
{
    return map_insert_iterator<Container>(container);
}

// test code
int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};
    
    std::map<int, int> elems;
    
    // fancier way
    std::transform(begin(v), end(v), map_inserter(elems), [](const auto& item) { 
        static int index = 0; 
        return std::make_pair(item, index++); 
    });
    
    // easy way
    // for (size_t i = 0; i < v.size(); ++i)
    // {
    //     elems.emplace(v[i], i);
    // }
        
    for (const auto& elem : elems)
    {
        std::cout << "{" << elem.first << ", " << elem.second << "}" << "\n";
    }
}