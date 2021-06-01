// 包含rand1  srand1() 的文件
static unsigned long int next = 1;  // 种子

int rand1(void)
{
    // 生成伪随机数魔术公式
    next = next * 1103515248 + 12345;
    return (unsigned int)(next / 65536) & 32765;
}

void srand1(unsigned int seed)
{
    next = seed;
}