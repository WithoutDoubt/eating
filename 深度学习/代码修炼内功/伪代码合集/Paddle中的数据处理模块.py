"""
TRAIN_DIR = './data/训练集地址'
TEST_DIR = './data/测试集地址'

train_file = (训练集路径下的文件和文件夹列表)
test_file = (测试集路径下的文件和文件夹列表)

print (有多少条训练语句)
print (有多少条测试语句)

列表 train_labels = []  存储[path, label]对象
列表 x_train = []       存储训练集 输入数据 mag
列表 y_train = []       存储训练集 输出数据 label

将train_labels 处理为表格，行列为[file , label]  存储为csv文件


x_train 按行堆叠
y_train 存为numpy的数组


打印 x_train , y_train 的维度
存储为 npy文件

test_files = [] 测试文件名称列表

x_test = [] 存储测试输入文件
x_test 按行堆叠 存储为 npy


# 相关 的 API

a = os.listdir(path)       # 用于返回指定的文件夹包含的文件或文件夹的名字的列表
path = os.path.join(DIR, filename)  # 返回路径地址
pandas.DataFrame(data, columns)  # 处理成表格
pandas 中 to_csv(' ', index=False)  # 不保留为行索引
numpy.vstack()  # 按 行堆叠为一个新数组
numpy.array(y_train)  # 创建为numpy中的 数组
np.save('./data/x_train.npy', x_train)  # 存储为npy 文件

"""


from utils.utils import wav2mfcc
import pandas as pd
import numpy as np
import sys
import os
if os.path.exists('/home/aistudio/external-libraries'):
    sys.path.append('/home/aistudio/external-libraries')


TRAIN_DIR = './data/train'
TEST_DIR = './data/test'

train_files = os.listdir(TRAIN_DIR)
test_files = os.listdir(TEST_DIR)
print('num of train files: %d' % len(train_files))
print('num of test files: %d' % len(test_files))

train_labels = []
x_train = []
y_train = []

for tfile in train_files:
    # {FOLD}-{CLIP_ID}-{TAKE}-{TARGET}.wav
    label = tfile.split('-')[-1].split('.')[0]
    label = int(label)
    path = os.path.join(TRAIN_DIR, tfile)
    train_labels.append([path, label])
    # mfcc (32, 431)
    mfcc = wav2mfcc(path, n=64)
    mfcc = mfcc.reshape((1,) + mfcc.shape)
    x_train.append(mfcc)
    y_train.append(label)

train_labels = pd.DataFrame(train_labels, columns=['file', 'label'])
train_labels.to_csv('./data/train_labels.csv', index=False)

x_train = np.vstack(x_train)
y_train = np.array(y_train)

print(x_train.shape, y_train.shape)
np.save('./data/x_train.npy', x_train)
np.save('./data/y_train.npy', y_train)

# 0-399
test_files = ['%d.wav' % i for i in np.arange(400)]

x_test = []

for tfile in test_files:
    # {ID}.wav
    path = os.path.join(TEST_DIR, tfile)
    # mfcc (32, 431)
    mfcc = wav2mfcc(path, n=64)
    mfcc = mfcc.reshape((1,) + mfcc.shape)
    x_test.append(mfcc)

x_test = np.vstack(x_test)

print(x_test.shape)
np.save('./data/x_test.npy', x_test)
