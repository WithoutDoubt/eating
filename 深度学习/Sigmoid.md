## 激活函数

#### Sigmoid

$$
S(x)=\frac{1}{1+e^{-x}}
$$

$$
S'(x)=\frac{e^{-x}}{(1+e^{-x})^2}=S(x)(1-S(x))
$$

值域（0，1）

![Sigmoid 曲线](https://bkimg.cdn.bcebos.com/pic/c9fcc3cec3fdfc03f23fbf16d73f8794a5c226dc?x-bce-process=image/resize,m_lfit,w_220,h_220,limit_1)



#### tanh

$$
tahx = \frac{sinhx}{coshx}=\frac{e^x-e^{-x}}{e^x+e^{-x}}
$$

$$
(tahx)'=sech^2x =1-tanh^2x
$$

值域：（-1,1）

![640?wx_fmt=png](https://ss.csdn.net/p?https://mmbiz.qpic.cn/mmbiz_png/QY9Ieg3xj8Bv1a74ib0GalrmHAQrEwdsGB4pW8ia0fS6uvJ7QxyNjibK6RCnJRQNBtKNOZOdtKCYicia09qS2UD06Hg/640?wx_fmt=png)



