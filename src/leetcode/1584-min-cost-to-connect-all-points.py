from typing import List, Dict, Tuple

Weight = int
Point = Tuple[int, int]
Edge = Tuple[int, Point, Point]


class UnionFind:
    pi: Dict[Point, Point]
    rank: Dict[Point, int]

    def __init__(self, points: List[List[int]]):
        self.pi = {}
        self.rank = {}
        for point in points:
            x = point[0]
            y = point[1]
            self.pi[(x, y)] = (x, y)
            self.rank[(x, y)] = 0

    def union(self, u: Point, v: Point):
        ru = self.find(u)
        rv = self.find(v)
        if ru == rv:
            return
        if self.rank[ru] > self.rank[rv]:
            self.pi[rv] = ru
        else:
            self.pi[ru] = rv
            if self.rank[ru] == self.rank[rv]:
                self.rank[rv] += 1

    def find(self, p: Point):
        if p != self.pi[p]:
            self.pi[p] = self.find(self.pi[p])
        return self.pi[p]


def kruskal(edges: List[Edge], uf: UnionFind):
    x = []
    edges.sort(key=lambda edge: edge[0])
    for w, u, v in edges:
        if uf.find(u) != uf.find(v):
            x.append((w, u, v))
            uf.union(u, v)
    return x


def mccp(points: List[List[int]]) -> int:
    npts = len(points)
    uf = UnionFind(points)
    edges = []
    for i in range(npts):
        x1 = points[i][0]
        y1 = points[i][1]
        for j in range(i + 1, npts):
            x2 = points[j][0]
            y2 = points[j][1]
            dist = abs(x1 - x2) + abs(y1 - y2)
            edges.append((dist, (x1, y1), (x2, y2)))
    x = kruskal(edges, uf)
    total = sum(w for w, _, _ in x)
    return total
