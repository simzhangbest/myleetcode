"""
线性表结构
"""


class LinearMap(object):

    def __init__(self):
        self.items = []

    # 往表中添加元素
    def add(self, k, v):
        self.items.append((k, v))

    # 线性方式查找元素
    def get(self, k):
        for key, value in self.items:
            if key == k:  # 键存在，返回值，否则抛出异常
                return value
        raise KeyError


'''
我们可以在使用add添加元素时让items列表保持有序，而在使用get时采取二分查找方式，时间复杂度为O(log n)。 
然而往列表中插入一个新元素实际上是一个线性操作，所以这种方法并非最好的方法。
同时，我们仍然没有达到常数查找时间的要求。
'''

'''
将总查询表分割为若干段较小的列表，比如100个子段。
通过hash函数求出某个键的哈希值，再通过计算，得到往哪个子段中添加或查找。
相对于从头开始搜索列表，时间会极大的缩短。
'''


class BetterMap(object):
    # 利用LinearMap对象作为子表，建立更快的查询表
    def __init__(self, n=100):
        self.maps = []  # 总表格
        for i in range(n):  # 根据n的大小建立n个空的子表
            self.maps.append(LinearMap())

    def find_map(self, k):  # 通过hash函数计算索引值
        index = hash(k) % len(self.maps)
        return self.maps[index]  # 返回索引子表的引用

    # 寻找合适的子表（linearMap对象）,进行添加和查找
    def add(self, k, v):
        m = self.find_map(k)
        m.add(k, v)

    def get(self, k):
        m = self.find_map(k)
        return m.get(k)


    '''
    重点关注 add 部分，该函数检查元素个数与BetterMap的大小，如果相等，则“平均每个LinearMap中的元素个数为1”，然后调用resize方法。

resize创建一个新表，大小为原来的两倍，然后对旧表中的元素“rehashes 再哈希”一 遍，放到新表中。

resize过程是线性的，听起来好像很不怎么好，因为我们要求的hashtable具有常数时间。但是，要知道我们并不需要经常进行重排操作，所以add操作在绝大部分时间中都是常数的，偶然出现线性。由于对n个元素进行add操作的总时间与n成比例，所以每次add的平均时间就是一个常数！

假设我们要添加32个元素，过程如下：

1. 由于初始长度为2，前两次add不需要重排，第1,2次 总时间为 2

2. 第3次add，重排为4，耗时2，第3次时间为 3

3. 第4次add，耗时1　　　　到目前为止，总时间为 6

4. 第5次add，重排为 8，耗时4，第5次时间为5

5. 第6~8次   共耗时3    　　到目前为止，总时间为 6+5+3 = 14

6. 第9次add，重排16，  耗时8，第9次时间为9

7. 第10~16次，共耗时7，　到目前为止，总时间为 14+9+7 = 30

在32次add后，总时间为62的单位时间，由以上过程可以发现一个规律，在n个元素add之后，当n为2的幂，则当前总单位时间为 2n-2，所以平均add时间绝对小于2单位时间。

当n为2的幂时，为最合适的数量，当n变大之后，平均时间为稍微上升，但重要的是，我们达到了O(1)。
    
    '''