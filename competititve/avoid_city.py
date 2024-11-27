from collections import deque, defaultdict

def find_shortest_path(n, m, source, target, cursed, roads):
    # If source or target is cursed, return -1 immediately
    if cursed[source] == 1 or cursed[target] == 1:
        return -1

    # Build the adjacency list for the graph
    graph = defaultdict(list)
    for u, v in roads:
        # Only add edges between non-cursed cities
        if cursed[u] == 0 and cursed[v] == 0:
            graph[u].append(v)
            graph[v].append(u)

    # BFS to find the shortest path
    queue = deque([(source, 0)])  # (current city, distance from source)
    visited = set()
    visited.add(source)

    while queue:
        current, dist = queue.popleft()

        if current == target:
            return dist

        for neighbor in graph[current]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append((neighbor, dist + 1))

    # If we reach here, no path exists
    return -1

# Input reading
n, m = map(int, input().split())
source, target = map(int, input().split())
cursed = list(map(int, input().split()))
roads = [tuple(map(int, input().split())) for _ in range(m)]

# Output the result
print(find_shortest_path(n, m, source, target, cursed, roads))
