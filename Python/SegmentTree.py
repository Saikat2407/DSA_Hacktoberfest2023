class SegmentTree:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)  

    def build(self, node, start, end):
        if start == end:
            self.tree[node] = self.arr[start]
        else:
            mid = (start + end) // 2
            left_node = 2 * node + 1
            right_node = 2 * node + 2
            self.build(left_node, start, mid)
            self.build(right_node, mid + 1, end)
            self.tree[node] = self.tree[left_node] + self.tree[right_node]

    def query(self, node, start, end, left, right):
        if left > end or right < start:
            return 0
        if left <= start and right >= end:
            return self.tree[node]
        mid = (start + end) // 2
        left_node = 2 * node + 1
        right_node = 2 * node + 2
        left_sum = self.query(left_node, start, mid, left, right)
        right_sum = self.query(right_node, mid + 1, end, left, right)
        return left_sum + right_sum

    def update(self, node, start, end, index, new_value):
        if start == end:
            self.arr[index] = new_value
            self.tree[node] = new_value
        else:
            mid = (start + end) // 2
            left_node = 2 * node + 1
            right_node = 2 * node + 2
            if index <= mid:
                self.update(left_node, start, mid, index, new_value)
            else:
                self.update(right_node, mid + 1, end, index, new_value)
            self.tree[node] = self.tree[left_node] + self.tree[right_node]

    def build_tree(self):
        self.build(0, 0, self.n - 1)

    def query_tree(self, left, right):
        return self.query(0, 0, self.n - 1, left, right)

    def update_tree(self, index, new_value):
        self.update(0, 0, self.n - 1, index, new_value)


# Example usage:
arr = [1, 3, 5, 7, 9, 11]
segment_tree = SegmentTree(arr)
segment_tree.build_tree()
print(segment_tree.query_tree(1, 4))  
segment_tree.update_tree(2, 10)  
print(segment_tree.query_tree(1, 4))  
