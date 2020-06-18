1. audio 的设置

   > n = 1
   >
   > h = 4
   >
   > d_model = 160
   >
   > ksize = 6
   >
   > n_level = 3

2. 什么是 `scores.masked_fill` ？

   就是将 scores 中的true 部分 改为 value 的值

3. 

4. attention

   > 

5. MHPooling 部分的伪代码

   > d_k = d_model // h
   >
   > 将 [B , seq_len, d_model] 变为 [B, seq_len, h, d_k]
   >
   > 

6. 