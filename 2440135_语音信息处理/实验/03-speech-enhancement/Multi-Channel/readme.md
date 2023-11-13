# 实践二 多通道语音增强 

### SDR.py 
SDR的计算方法 

### ComputeSDR.py 
调用SDR.py进行多通道音频增强前后SDR变化的对照 

### linerdsbeaformer.py 
多通道麦克风阵列语音增强的核心代码

### generateMulti.py 
模拟产生多通道音频的代码、
基本流程就是用单通道音频 通过指定一些房间参数 通道数量 声源角度等等参数来产生多通道音频
如果觉得提供的数据不够用可以自行利用改代码模拟出更多的多通道音频
单通道的人声和噪声可以自己从网上选取或者自己录制



### dataset 
--clean 干净的多通道音频\
&nbsp;&nbsp;--clean_mul_20.wav 20代表声源产生的角度在麦克风的20°方向\
&nbsp;&nbsp;--clean_mul_170.wav\
--mixture  混合多通道音频\
&nbsp;&nbsp;--clean_20_steadyNoise_10.wav  20人声角度20 steadynoise稳态噪声 10噪声角度10 \
&nbsp;&nbsp;... \
--noise 多通道噪声音频\
&nbsp;&nbsp;--steadynoise_mul_10.wav 
