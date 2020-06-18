开头第一句：

To evaluate the performance of the proposed method, we create some synthetic datasets。

The conditions of all the datasets are summarized in Table 1.

**版本**1：

We first analyze the performance of the baseline methods and the proposed method on Test-0 using casual dynamic attention. The re- sults of PESQ and STOI are summarized in Table 2. We can clearly see that the attention-based method outperforms the two baselines consistently for different size of parameters, which indicates that in- troducing attention mechanism to neural network based speech en- hancement is beneficial.

We also notice that the stacked encoder structure has slightly better performance than the expanded encoder structure but the difference is not significant.

In the experiments for causal local attention, the value of w was set to 5, 15 and 30. 

The results of PESQ and STOI on Test-0 are shown in Table 3. Previous observation is still valid for causal local attention: the attention-based model outperforms the baseline systems. 

We also notice that bigger value of w for causal local atten- tion results in no further improvement and the best performance is achieved when w = 5. 

At the same time, comparing Table 2 and Table 3, the causal local attention models have comparative or even better performance than the causal dynamic attention models. 

The above two observations verify the conjecture that we do not need consider very long historical information in the speech enhancement task. 

This is reasonable because noise conditions (types and SNRs) may change time to time.

To make an intuitive understanding of the attention mechanism, we have visualized the attention weights of the two attention-based approaches with stacked encoder (w = 5) on a testing speech clip (100 frames), as shown in Fig 3. 

The x axis represents hK and the y axis represents hQ. 

The point, (x, y) represent attention weight. We can see that the attention-based model gives different weights (or different ‘attention levels’) to the contextual frames explicitly during speech enhancement. 

To further showcase the speech enhancemen- t ability of different methods, a speech utterance (spectrum) from Test-0 is shown in Fig 4. 

The original speech is contaminated with ‘dog-barking’ noise. 

The traditional OM-LSA method cannot handle this kind of non-stationary noise properly: most of the noise compo- nents still exist and some of the speech components are mistakenly removed. 

Although the LSTM approach can significantly remove the noise components in this example, there still exists noise residu- als (in the marked rectangular). 

On the contrast, the attention-based method can remove the noise properly and the speech components are almost completely restored. 

Some of our testing examples can be found from https://xhoare.github.io/index.html.

Experimental results on Test-0,1,2,3,4 are summarized in Table 4, which shows the generalization capability of different approaches.

Here for the attention model, the casual local attention strategy is used and the attention window w = 5. 

First, we can see that, on all the test sets, the neural network methods (LSTM and attention) achieve superior performances over the traditional OM-LSA method and attention-based models consistently achieve the best performance. 

We also notice that all the neural network models have performance degradation when tested on the mismatched sets (Test- 1,2,3,4 vs. Test-0). 

Moreover, the models trained on the data with 0-20dB SNR have significant performance degradation on the test set with -5-0dB SNR (Test-2). 

Further with both mismatched noises and SNR conditions, large performance degradation can be ob- served on Test-4. 

But among all the methods, our attention models have shown better generalization ability. 

For example on Test-4, the attention model with stacked encoder has achieve 0.173 and 0.295 absolute PESQ gains as compared with the ordinary LSTM model and the OM-LSA method, respectively. 

These results further prove that the proposed method using attention mechanism is promising in improving speech enhancement performance.







We compare our approach with OM-LSA [31] and an LSTM approach without attention mechanism. Here as a typical statistical method, OM-LSA is treated as the baseline.

The LSTM has two layers and each layer has 128/256/512 cells.

Note that in order to make performance comparison when the models have similar size of parameters, the cell size of the LSTM encoder in the proposed attention approach is set to 112/224/448, accordingly.

These models are initialized with the normalized initialization and trained using Adam [32].

The loss function used is mean square error (MSE).

All parameters are learned automatically when we train the neural network.

The learning rate is set to 0.0005 at the beginning and decays with a rate of 0.5 when the loss of current epoch is greater than the previous epoch.

The batch size is 128.

Dropout regularization is also used [33].

Perceptual evaluation of speech quality (PESQ) and short-time objective intelligibility (STOI) are used as evaluation criteria.



**版本**2



**版本**3





---



自己的版本：

We compare our approach with LSTM approach  [31] and an Transformer approach without Local RNN mechanism. 

Here as a typical statistical method, OM-LSA is treated as the baseline. 【naive transformer as the baseline】

The LSTM has two layers and each layer has 1024 cells.

Note that in order to make performance comparison when the models have similar size of parameters, the cell size of the LSTM encoder 【in the proposed attention approach】 is set to 112/224/448, accordingly.

These models are initialized with the normalized initialization and trained using Adam [32].

The loss function used is mean square error (MSE).

All parameters are learned automatically when we train the neural network.

The learning rate is set to 0.0005 at the beginning and decays with a rate of 0.5 when the loss of current epoch is greater than the previous epoch.

The batch size is 128.

Dropout regularization is also used [33].

Perceptual evaluation of speech quality (PESQ) and short-time objective intelligibility (STOI) are used as evaluation criteria.