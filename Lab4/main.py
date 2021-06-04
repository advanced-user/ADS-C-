import math


class GraphWeighted:
    def __init__(self, prim_edges, edges, m):
        self.edges = edges
        self.matrix = m
        self.prim_edges = prim_edges

    def kruskal(self):
        sorted_edges = sorted(self.edges, key=lambda x: x[0])
        u = set()
        d = {}
        t = []

        for r in sorted_edges:
            if r[1] not in u or r[2] not in u:
                if r[1] not in u and r[2] not in u:
                    d[r[1]] = [r[1], r[2]]
                    d[r[2]] = d[r[1]]
                else:
                    if not d.get(r[1]):
                        d[r[2]].append(r[1])
                        d[r[1]] = d[r[2]]
                    else:
                        d[r[1]].append(r[2])
                        d[r[2]] = d[r[1]]

                t.append(r)
                u.add(r[1])
                u.add(r[2])

        for r in sorted_edges:
            if r[2] not in d[r[1]]:
                t.append(r)
                gr1 = d[r[1]]
                d[r[1]] += d[r[2]]
                d[r[2]] += gr1

        print(t)

    def arg_min(self, t, s):
        amin = -1
        m = math.inf
        for i, t in enumerate(t):
            if t < m and i not in s:
                m = t
                amin = i

        return amin

    def dijkstra(self):
        n = len(self.matrix)
        t = [math.inf] * n

        v = 0
        s = {v}
        t[v] = 0

        while v != -1:
            for j in self.get_link_v(v):
                if j not in s:
                    w = t[v] + self.matrix[v][j]
                    if w < t[j]:
                        t[j] = w

            v = self.arg_min(t, s)
            if v >= 0:
                s.add(v)

        print(t)

    def get_link_v(self, v):
        for i, weight in enumerate(self.matrix[v]):
            if weight > 0:
                yield i

    def get_min(self, u):
        rm = (math.inf, -1, -1)
        for v in u:
            rr = min(self.prim_edges,
                     key=lambda x: x[0] if (x[1] == v or x[2] == v) and (x[1] not in u or x[2] not in u) else math.inf)
            if rm[0] > rr[0]:
                rm = rr
        return rm

    def prim(self):
        n = 6
        u = {1}
        t = []

        while len(u) < n:
            r = self.get_min(u)
            if r[0] == math.inf:
                break

            t.append(r)
            u.add(r[1])
            u.add(r[2])

        print(t)


# длина, вершина1, вершина2
eds = [(13, 1, 2), (18, 1, 3), (17, 1, 4), (14, 1, 5), (22, 1, 6),
       (26, 2, 3), (22, 2, 5), (3, 3, 4), (19, 4, 6)]

prim_eds = [(math.inf, -1, -1), (13, 1, 2), (18, 1, 3), (17, 1, 4), (14, 1, 5), (22, 1, 6),
            (26, 2, 3), (22, 2, 5), (3, 3, 4), (19, 4, 6)]

matrix = ((0, 3, 1, 3, math.inf, math.inf),
          (3, 0, 4, math.inf, math.inf, math.inf),
          (1, 4, 0, math.inf, 7, 5),
          (3, math.inf, math.inf, 0, math.inf, 2),
          (math.inf, math.inf, 7, math.inf, 0, 4),
          (math.inf, math.inf, 5, 2, 4, 0))

graphWeighted = GraphWeighted(prim_eds, eds, matrix)
print(eds)

graphWeighted.kruskal()
graphWeighted.dijkstra()
graphWeighted.prim()
