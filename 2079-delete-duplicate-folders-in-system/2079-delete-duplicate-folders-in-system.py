class Solution(object):
    def deleteDuplicateFolder(self, paths):
        from collections import defaultdict

        class Node:
            def __init__(self, name):
                self.name = name
                self.children = {}
                self.serial = ""
                self.to_delete = False

        root = Node("")

        for path in paths:
            node = root
            for folder in path:
                if folder not in node.children:
                    node.children[folder] = Node(folder)
                node = node.children[folder]

        seen = defaultdict(list)

        def dfs(node):
            if not node.children:
                node.serial = ""
                return node.serial
            serials = []
            for child_name in sorted(node.children):
                child = node.children[child_name]
                serials.append(child_name + "(" + dfs(child) + ")")
            node.serial = "".join(serials)
            seen[node.serial].append(node)
            return node.serial

        dfs(root)

        for nodes in seen.values():
            if len(nodes) > 1:
                for node in nodes:
                    node.to_delete = True

        result = []
        stack = [(root, [])]
        while stack:
            node, path_so_far = stack.pop()
            for name, child in node.children.items():
                if not child.to_delete:
                    new_path = path_so_far + [name]
                    result.append(new_path)
                    stack.append((child, new_path))

        return result
