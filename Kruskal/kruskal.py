# Name : Divay Mohan
# implementaion using disjoint set concept
global id
id = [i for i in range(0, 10000)]


def root(x):
    while id[x] != x:
        id[x] = id[id[x]]
        x = id[x]
    return x


def union(x, y):
    p = root(x)
    q = root(y)
    id[p] = id[q]
    return


def kruskal(pair, edges, vertex):
    #count = 0
    # sort the edges with respect to their weights in increasing order
    pair1 = sorted(pair, reverse=True)
    # initializing minimum cost to 0
    minimumCost = 0
    # pop edges one by one
    for i in range(0, edges):
        t = pair1.pop()
        w = t[0]
        x = t[1][0]
        y = t[1][1]
        if(root(x) != root(y)):
            #count = count + 1
            minimumCost = minimumCost+w
            print("edge:({} {})".format(x, y))
            union(x, y)

    return minimumCost


# given graph
# edges
edges = 6
# vertex
vertex = 5
# set(weight,(x,y))
pair = set(((5, (1, 2)), (4, (2, 5)), (6, (2, 3)),
            (3, (5, 3)), (1, (3, 4)), (2, (5, 4))))

# getting mincost using kruskal
mincost = kruskal(pair, edges, vertex)
# printing minimumcost
print("MiniMumcost id :: {}".format(mincost))
