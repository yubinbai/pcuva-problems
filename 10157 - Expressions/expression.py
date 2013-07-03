'''
Expressions （括号表达式）
PC/UVa IDs: 110604/10157, Popularity: C, Success rate: average Level: 2

// 如何得到相应的递推关系？翻看了 Catalan 数的推导过程得到了一些启发。首先，括号的数目必须是
// 偶数才可能得到合法的表达式，当 n 为奇数时，不能得到任何深度的正确表达式，同时若深度超过 n
// 个括号所能得到的合法表达式的最大深度时，结果也将是 0 。所有深度为 1 的表示式都只有 1 种，假
// 设 T（m，d） 表示括号对数为 m （n = 2 * m），深度不超过 d 的合法括号表达式的总数，则有：
//
// T（0，d） = 1
//
// 对于其他情况，假设 E 是一个深度为 d ，括号对数为 m 的合法表达式，则表达式 E 的最左边的括号
// l 一定和某个右括号 r 配对，他们合在一起把表达式划分为两个合法的括号表达式，在 l 和 r 之间的
// 部分以及 r 右边的部分，即：
//
// E = （X）Y
//
// 假设左边部分有 k 对括号，则右边部分有 n - k - 1 对括号，因为 l 和 r 已经用了一对括号，则括号
// 表达式 X 的深度最大为 d - 1 ，括号表达式 Y 的深度最大为 d 。则括号对数为 m，深度为 d 的合法
// 表达式数量为 T（m，d） - T（m，d - 1）。
//
// T（m，d） = T（0，d - 1） * T（m - 1，d） + T（1，d - 1） * T（m - 2，d） + …… + T（k，
// d - 1） * T（m - k - 1，d），0 <= k <= m - 1。
//
// 看起来像是 Catalan 数的二维版本。
//
// 用于 How Many Pieces of Land? 问题的大数类在这个问题上，显然效率不够高，于是我改进了一下，以
// 10000为基数，数位改用模10000的值，用无符号整数来保存数位。
'''

# exp that have lower or equal depth than 'depth'


def depthLowerSum(pairs, depth, memo):
    if memo[pairs][depth] != -1:
        return memo[pairs][depth]
    if pairs == 0 or depth == 1:
        memo[pairs][depth] = 1
        return 1
    s = 0
    for i in range(pairs):
        s += depthLowerSum(i, depth - 1, memo) * \
            depthLowerSum(pairs - 1 - i, depth, memo)
    memo[pairs][depth] = s
    return s

if __name__ == '__main__':
    f = open('input.txt')
    while True:
        line = f.readline()
        if line == '':
            break
        length, depth = [int(x) for x in line.split()]
        pairs = int(length / 2)
        memo = [[-1 for x in range(depth + 1)] for y in range(pairs + 1)]

        print(depthLowerSum(pairs, depth, memo)
              - depthLowerSum(pairs, depth - 1, memo))
