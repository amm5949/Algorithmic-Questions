from collections import defaultdict, deque

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n, k = int(data[0]), int(data[1])
    words = data[2:2+n]
    
    if n == 1:
        print(words[0])
        return

    graph = defaultdict(deque)
    in_degree = defaultdict(int)
    out_degree = defaultdict(int)
    all_nodes = set()

    for word in words:
        prefix = word[:-1]
        suffix = word[1:]
        graph[prefix].append(suffix)
        out_degree[prefix] += 1
        in_degree[suffix] += 1
        all_nodes.add(prefix)
        all_nodes.add(suffix)
    
    start = None
    end = None

    for node in all_nodes:
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
        start = next(iter(all_nodes))
    
    stack = [start]
    path = []
    while stack:
        node = stack[-1]
        if graph[node]:
            stack.append(graph[node].popleft())
        else:
            path.append(stack.pop())
    
    if len(path) != n + 1:
        print(-1)
        return
    
    path = path[::-1]
    answer = path[0]
    for i in range(1, len(path)):
        answer += path[i][-1]
    
    print(answer[:n])

# Example usage:
solve()
