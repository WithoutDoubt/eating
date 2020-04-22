1. 服务器连接后，进入虚拟环境

   `export PATH=~/anaconda3/bin:$PATH`

   `source activate new_env`

2. 修改配置文件

   `config` 文件夹中

3. 实验数据

   1. RT 模型参数【之前的】

      - [ ] `input_size=161, d_model=320, output_size=161, h=4, rnn_type="LSTM", ksize=3, n=1, n_level=2, dropout=0.1, emb_dropout=0.1`    第一次
      - [ ] `lstm` 模型 : ``

   2.  `ZRT` 模型参数【】

      - [ ] `input_size=161, d_model=320, output_size=161, h=4, rnn_type="LSTM", ksize=5, n=2, n_level=2, dropout=0.1, emb_dropout=0.1`    第二次
      - [ ] 无 `layernorm`
      - [ ] `lstm`模型 : `d_model , d_model, k_size`

   3.  语音数据：

      `n_fft = 320 , hop_length = 160, win_length = 320`

      应该试试 

      `n_fft = 512 , hop_length = 256, win_length = 512`

   4. mask = ?

      $mask = \sqrt{\frac{y^2}{(y+x)^2}}$

   5. `librosa.magphase()` 返回的值shape是什么样子的

      (d,t)  所以想知道多少帧，返回 .shape[-1]

   6. 

   7. 

      > input_size = 161
      >
      > d_model = 320           每一帧的特征数
      >
      > output_size = 161
      >
      > h = 4                             头数
      >
      > ksize = 3                      3个帧训练一下
      >
      > n = 1                             rnn进行一次
      >
      > n_level = 2                   2层RT
      >
      > dropout = 0.1
      >
      > emb_dropout = 0.1
      >
      > ​    

   8. 

   > 模型：RT
   >
   > 训练epochs: 1200
   >
   > validation ： 
   >
   > 模型参数：
   >
   > optimizer：
   >
   > train_dataset：
   >
   > ​		`musan` 噪声
   >
   > ​		900条语音
   >
   > ​		`snr`：-5 . 0
   >
   > ​		batch_size: 32
   >
   > ​		shuffle ：true		
   >
   > validation: 
   >
   > ​		语音: 50
   >
   > ​		`snr`：-5，0，5

4. 开始训练

   CUDA_VISIBLE_DEVICES=3 python train.py -C config/train/2020_04_03_zrt_musan_32.json5

5. 保存断点

6. 断点继续训练

   <font color=red> 注意修改epoch</font>

   CUDA_VISIBLE_DEVICES=3 python train.py -C config/train/2020_04_03_zrt_musan_32.json5

7. 测试

8. 输入的语音时怎么处理的

   继承了torch的Dataset

   

---

1. 什么叫做 `T-F unit` ？

2. `stft` 处理后的shape？

   `( 1 + n_FFT/2 ,  Frames )`

3.  

---

语音数据处理流程

1. 两个文件中有所有语音文件的路径

2. 将文件路径保存为 两个 list

3. `libraso` 读取 list 中路径 ，获得 `wav` 文件

4. 重载Dataset 类，重写 `__length__( )` 和 `get_item( )` 方法，  得到 dataset

   - 样本数目 为 `clean_wav` 的 数目

   - 样本为 [ noisy_mag , clean_mag, mask, n_frames ]

     - [ ] 随机选取一个 `snr` 

     - [ ] 随机选取一个 noise_data，合成出 noise_y   

       `random.choice(  )`

     - [ ] mode = train 时 ，计算出 clean_mag , noise_mag, noisy_mag, mask ,n_frames

       `shape =  (  1 + n_fft / 2  , n_frames )`

       `shape =  (  1 + n_fft / 2  , n_frames )`

       `shape =  (  1 + n_fft / 2  , n_frames )`

       $IRM =  \sqrt{\frac{|S(t,f)|^2}{|S(t,f)|^2+|N(t,f)|^2}}$   (Ideal Ratio Mask) 理想率值掩蔽。

       $MASK =  \sqrt{\frac{clean^2}{(noise+clean)^2}}$   不知道依据是什么?

     - [ ] mode = validation 时, noisy_y, clean_y, name

     - [ ] mode = test时, noisy_y, name

5. 按照 `collate_fn` 函数 从 dataset中 提取 每一 `batch` 的数据 

   假设 `batch_size = 32 , shape = (257 , * )  `   $* \in [1 , 20)$ 

   - [ ] 每一个batch处理成  list , 每一个都填充为最大帧长度。

   - [ ] 是不是 因为 每一个 batch 里面 单独填充？是的

     [   (1 , 257),                                                                

     ​	 (2, 257),

     ​     (3, 257),        -------pad_sequences--------->  [ 20, 32, 257 ]  ----batch_first----->  [32, <font color=red>20</font>, 257 ]

     ​		....

     ​     (20, 257)

     ]                                                                                    

6. 

[]