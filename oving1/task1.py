# Øving 1 - Oppgave 1

def is_fibonacci_number(n: int) -> bool:
    a = 0
    b = 1
    while b < n: 
        temp = b
        b += a
        a = temp
    return b == n


