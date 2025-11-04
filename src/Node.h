// Does the same as '#ifndef NODE_H ... #define NODE_H ... #endif'
// Compiler tracks physical file intead of being text based like #ifndef
// Avoids potential naming issues with dupilicated file names like src/Node.h and util/Node.h 
#pragma once

#include <string>
#include <vector>

class Node {
// Node and derived classes can access
protected:
    std::vector<Node*> d_parents;
    std::vector<Node*> d_children;

    // Prevents implicit converion
    // Typically always use for single-parameter constructors
    explicit Node(const std::string& id) : d_id(id) {}

// Everyone can access
public:
    // Allows derived classes to overide base class
    virtual ~Node() = default;

    // Pure virtual - must be implemented by derived class
    virtual const std::string& type() const = 0;

    const std::string& id() const { return d_id; }
    const std::vector<Node*>& parents() { return d_parents; }
    const std::vector<Node*>& children() { return d_children; }

// Node can access
private:
    const std::string d_id;

};