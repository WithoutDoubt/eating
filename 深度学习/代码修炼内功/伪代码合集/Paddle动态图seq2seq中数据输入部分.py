"""
vocab-dic 保存 { 字 ：id }

函数 ： _para_file_to_ids
    src_data = []  文字存储为数字
    tar_data = []

函数:控制src new的长度

函数：raw_data
    src_vocab 制作字典
    tar_vocab 制作字典

    制作数据集 train test eval

函数：get_data_iter
 

    data_len = src 的长度
    index 列表，长度为data_len 

    如果 mode 是 train , 随机打乱index

    扩充数据 pad

    b_src = [] 存储 (src_data , tar_data)
    如果 b_src= batch_size * cache_num  缓存数




常用API

yield : python中的生成器 

"""
