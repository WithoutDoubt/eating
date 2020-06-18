开头第一句：

To evaluate the performance of the proposed method, we create some synthetic datasets。

The conditions of all the datasets are summarized in Table 1.

**版本**1：

The sampling rate of the speech files is 16 kHz. We use short-time Fourier transform (STFT) to extract the spectrum from each speech utterance.

A Hanning window with 512 points and overlap interval of 128 are used. The fast Fourier transform (FFT) is taken at 512 points and the first 257 FFT points are used as our spectral feature.
Hence for all neural networks in this paper, the input and the output are both magnitude spectrum with 257 dimensions. 

In the evaluation stage, we combine the output of neural network and phase information calculated from the corresponding noisy speech and use inverse Fourier transform (IFT) to get the enhanced wave file.



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