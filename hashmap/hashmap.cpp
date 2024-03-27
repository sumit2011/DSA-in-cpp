#include<iostream>
#include<map>
#include<unordered_map>


using namespace std;


int main(){
    //creation
    unordered_map<string ,int> map;

    //insertion
// methid 1 to insert
    pair<string,int> p = make_pair("sumit", 3);
    map.insert(p);

// method 2 to insert
    pair<string, int> p2("kumar", 2);
    map.insert(p2);

// method 3 to insert
    map["test"] = 1;

    cout << map.size() << endl << endl;
    // output-> 3

// what will happen at
    map["test2"] = 2;

    cout << map.size() << endl << endl;
    // output-> 4

// accesing the data in the created map
    cout << map["test2"] << endl;
    cout << map.at("sumit") << endl;

// if data is not present in the map
    // cout << map.at("unknown") << endl;
    // output will be out of range

    cout << map["unknown"] << endl;
    // output will be "0" because it will create a map of "unknown" pointing to "0".

    cout << map.at("unknown") << endl;
    // now for this code output will be zero because the map of unknown has been created.
    
    cout << "size: " << map.size() << endl;
    // output-> 5

    // to check presence
    cout << map.count("bro") << endl;
    // output-> 0 means not present

    cout << map.count("sumit") << endl;
    // output-> 1 means presnt in the map

    // erase
    map.erase("sumit");
    cout<< "size after erasing: " << map.size() <<endl;
    //output-> 4

// accesing all the data in the map
    for(auto i: map){
        cout << i.first << " -> "<< i.second <<endl;
    }

    // using itrator
    unordered_map <string , int> :: iterator it = map.begin();

    while(it != map.end()){
        cout<< it->first <<" -> " << it->second <<endl;
        it++;
    }
// output ->
    // unknown -> 0
    // test -> 1
    // test2 -> 2
    // kumar -> 2
    
    return 0;
}

