def a(n, vals):
    if n == 0:
        return 1
    if n == 1:
        return -7

    if not vals[n]:
        vals[n] =  5*a(n-1, vals) + 6*a(n-2, vals)

    return vals[n]


def main():
    values = [0 for i in range(0, 101)]

    values[0] = 1
    values[1] = -7

    n = int(input("Введите n для нахождения a(n):\n"))
    print(f"a({n}) =", a(n, values))


if __name__  == "__main__":
    main()
