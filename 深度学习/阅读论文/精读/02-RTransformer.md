#### 模型结构

- `LocalRNN`

  `self.rnn = nn.LSTM(output_dim, output_dim, batch_first=True)` 这是构造 `lstm`

  Linear(output ,output, )
  $$
  h_t= LocalRNN(x_{t-(M-1)},x_{t-(M-2)},...,x_t)
  $$

  $$
  h_1,h-2，...，h_N = LocalRNN(x_1，x_2,...,x_N)
  $$

  

- Multi-Head
  $$
  \begin{aligned}
  u_t &= MultiHeadAttention(h_1,h_2,...,h_t)
  \\&=Concatenation(head_1(h_t),head_2(h_t),...,head_k(h_t))W^o
  \end{aligned}
  $$
  
  $$
    \begin{aligned}
    {\alpha_1,\alpha_2,\cdots,\alpha_n} &= Softmax({\frac{<q,k_1>}{\sqrt{(d_k)}},\frac{<q,k_2>}{\sqrt{(d_k)},\cdots,\frac{<q,k_n>}{\sqrt{(d_k)})\\
    
  \end{aligned}
  $$
  
  
  
- `FeedForward`
  $$
  FeedForward(m_t)=max(0,u_tW_1+b_1)W_2+b_2
  $$

- residual + layernorm

N层R-Transformer的总体体系结构,for the $i^{th}$ layer
$$
h_1^i,h_2^i,\cdots,h_T^i = LocalRNN(x_1^i,x_2^i,\cdots,x_T^i)\\
\hat{h}_1^i,\hat{h}_2^i,\cdots,\hat{h}_T^i=LayerNorm(h_1^i+x_1^i,h_2^i+x_2^i,\cdots,h_T^i+x_T^i)\\
u_1^i,u_2^i,\cdots,u_T^i=MultiHeadAttention(\hat{h}_1^i,\hat{h}_2^i,\cdots,\hat{h}_T^i)\\
\hat{u}_1^i,\hat{u}_2^i,\cdots,\hat{u}_T^i=LayerNorm(u_1^i+\hat{h}_1^i,u_2^i+\hat{h}_2^i,\cdots,u_T^i+\hat{h}_T^i)\\
m_1^i,m_2^i,\cdots,m_T^i=FeedForward(\hat{u}_1^i,\hat{u}_2^i,\cdots,\hat{u}_T^i)\\
x_1^{i+1},x_2^{i+1},\cdots,x_T^{i+1}=LayerNorm(m_1^i+\hat{u}_1^i,m_2^i+\hat{u}_2^i,\cdots,m_T^i+\hat{u}_T^i)
$$
实现：

x = linear(x)

x = rt(x)

x = 

x = sigmoid(x)