class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.tree = [0] * (2 * self.n)
        self.build(data)

    def build(self, data):
        # Build the tree
        for i in range(self.n):
            self.tree[self.n + i] = data[i]
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = min(self.tree[2 * i], self.tree[2 * i + 1])

    def query(self, l, r):
        # Query the minimum in the range [l, r)
        l += self.n
        r += self.n
        res = float('inf')
        while l < r:
            if l % 2 == 1:
                res = min(res, self.tree[l])
                l += 1
            if r % 2 == 1:
                r -= 1
                res = min(res, self.tree[r])
            l //= 2
            r //= 2
        return res

n, q = map(int, input().split())
a = list(map(int, input().split()))
if(sorted(a)==a):
    for i in range(q):
        l,r=map(int,input().split())
        print(a[l-1])
else:
# Build the segment tree
    seg_tree = SegmentTree(a)

    # Process each query
    for _ in range(q):
        l, r = map(int, input().split())
        print(seg_tree.query(l - 1, r))
