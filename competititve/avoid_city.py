'''

A. Avoid Cities
time limit per test
1.5 seconds
memory limit per test
256 megabytes

There are N
cities with M

bi-directional roads between them. You want to travel from a given source city to target city. But there are some cities that you cannot visit because they are cursed.

Find the smallest number of roads that you should take to complete your travel and output it. If it is not possible to do so output −1.

1≤N≤105
0≤M≤2×105

Input

The first line contains two integers N
and M

denoting the number of cities and the number of roads respectively.

The second line contains two integers: source and target.

The third line contains N
integers which are either 0 or 1 denoting whether each city is cursed or not. (1

means that the city is cursed.)

Finally, there are M
lines containing 2 integers each u and v denoting that there is a road between city u and city v

.
Output

Output the smallest number of roads that you should take to complete your travel and output it. If it is not possible to do so output −1

.
Example
Input

5 5
0 2
0 1 0 0 0
0 1
1 2
0 3
3 4
4 2

Output

3


'''







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
