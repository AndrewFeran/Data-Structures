"""
We are given arrays A, B, C, of sizes a, b, c.
Our goal is linear time complexity of O(a+b+c)
This program runs in 2a+2b+c iterartions, thus the time complexity is linear O(a+b+c)
The same time complexity would be achieved by only calling the function once, passng in the all 3 arrays as arguments.
The reason being you cannot take the min() of 3 arguments without taking them min() twice under the hood
"""
A = [6, 7, 14, 41]
B = [3, 49, 82, 131]
C = [5, 17, 44, 75, 90, 200]

def mergesorted(M, N):
    m = len(M)
    n = len(N)
    out = [None] * (m+n)
    i = 0
    j = 0
    for num in range(0, (m+n)):
        if i >= m:
            out[num] = N[j]
            j += 1
        elif j >= n:
            out[num] = M[i]
            i += 1
        elif M[i] < N[j]:
            out[num] = M[i]
            i += 1
        else:
            out[num] = N[j]
            j += 1

    return out

print(mergesorted(mergesorted(A, B), C))