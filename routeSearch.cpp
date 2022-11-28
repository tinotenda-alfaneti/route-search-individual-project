#include "main.h"

/**
 * precondition: airportCode not equal to null and routes not empty
 * postcondition: a vector of destinations from the given source airport code 
*/
vector<route> getDestinations(string airportCode, unordered_map<string, vector<route>>& routes) {
    vector<route> destinations;

    for (auto route : routes) {
        if (route.first.compare(airportCode) == 0) {
            destinations = route.second;
        } 
    }

    if (destinations.size() == 0) {
        cout << "No Airport Code Found For: " + airportCode + "\n";
    }

    return destinations;
}
/**
 * precondition: start and destinations which will all not be null
 * postcondition: 1 if successful and zero if there is an error
*/
int perfomRouteSearch(string start, string destination) {

    //loading data for routes
    unordered_map<string, vector<route>> routes;
    loadRoutes(routes);

    //creating and adding data to the route structure
    route startPoint;
    startPoint.airportCode = start;
    startPoint.airlineCode = "";
    startPoint.stops = 0;

    node *fNodePtr = new node(startPoint, nullptr);

    deque<node> frontier;
    frontier.push_back(*fNodePtr);
    unordered_set<string> visited;
    visited.insert(startPoint.airportCode);

    while(!frontier.empty()) {

        node poppedRouteNode = frontier.front();
        //creating a pointer to the popped node
        node *nodeptr = new node(poppedRouteNode.curr, poppedRouteNode.prev);
        frontier.pop_front();
        visited.insert(nodeptr->curr.airportCode);
        vector<route> actions = getDestinations(nodeptr->curr.airportCode, routes);
        for (int i = 0; i < actions.size(); i++) {
            //creating new node
            node *newNodePtr = new node(actions[i]);
            newNodePtr->prev = nodeptr;
            
            //checking if created node is in the frontier or visited
            auto it = find(frontier.begin(), frontier.end(), *newNodePtr);
            if(visited.find(actions[i].airportCode) == visited.end() && it == frontier.end()) {

                cout << "Currently at " << newNodePtr->curr.airportCode << " from " << newNodePtr->prev->curr.airportCode << endl;
                if (actions[i].airportCode.compare(destination) == 0) {

                    outputData(newNodePtr);

                    //freeing up memory
                    delete fNodePtr;
                    delete newNodePtr;
                    delete nodeptr;
                    return 0;
                    
                } else {
                    
                    frontier.push_back(*newNodePtr);

                }

            }
        }
    }

    return -1;
}