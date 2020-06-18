## AN ATTENTION-BASED NEURAL NETWORK APPROACH FOR SINGLE CHANNEL SPEECH ENHANCEMENT

#### 引用：

Hao, Xiang , et al. "AN ATTENTION-BASED NEURAL NETWORK APPROACH FOR SINGLE CHANNEL SPEECH ENHANCEMENT." *Icassp IEEE International Conference on Acoustics* IEEE, 2019.

#### 解决的问题

测试了基于注意力的神经网络结构，以改善语音增强的性能。

we explore the attention-based neural network structures for improving the performance of speech enhancement.

Our work is inspired by the recent success of attention models in various sequence-to-sequence learning tasks, including machine translation, speech recognition and keyword spotting.

It is intuitive to use attention mechanism in speech enhancement: humans are able to focus on a certain region of an audio stream with “high attention” (e.g. the target speech) while perceiving the surrounding audio (e.g., noise or interference) in “low attention”, and then adjust the focal point over time. 

Specifically, we adopt attention mechanism on LSTM-RNN models which have shown superior speech enhancement performances by modeling important sequential information [12]. While the RNN model learns weights of past input features implicitly when predicting enhanced frame, the attention mechanism calculates correlations between past frames and the current frame to be enhanced and give weights to past frames explicitly.  【在语音增强领域使用attention机制是十分显而易见的】

Experiments show that, as compared with the LSTM baseline, the proposed attention approach can consistently achieve better performance in terms of speech quality (PESQ) and intelligibility 

(STOI). More promisingly, the attention-based approach has better generalization ability to unseen noise conditions.



2020_05_05_rt_conv1d_total_musan_32

#### 模型结构

- 系统总览

  我们基于注意力的方法的示意图如图1所示。

  The input $X = [x_1,x_2,...x_t,...x_T]$, where $x_t$ represents the magnitude spectrum of noisy speech at frame $t$ and $T$ represents the total number of frames of a speech segment. 

  Specifically, our system contains three modules: the encoder, the attention mechanism and the generator.

  编码器从输入语音特征x中提取高级特征表示h：
  $$
  h^Q,h^K=Encoder(x)
  $$
  其中$h^Q$和$h^K$分别是 query 和 key[26]。

  在我们的工作中，我们采用`LSTM`作为<font color=red>encoder</font>，该encoder具有强大的顺序建模能力，从而在语音增强方面具有出色的性能[12]。

  Then the attention mechanism takes the **query** and **key** as input and forms a fixed-length context vector:
  $$
  c_t = Attention(h^K,h_t^Q)
  $$
  Finally, the enhanced speech $y$ is the output of the generator which takes the context vector $c_t$, the noisy speech $x_t$ and the encoder’s output $h^Q_t$ as inputs:
  $$
  y_t = Generator(c_t, h_t^Q,x_t)
  $$
  We detail the encoder, the attention mechanism and the generator in the following subsections.

- Encoder

  explore two different structures for the encoder : *expanded* and *stacked*

  $x_t$ is first fed into a fully-connected layer
  $$
  \hat{x_t}= tanh(W_sx_t+b_s)
  $$
  Then , $\hat{x_t}$ is regarded as the input of the LSTM cell and 
  $$
  h_t^K=f(\hat{x_t})
  $$
  where $f(\cdot)$ represents function of LSTM cell and $h_t^K$ is the output of LSTM cell. Through the same process, we can get the output $h_t^Q$ as well.

  Differently, in the <font color=red>stacked encoder</font> as shown in Fig 2(b) , $h_t^Q$ is calculated as 
  $$
  h_t^Q = f(h_t^K)
  $$
  所以：stacked 结构 和 expanded 结构 就是 $h_t^Q$ 的输入不一样。

- Attention Mechanism

  Recall that the attention mechanism forms a context vector $c$ that contains the information of key $h^K$.

  Notably , the attention mechanism can use both past and future frames of a time sequence. 

  In practice, we usually treat speech enhancement as a casual problem, or we only use the past frames to avoid any latency.

  Here we use two strategies : casual dynamic attention and causal local attention.

  Specifically, in the former, if we denoise a frame , $x_t$ , we calculate attention weights using $[x_1,...,x_t]$. This means we consider all the past frames when we enhance the current frame. 

  If the utterance is too long, the attention weights of many previous frames may be nearly zero.

  So, in the latter, if we enhance the current input $x_t$，we only use $[x_{t-w},...,x_t]$ to calculate the attention weight , where the value of $w$ can be set as a constant.

  Thus , a normalized attention weight $\alpha$ is learned:
  $$
  \alpha_{t,k}=\frac{exp(score(h_k^K,h_t^Q))}{\sum_{k=n}^texp(score(h_k^K,h_t^Q))}
  $$
  when we use caused dynamic attention, n = 1.

  For causal local attention , n = (t-w).

  We follow the correlation calculation in [27], so score$(h_k^K,h_t^Q)=h_k^{KT}Wh_t^Q$. 

  Finally , we compute the context vector as the weighted average of $h_k^K$:
  $$
  c_t = \sum_{k=n}^t\alpha_{tk}h_k^K
  $$

