WHITE = 0
GREY = 1
BLACK = 2

def depth_first_search(vertices, adjacency_list):
    visited = {v: WHITE for v in vertices}
    for vertex in vertices:
        depth_first_search_visit(vertex, adjacency_list, visited)

def depth_first_search_visit(source, adjacency_list, visited):
    """Run a depth first search from `source` on a directed graph.
    """
    if visited[source] is not WHITE:
        return 1
    
    ## Discovered 'source'   
    visited[source] = GREY
    ## Pre-Compute Here
    count = 0

    ## Depth First Tree Computations:
    for node in adjacency_list[source]:
        ## Computation on each Neighbor Depth First Tree 
        count += depth_first_search_visit(node, adjacency_list, visited)
    
    ## Post-Compute Here
    ## Finished 'source'
    visited[source] = BLACK
    ## Return Computation
    return count