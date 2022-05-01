// Segment Tree

int f(int node, int node_low, int node_high, int query_low, int query_high) {
    if (query_low <= node_low && node_high <= query_high) {
        return tree[node];
    }
    if (node_high < query_low || query_high < node_low) {
        return 0;
    }

    int last_in_first = (node_high + node_low)/2;

    return f(2*node, node_low, last_in_first, query_low, query_high) + 
    f(2*node + 1, last_in_first + 1, node_high, query_low, query_high);
}

problem 

https://cses.fi/paste/6277b99f0a975a6d3b5665/
