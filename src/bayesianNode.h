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
    // Constructor for root nodes (has prior distributions)
    explicit BayesianNode(const std::string& id, const std::vector<double>& priors)
        : Node(id), d_priors(priors) {}
    
    // Constructor for nodes with parents (will need conditional probability table)
    BayesianNode(const std::string& id, size_t num_states)
        : Node(id), d_num_states(num_states) {}

    const std::string& type() const override { return d_type; }
    
    // Accessors
    const std::vector<double>& priors() const { return d_priors; }
    size_t numStates() const { return d_num_states; }
    bool parents() const { return !d_priors.empty(); }

private:
    const std::string d_type = "Bayesian";
    
    // For root nodes
    std::vector<double> d_priors;  // Prior probabilities
    
    // For all nodes
    size_t d_num_states = 0;  // Number of possible states
};
