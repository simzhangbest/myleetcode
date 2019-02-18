def createCounter(count):
    fs= []
    for i in range(1, count):
        def counter():
            return i*i
        fs.append(counter)
    return fs

res= []
res = createCounter(100)
for i in range(99):
    print(res[i]())


