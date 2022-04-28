#ifndef BEAMSEARCH_H_INCLUDED
#define BEAMSEARCH_H_INCLUDED

#include "Extended/SearchingAlgorithm.h"

class BeamSearch : public SearchingAlgorithm {
    private:
        int k; // Số state tối đa ở mỗi bậc
        priority_queue<vvt, vector<vvt>, cmp> open;
        queue<vvt> temp;

        void checkChild(int, int, int, int);

    public:
        BeamSearch(vvt, int);
        bool execute(); 
};

BeamSearch::BeamSearch(vvt current_state, int k) {
    this->current_state = current_state;
    this->k = k;
    n = current_state.size();
}

void BeamSearch::checkChild(int i, int j, int x, int y) {
    const vvt dad = current_state;
    swap(current_state[i][j], current_state[i+x][j+y]);
    if(!appear.count(current_state)) {
        // open.push(current_state);
        temp.push(current_state);
        father[current_state] = dad;
        appear[current_state] = 1;
        evaluate(current_state);
    }
    swap(current_state[i][j], current_state[i+x][j+y]);   
}

bool BeamSearch::execute() {
    open.push(current_state);
    appear[current_state] = 1;
    evaluate(current_state);

    bool found = true;
    bool foundAnswer = false;
    while(found) {
        if(open.empty()) {
            found = false;
            break;
        }
        int MIN = min(k, (int)open.size());
        for(int i = 0; i < MIN; i++) {
            current_state = open.top();
            open.pop(); 
            
            if(checkCurrentState()) {
                foundAnswer = true; 
                break;
            }
            
            else generateChild();
        }
        if(foundAnswer) break;
        while(!open.empty()) open.pop();
        while(!temp.empty()) {
            open.push(temp.front());
            temp.pop();
        }
        
    }
    return found;
}

#endif