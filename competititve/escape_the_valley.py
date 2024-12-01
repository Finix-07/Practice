def maximum_sum(n, k, grid):
    pairs = []
    
    # Consider horizontal pairs (i, j) and (i, j+1) in each row
    for i in range(n):
        for j in range(2):  # Only need to check (j) and (j+1) in the row
            pairs.append((grid[i][j] + grid[i][j+1], i, j, "H"))
    
    # Consider vertical pairs (i, j) and (i+1, j) in each column
    for i in range(n-1):
        for j in range(3):
            pairs.append((grid[i][j] + grid[i+1][j], i, j, "V"))
    
    # Sort pairs by the value sum in descending order
    pairs.sort(reverse=True, key=lambda x: x[0])
    
    used = [[False] * 3 for _ in range(n)]  # To track used cells
    total_sum = 0
    placed_tiles = 0
    
    for value, i, j, direction in pairs:
        # Check if the tile is available to be placed
        if direction == "H" and j < 2 and not used[i][j] and not used[i][j+1]:
            total_sum += value
            used[i][j] = used[i][j+1] = True
            placed_tiles += 1
        elif direction == "V" and not used[i][j] and not used[i+1][j]:
            total_sum += value
            used[i][j] = used[i+1][j] = True
            placed_tiles += 1
        
        # Stop if we've placed `k` tiles
        if placed_tiles == k:
            break
    
    return total_sum

# Input reading
n, k = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# Output the result
print(maximum_sum(n, k, grid))