-  Generator

  The output of the speech enhancement system is generated using the context vector $c_t$, the encoder's output $h_t^Q$ and the input feature $x_t$, Given $c_t$ and $x_t$ , we first learn an enhancement vector $e_t$:
  $$
  e_t = tanh(W_e[c_t;h_t^Q] + b_e)
  $$
  where the $[\cdot;\cdot]$ denotes the concatenation of two vectors. Finally, similar to [28], we form a hidden mask  of the input feature $x_t$, and the final enhanced speech $y_t$ is 
  $$
  y_t = x_t \odot sigmoid(W_me_t + b_m)
  $$

#### 实验

数据集

- [ ] noise dataset : Musan corpus
- [ ] snr-list : {0 , 5, 10, 15, 20}
- [ ] clean : 21407 【怀疑是希尔贝尔数据集】
- [ ] train : 13407
- [ ] validation：4000
- [ ] test : 3000
  - [ ] Test-0 : Musan         {0, 20}  
  - [ ] Test-1 : Musan         {0, 20}                     another set of speakers
  - [ ] Test-2 : Musan         {-5, 0}
  - [ ] Test-3 : CHIME 3      {0 , 20}
  - [ ] Test-4 : CHIME 3      {-5 , 0}

<font color=red>语音数据设置</font>

- [ ] sampling rate : 16kHz
- [ ] `n_fft` ：512
- [ ] overlap : 128

对比实验

- [ ] `OM-LSA` 
- [ ] `LSTM-RNN` :  128 / 256 / 512 cells  【两层】
- [ ] encoder ：expanded  /  stacked
- [ ] attention w

学习目标以及loss

- [ ] loss : MSE

实验参数

- [ ] batch_size = 128
- [ ] lr = 0.0005

#### 实验测试

- [ ] `PESQ` :

- [ ] `STOI` :

- [ ] 结论：在 Test-0 测试集中的测试

  <font color=red>stacked 和 expanded</font>

  stacked的表现更好

  0.018   和 0.001 的提升

  <font color=red>local 和 global</font>

  local 的 好一点

  0.007 和 0.001 的提升

  ![1587115111932](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1587115111932.png)

  test-4 的表现 提升很大 0.173  0.025

---

#### 可以参考的地方

实验部分的描述：

- [ ] Datasets

- [ ] Experimental Setups

  The sampling rate of the speech files is 16 kHz. We use short-time Fourier transform (`STFT`) to extract the spectrum from each speech utterance. 

  A `Hanning` window with 512 points and overlap interval of 128 are used. The fast Fourier transform (`FFT`) is taken at 512 points and the first 257 `FFT` points are used as our spectral feature. Hence for all neural networks in this paper, the input and the output are both magnitude spectrum with 257 dimensions. In the evaluation stage, we combine the output of neural network and phase information calculated from the corresponding noisy speech and use inverse Fourier transform (`IFT`) to get the enhanced wave file

  We compare our approach with `OM-LSA` [31] and an `LSTM` approach without attention mechanism. Here as a typical statistical method, `OM-LSA` is treated as the baseline. <font color=red>The LSTM has two layers</font> and each layer has 128/256/512 cells. 

  Note that in order to make performance comparison when the models have similar size of parameters, the cell size of the` LSTM` encoder in the proposed attention approach is set to 112/224/448, accordingly. 

  These models are initialized with the normalized initialization and trained using Adam [32]. 

  The loss function used is mean square error (`MSE`). 

  All parameters are learned automatically when we train the neural network. 

  The learning rate is set to 0.0005 at the beginning and decays with a rate of 0.5 when the loss of current epoch is greater than the previous epoch. 

  The batch size is 128. Dropout regularization is also used [33]. 

  Perceptual evaluation of speech quality (`PESQ`) and short-time objective intelligibility (`STOI`) are used as evaluation criteria. 

实验设计

- [ ] 

- [ ] 对比实验 是 lstm 
  - [ ] 两层
  - [ ] input = 161
  - [ ] hidden_size = 1024
  - [ ] `FFN` = [1024 ,161]
- [ ] 加 $\alpha$ 
- [ ] 加 local-rnn
- [ ] 对比实验 是 

clean and noisy : 0.6892547129575866  数据个数400
clean and denoisy : 0.7658901753075614
clean and noisy : 1.5730522310733794
clean and denoisy : 2.2447589480876924