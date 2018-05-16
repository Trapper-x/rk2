#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>

class Objects {
    std::map<std::string, float> Data;
public:
    Objects() = default;
    
    Objects(const Objects&) = default;
    
    Objects& operator=(const Objects&) = default;
    
    // changing object at a key
    void Add(const std::string& key, const float value) {
        Data[key] = value;
    }
    
    // receiving all keys
    std::set<std::string> Keys() const {
        std::set<std::string> keys;
        
        for (const auto& a : Data)
        {
            keys.insert(a.first);
        }
        
        return keys;
    }
    
    // receiving objects from the key
    float GetFromKey(const std::string& key) const {
        auto it = Data.find(key);
        if (it == Data.end())
            throw std::runtime_error("key not found");
        
        return it->second;
    }
};

class Container {
    std::map<std::string, Objects> Data;
    
    enum class EAction
    {
        FindScheme,
        ReadFields,
        ReadObject
    };
    
public:
    Container() = default;
    
    // receiving object from key
    const Objects& GetObject(const std::string& key) const {
        auto it = Data.find(key);
        if (it == Data.end())
            throw std::runtime_error("key not found");
        
        return it->second;
    }
    
    // deleting one object
    void Erase(const std::string& key)
    {
        auto it = Data.find(key);
        if (it == Data.end())
            return;
        Data.erase(it);
    }
    
    // deleting multipal objects
    void Erase(const std::set<std::string>& keys)
    {
        for (const auto& key : keys) {
            Erase(key);
        }
    }
    
    // adding a new object
    void AddObject(const std::string& key, const Objects& obj)
    {
        if (key == "x")
            throw std::runtime_error("not valid key");
        
        if (Data.find(key) != Data.end())
            throw std::runtime_error("not valid key");
        
        if (!Data.empty())
        {
            auto names = obj.Keys();
            auto exist = Data.cbegin()->second.Keys();
            
            bool right = std::equal(names.begin(), names.end(), exist.begin());
            if (!right)
                throw std::runtime_error("not valid object");
        }
        Data[key] = obj;
    }
    
    void Save(const std::string& filename) const {
        std::ofstream ofs(filename);
        if (Data.empty())
            return;
        
        std::set<std::string> keys = Data.begin()->second.Keys();
        
        
        
    }
};





int main() {
    
}

