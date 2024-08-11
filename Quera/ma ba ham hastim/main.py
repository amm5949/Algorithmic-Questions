from collections import defaultdict, deque

def solve():
    n, k = map(int, input().split())
    words = [input().strip() for _ in range(n)]
    
    # Create a graph of k-1 length prefixes to suffixes
    graph = defaultdict(list)
    in_degree = defaultdict(int)
    out_degree = defaultdict(int)
    
    for word in words:
        prefix = word[:-1]
        suffix = word[1:]
        graph[prefix].append(suffix)
        out_degree[prefix] += 1
        in_degree[suffix] += 1
    
    # Check if there is a Eulerian path in the graph
    start = None
    end = None
    for node in set(in_degree.keys()).union(out_degree.keys()):
        if out_degree[node] > in_degree[node]:
            if start is None:
                start = node
            else:
                print(-1)
                return
        elif in_degree[node] > out_degree[node]:
            if end is None:
                end = node
            else:
                print(-1)
                return
    
    if start is None:
        start = words[0][:-1]
    
    # Hierholzer's algorithm to find Eulerian path
    stack = [start]
    path = []
    
    while stack:
        node = stack[-1]
        if graph[node]:  # Ensure there are still edges to follow
            next_node = graph[node].pop()
            stack.append(next_node)
        else:
            path.append(stack.pop())
    
    # Check if we have a valid path length
    if len(path) != n + 1:
        print(-1)
        return
    
    # Reconstruct the answer from the path
    path = path[::-1]
    answer = path[0]
    for i in range(1, len(path)):
        answer += path[i][-1]
    
    # Trim the answer to exactly n characters
    print(answer[:n])

# Example usage:
solve()
