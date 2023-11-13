# 实验02-1
## 实验内容
通过补全GMM中EM算法，从而完成基于GMM的英语数字语音的识别。  
基于13维MFCC特征，每个类别用3个高斯模型建模，目前在测试集上可达95.5%的识别准确率。
## 环境依赖
### python环境
python  
### 安装包依赖
numpy  
scipy  
python_speech_features
## 文件说明
gmm.py GMM实现代码   
utils.py 工具代码   
README.md 说明文件  
data 数据文件夹

## 参考
[1] [nwpuaslp/ASR_Course [github]](https://github.com/nwpuaslp/ASR_Course/tree/master/03-GMM-EM)  
[2] [GMM\EM算法详解——附0-9孤立词识别demo(python实现) [CSDN]](https://blog.csdn.net/weixin_39529413/article/details/117200165)  
[3] [stober/gmm [github]](https://github.com/stober/gmm/blob/master/src/gmm.py)

