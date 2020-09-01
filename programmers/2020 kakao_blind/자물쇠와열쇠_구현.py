def rotate_by_90_degree(a):
    n = len(a)
    result = [[0]* n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[j][n - i -1] = a[i][j]
    return result

def is_open(new_lock, n):
    for i in range(n):
        for j in range(n):
            if new_lock[i + n - 1][j + n - 1] != 1:
                return False
    return True

def solution(key, lock):
    answer = True
    length = len(lock) * 3 - 2
    m = len(key)
    n = len(lock)
    lock_map = [[0] * length for _ in range(length)]
    #setting
    for i in range(n):
        for j in range(n):
            lock_map[i + n - 1][j + n - 1] = lock[i][j]

    for i in range(4): #rotate
        key = rotate_by_90_degree(key)
        for j in range(2 * n -1):
            for k in range(2 * n -1):
                start = [j, k]
                for x in range(m):
                    for y in range(m):
                        lock_map[x + j][y + k] += key[x][y]
                result = is_open(lock_map, n)
                if result:
                    return True
                for x in range(m):
                    for y in range(m):
                        lock_map[x + j][y + k] -= key[x][y]
    
    return False
