#ifndef GREEDYBESTFIRSTSEARCH_H_INCLUDED
#define GREEDYBESTFIRSTSEARCH_H_INCLUDED

#include "Extended/SearchingAlgorithm.h"

class GreedyBestFirstSearch : public SearchingAlgorithm {
    private:
        priority_queue<vvt, vector<vvt>, cmp> open;
           
        void checkChild(int, int, int, int);

    public:
        GreedyBestFirstSearch(vvt);
        bool execute();
};

GreedyBestFirstSearch::GreedyBestFirstSearch(vvt current_state) {
    this->current_state = current_state;
    n = current_state.size();
}

void GreedyBestFirstSearch::checkChild(int i, int j, int x, int y) {
    const vvt dad = current_state;
    swap(current_state[i][j], current_state[i+x][j+y]);
    if(!appear.count(current_state)) {
        open.push(current_state);
        father[current_state] = dad;
        appear[current_state] = 1;
        evaluate(current_state);
    }
    swap(current_state[i][j], current_state[i+x][j+y]);   
}

bool GreedyBestFirstSearch::execute() {
    open.push(current_state);
    appear[current_state] = 1;
    evaluate(current_state);

    bool found = true;
    while(found) {
        if(open.empty()) {
            found = false;
            break;
        }
        current_state = open.top();
        open.pop();
    
        if(checkCurrentState()) break;
        
        else generateChild();
        
    }
    return found;
}

#endif