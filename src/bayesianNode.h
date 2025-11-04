#pragma once
#include <Node.h>
#include <vector>

/* 
---------------------------- Bayesian Network Definition ----------------------------
Let G be a DAG, and p a probability distribution over the variables that comprise the 
nodes of G. Then (G, p) is a Bayesian network if it satisfies the Markov condition.
-------------------------------------------------------------------------------------
*/

class BayesianNode : public Node {
protected:

public:
    // Use explicit with single argument methods to preven implicit conversion
    explicit BayesianNode(const std::string& id, size_t num_states = 1) 
        : Node(id), 
          d_pi(num_states), // TODO: Re-read how we should initialize pi vector
          d_lambda(num_states, 1.0) {} // TODO: Re-read how we should initialize lambda vector

    const std::string& getType() const override { return d_type; }

private:
    std::vector<double> d_pi;
    std::vector<double> d_lambda;
    const std::string d_type = "Bayesian"; 

/*
TODO: Create a Bayes' net validation function using Tarjan's SCC algorithm to ensure no cycles

function Tarjan(Node* node):
    node.visited <- true
    node.index <- indexCounter
    s.push(node)
    for all sucessor in node.succesors do 
        if !node.visited then Tarjan(successor)
        end if
        node.lowlink <- MIN(node.lowlink, successor.lowlink)
    end for
    if node.lowlink == node.index then
        repeat
            successor <- stack.pop()
        until successor == node
    end if
end function
*/

};
