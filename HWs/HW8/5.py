from collections import defaultdict

def min_required_power(n, m, powers, edges):
    adj_list = defaultdict(list)
    for u, v in edges:
        adj_list[u].append(v)
        adj_list[v].append(u)

    country_powers = [(power, i) for i, power in enumerate(powers)]
    country_powers.sort(reverse=True)

    def conquer_country(start_country):
        conquered = [False] * n
        conquered[start_country] = True
        conquest_power = powers[start_country]
        additional_power = 0

        for power, country in country_powers:
            if conquered[country]:
                continue

            if power > conquest_power:
                additional_power += power - conquest_power
                conquest_power = power

            conquered[country] = True
            conquest_power += power

        return additional_power

    return [conquer_country(start) for start in range(n)]

# Input
n, m = map(int, input().split())
powers = list(map(int, input().split()))
edges = [tuple(map(int, input().split())) for _ in range(m)]

# Compute result
result = min_required_power(n, m, powers, edges)

# Output
print(*result)