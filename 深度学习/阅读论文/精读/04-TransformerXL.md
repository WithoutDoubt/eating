#### Abstract

Transformers have a potential of learning longer-term dependency, but are limited by a fixed-length context in the setting of language modeling. 

We propose a novel neural architecture Transformer-XL that enables learning dependency beyond a fixed length without disrupting temporal coherence. It consists of a segment-level recurrence mechanism and a novel positional encoding scheme. 

Our method not only enables capturing longer-term dependency, but also resolves the context fragmentation problem. 

As a result, TransformerXL learns dependency that is 80% longer than RNNs and 450% longer than vanilla Transformers, achieves better performance on both short and long sequences, and is up to 1,800+ times faster than vanilla Transformers during evaluation. 

=======

Notably, we improve the state-of-the-art results of bpc/perplexity to 0.99 on enwiki8, 1.08 on text8, 18.3 on WikiText-103, 21.8 on One Billion Word, and 54.5 on Penn Treebank (without finetuning). 

When trained only on WikiText-103, Transformer-XL manages to generate reasonably coherent, novel text articles with thousands of tokens. 

=======

Our code, pretrained models, and hyperparameters are available in both Tensorflow and PyTorch 

Language modeling is among the important problems that require modeling long-term dependency, with successful applications such as unsupervised pretraining (Dai and Le, 2015; Peters et al., 2018; Radford et al., 2018; Devlin et al., 2018). 

However, it has been a challenge to equip neural networks with the capability to model long-term dependency in sequential data. 

=======

****

Recurrent neural networks (RNNs), in particular Long Short-Term Memory (LSTM) networks (Hochreiter and Schmidhuber, 1997), have been a standard solution to language modeling and obtained strong results on multiple benchmarks.

Despite the wide adaption, RNNs are difficult to optimize due to gradient vanishing and explosion (Hochreiter et al., 2001), and the introduction of gating in LSTMs and the gradient clipping technique (Graves, 2013) might not be sufficient to fully address this issue. 

Empirically, previous work has found that LSTM language models use 200 context words on average (Khandelwal et al., 2018), indicating room for further improvement. 

****

=======

On the other hand, the direct connections between long-distance word pairs baked in attention mechanisms might ease optimization and enable the learning of long-term dependency (Bahdanau et al., 2014; Vaswani et al., 2017). 

Recently, Al-Rfou et al. (2018) designed a set of auxiliary losses to train deep Transformer networks for character-level language modeling, which outperform LSTMs by a large margin. 

Despite the success, the LM training in Al-Rfou et al. (2018) is performed on separated fixed-length segments of a few hundred characters, without any information flow across segments. 

As a consequence of the fixed context length, the model cannot capture any longer-term dependency beyond the predefined context length. 

In addition, the fixed-length segments are created by selecting a consecutive chunk of symbols without respecting the sentence or any other semantic boundary. 

Hence, the model lacks necessary contextual information needed to well predict the first few symbols, leading to inefficient optimization and inferior performance. We refer to this problem as context fragmentation. 

**To address the aforementioned limitations of fixed-length contexts, we propose a new architecture called Transformer-XL (meaning extra long).** 

We introduce **the notion of recurrence** into our deep self-attention network. 

In particular, instead of computing the hidden states from scratch for each new segment, we reuse the hidden states obtained in previous segments. 

The reused hidden states serve as memory for the current segment, which builds up a recurrent connection between the segments. As a result, modeling very longterm dependency becomes possible because information can be propagated through the recurrent connections. 

Meanwhile, passing information from the previous segment can also resolve the problem of context fragmentation. 

More importantly, we show the necessity of using relative positional encodings rather than absolute ones, in order to enable state reuse without causing temporal confusion. 

Hence, as an additional technical contribution, we introduce a simple but more effective **relative positional encoding** formulation that generalizes to attention lengths longer than the one observed during training. 

**Transformer-XL obtained strong results on five datasets, varying from word-level to character level language modeling. Transformer-XL is also able to generate relatively coherent long text articles with thousands of tokens (see Appendix E), trained on only 100M tokens** 

