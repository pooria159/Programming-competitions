n = int(input())
towers = [list(map(int, input().split()))[1:] for _ in range(n)]
blocks = []
for t in towers:
    blocks.extend(t)
blocks.sort()
for i in range(len(towers)):
    towers[i] = [(block, blocks.index(block)) for block in towers[i]]
splits = 0
for tower in towers:
    for i in range(len(tower) - 1):
        if (tower[i + 1][1] - tower[i][1]) != 1:
            splits += 1
merges = n + splits - 1
print(splits, merges)