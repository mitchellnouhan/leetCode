#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cstring>

using namespace std;

const std::string csv = "Name,Parent1,Parent2\n"
    "Chris,Bret,Annie\n"
    "Daphne,Chris,Emily\n"
    "Fred,Chris,Emily\n"
    "Henry,George,Daphne\n"
    "Ivy,George,Daphne\n"
    "Jack,George,Daphne\n";

/**
Assume:
    - No CSV metacharacters ("," or "\n") in the data of the CSV
    - Valid input
    - 1:1 mapping between a person and a name.
        
    1st task: parse this CSV. For each line of data, print "{name} is a child of {parent1} and {parent2}"
*/
vector<string> splitString(const string& input, char delim);


void printCsvLines(const string csv){
    vector<string> lines = splitString(csv, '\n');
    for(int i = 1; i < lines.size(); i++) {
        vector<string> people = splitString(lines[i], ',');
        std::cout << people[0] << " is a child of " << people[1] << " and " << people[2] << std::endl;
    }
}

/**
describe_relationship(name1, name2)

Return a value describing how name1 relates to name2. Valid values:
    - child
    - unknown
    
describe_relationship("Daphne", "Chris") // child
describe_relationship("Fred", "Henry") // unknown
describe_relationship("Foo", "Bar") // unknown
*/
unordered_map<string, vector<string>> child_to_parents;

void pre_proc(){
    vector<string> lines = splitString(csv, '\n');
    for(int i = 1; i < lines.size(); i++) {
        vector<string> people = splitString(lines[i], ',');
        child_to_parents[people[0]] = {people[1], people[2]};
    }
}

bool is_child(const string& name1, const string& name2){
    if(child_to_parents.count(name1) == 0)
        return false;
    
    vector<string> parents = child_to_parents[name1];
    return (name2 == parents[0] || name2 == parents[1]) ? true : false;
}

bool is_parent(const string& name1, const string& name2){
    return is_child(name2, name1);
}

bool dfs(const string& ancestor, const string& child){
    //base cases
    if(ancestor == child){
        return true;
    }
    
    if(child_to_parents.count(child) == 0){
        return false;
    }
    
    //recursive cases
    for(auto const& parent: child_to_parents[child]){
        if(dfs(ancestor, parent)){
            return true;
        }
    }
    return false;
}

bool is_ancestor(const string& name1, const string& name2){
    if(name1 == name2) {
        return false;
    }
    return dfs(name1, name2);
}

bool is_descend(const string& name1, const string& name2){
    return is_ancestor(name2, name1);
}

string describe_relationship(const string& name1, const string& name2){
    char* res = (char*)malloc(sizeof(char) * 10);
    const char* unknown = "unknown";
    const char* child = "child";
    const char* parent = "parent";
    const char* ancestor = "ancestor";
    const char* descendant = "descendant";
    
    pre_proc();
    
    if(is_child(name1, name2)){
        strcpy(res, child);
    }
    else if(is_parent(name1, name2)){
        strcpy(res, parent);
    }
    else if(is_ancestor(name1, name2)){
        strcpy(res, ancestor);
    }
    else if(is_descend(name1, name2)){
        strcpy(res, descendant);
    }
    else{
        strcpy(res, unknown);
    }
    return res;
}


int main(){
   // printCsvLines(csv);
    std::cout << describe_relationship("Daphne", "Chris") << std::endl; // child
    std::cout << describe_relationship("Chris", "Daphne") << std::endl; // parent
    std::cout << describe_relationship("Daphne", "Annie") << std::endl; // unknown
    std::cout << describe_relationship("Annie", "Daphne") << std::endl; // ancestor
    std::cout << describe_relationship("Chris", "Foo") << std::endl;    // unknown
    std::cout << describe_relationship("Fred", "Henry") << std::endl; // unknown
    std::cout << describe_relationship("Foo", "Bar") << std::endl; // unknown
    return 0;
}

vector<string> splitString(const string& input, char delim) {
    istringstream stream(input);
    vector<string> tokens;
    for (string each; getline(stream, each, delim);) {
        tokens.push_back(each);
    }
    return tokens;
}