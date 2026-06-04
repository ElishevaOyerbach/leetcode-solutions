class Solution(object):
    def hasValidPath(self, grid):
        m = len(grid)
        n = len(grid[0])

        dirs = {
            1: [(0,-1),(0,1)],
            2: [(-1,0),(1,0)],
            3: [(0,-1),(1,0)],
            4: [(0,1),(1,0)],
            5: [(0,-1),(-1,0)],
            6: [(0,1),(-1,0)]
        }

        visited = set()
        stack = [(0,0)]

        while stack:
            r,c = stack.pop()

            if (r,c) == (m-1,n-1):
                return True

            if (r,c) in visited:
                continue

            visited.add((r,c))

            for dr,dc in dirs[grid[r][c]]:
                nr = r + dr
                nc = c + dc

                if 0 <= nr < m and 0 <= nc < n:
                    if (-dr,-dc) in dirs[grid[nr][nc]]:
                        stack.append((nr,nc))

        return False