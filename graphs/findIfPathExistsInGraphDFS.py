class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        # create an adjacency list
        # starting at src, do a dfs 
        graph = defaultdict(list)
        for edge in edges:
            u, v = edge[0], edge[1]
            graph[u].append(v)
            graph[v].append(u)
        
        visit = [False for _ in range(n)]
        
        def dfs(cur):
            # base cases
            if cur == destination:
                return True
            if visit[cur]:
                return False
            
            # recursive cases
            visit[cur] = True
            for nei in graph[cur]:
                if dfs(nei):
                    return True
            return False
        return dfs(source)

        