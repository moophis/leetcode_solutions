/*
 * There are N gas stations along a circular route, 
 * where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs 
 * cost[i] of gas to travel from station i to its next station (i+1). 
 * You begin the journey with an empty tank at one of the gas stations.
 * 
 * Return the starting gas station's index if you can travel
 * around the circuit once, otherwise return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 */
 
/* 
 * The intuition is that:
 * 1) if the net residual gas (sum(gas[i] - cost[i])) < 0, that means
 *    the gas absolutely cannot sustain the whole tour; just return -1;
 * 2) if the net residual gas >= 0, we are guaranteed a start station
 *    from which we can pass the circuit. Now the work is to find this
 *    point. This point should not be within the sub-path whose net gas
 *    residue is below zero.
 */
 
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.empty() || cost.empty() || gas.size() != cost.size())
            return -1;
            
        int total_cost = 0, cur_cost = 0, index = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_cost += gas[i] - cost[i];
        }
        if (total_cost < 0)
            return -1;
            
        for (int i = 0; i < gas.size(); i++) {
            cur_cost += gas[i] - cost[i];
            if (cur_cost < 0) {
                index = i + 1;   // the previous path should be dropped
                cur_cost = 0;
            }
        }  
        return index;
    }
};