我们的主要技术贡献包括在纯自注意模型中引入递归概念，并推导新颖的位置编码方案。
这两种技术构成了一套完整的解决方案，因为它们中的任何一种都不能解决固定长度上下文的问题。 

Transformer-XL是第一个自我注意模型，在字符级别和单词级别的语言建模方面，其效果都比RNN更好得多。

#### 2 Related Work

In the last few years, the field of language modeling has witnessed many significant advances, including but not limited to devising novel architectures to better encode the context (Bengio et al., 2003; Mikolov et al., 2010; Merity et al., 2016; Al-Rfou et al., 2018), improving regularization and optimization algorithms (Gal and Ghahramani, 2016) , speeding up the Softmax computation (Grave et al., 2016a) , and enriching the output distribution family (Yang et al., 2017). 

 To capture the long-range context in language modeling, a line of work directly feeds a representation of the wider context into the network  as an additional input. Existing works range from ones where context representations are manually defined (Mikolov and Zweig, 2012; Ji et al., 2015; Wang and Cho, 2015) to others that rely on document-level topics learned from data (Dieng et al., 2016; Wang et al., 2017) 

More broadly, in generic sequence modeling, how to capture long-term dependency has been a long-standing research problem. From this perspective, since the ubiquitous adaption of LSTM, many efforts have been spent on relieving the vanishing gradient problem, including better initialization (Le et al., 2015), additional loss signal (Trinh et al., 2018), augmented memory structure (Ke et al., 2018) and others that modify the internal architecture of RNNs to ease the optimization (Wu et al., 2016; Li et al., 2018). 

**Different from them, our work is based on the Transformer architecture and shows that language modeling as a real-world task benefits from the ability to learn longer-term dependency.**  

#### Model 

Given a corpus of tokens x = (x1, . . . , xT ), the task of language modeling is to estimate the joint probability P(x), which is often auto-regressively factorized as P(x) = Q t P(xt | x 

With the factorization, the problem reduces to estimating each conditional factor. In this work, we stick to the standard neural approach to modeling the conditional probability. Specifically, a trainable neural network is used to encode the context x  t into a fixed size hidden state, which is multiplied with the word embeddings to obtain the logits. The logits are then fed into the Softmax function, yielding a categorical probability distribution over the next token. 

#####  Vanilla Transformer Language Models 

 In order to apply Transformer or self-attention to language modeling, the central problem is how to train a Transformer to effectively encode an arbitrarily long context into a fixed size representation. Given infinite memory and computation, a simple solution would be to process the entire context sequence using an unconditional Transformer decoder, similar to a feed-forward neural network. However, this is usually infeasible with the limited resource in practice. 

One feasible but crude approximation is to split the entire corpus into shorter segments of manageable sizes, and only train the model within each segment, ignoring all contextual information from previous segments. This is the idea adopted by Al-Rfou et al. (2018). We call it the vanilla model and visualize it in Fig. 1a. Under this training paradigm, information never flows across segments in either the forward or backward pass. There are two critical limitations of using a fixedlength context. First, the largest possible dependency length is upper bounded by the segment length, which is a few hundred on character-level language modeling (Al-Rfou et al., 2018). Therefore, although the self-attention mechanism is less affected by the vanishing gradient problem compared to RNNs, the vanilla model is not able to fully exploit this optimization advantage. Second, though it is possible to use padding to respect the sentence or other semantic boundaries, in practice it has been standard practice to simply chunk long text into fixed-length segments due to improved efficiency (Peters et al., 2018; Devlin et al., 2018; Al-Rfou et al., 2018). However, simply chunking a sequence into fixed-length segments will lead to the context fragmentation problem as discussed in Section 1.  

During evaluation, at each step, the vanilla model also consumes a segment of the same length as in training, but only makes one prediction at the last position. Then, at the next step, the segment is shifted to the right by only one position, and the new segment has to be processed all from scratch. As shown in Fig. 1b, this procedure ensures that each prediction utilizes the longest possible context exposed during training, and also relieves context fragmentation issue encountered in training. However, this evaluation procedure is extremely expensive. We will show that our proposed architecture is able to substantially improve the evaluation speed. 