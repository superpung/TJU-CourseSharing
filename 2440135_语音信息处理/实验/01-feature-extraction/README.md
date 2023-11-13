# 实验01
## 实验内容
通过补全预加重、分帧、加窗、快速傅里叶变换、求取滤波器组、离散余弦变换等代码，熟悉语音信号处理的相关内容，对语音特征提取的步骤进行掌握。 
此外求取频谱包络为选做实验。
运行成功后生成的图片会保存在result文件夹下。
## 环境依赖
### python环境
python3  
### 安装包依赖
numpy  
librosa  
scipy  
matplotlib  
## 文件说明
feature_extractor.py 特征提取代码  
test.wav 测试音频  
README.md 说明文件

## 参考
[1] [python_speech_features [github]](https://github.com/jameslyons/python_speech_features.git)  
[2] [torchaudio.compliance.kaldi [官方文档]](https://pytorch.org/audio/stable/_modules/torchaudio/compliance/kaldi.html#spectrogram)  
[3] [【语音-01】Fbank和MFCC介绍-理论和代码 [博客园]](https://www.cnblogs.com/yifanrensheng/p/13510742.html#_label4_0)  
[4] [提取语音频谱包络步骤及matlab代码参考 [CSDN]](https://blog.csdn.net/weixin_42069606/article/details/120503503)
