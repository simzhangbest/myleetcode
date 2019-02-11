def createCounter():
    count = 0
    def counter():
        nonlocal count
        count += 1
        return count
    return counter


f = createCounter()
for i in range(10):
    print(f())