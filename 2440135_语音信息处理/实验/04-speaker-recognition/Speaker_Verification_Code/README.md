# 实验04
## 实验内容
本次实验利用公开数据库实现声纹识别系统并进行验证。该实验旨在贯通课程学习中声纹识别的相关内容。通过实现前端特征提取、深度神经网络、池化层、损失函数等必要步骤，掌握声纹识别的整体流程，并了解部分优化方法。
## 环境依赖
### python环境
python
### 安装包依赖
pytorch  
pyyaml  
soundfile  
python_speech_features  
scipy  
librosa  
## 文件说明
Speaker_Verification_Code 代码库  
声纹识别系统实现及验证课程实验内容.docx 实验指导  
README.md 说明文件
## 实验数据
[AIShell](http://www.openslr.org/33/)子集  
[下载地址](https://pan.baidu.com/s/1ucjXgTnnvMmsRMPa9X0XMQ) 提取码：duqp
## 环境配置
### 虚拟环境安装与激活
```
conda create -n spkcls python=3.6
conda activate spkcls
```
### pytorch环境安装
```
conda install pytorch==1.6.0 torchvision==0.7.0 cudatoolkit=10.2 -c pytorch
```
### python依赖包安装
```
pip install pyyaml
pip install soundfile
pip install python_speech_features
pip install scipy
pip install librosa
pip install pandas
pip install matplotlib
```

## 参考
[1] [SpeechBrain官方文档及代码 [github]](https://github.com/speechbrain/speechbrain)  
[2] [声纹识别系统搭建 [参考]](https://github.com/zengchang233/asv_beginner/tree/master)  
[3] [Pytorch模型搭建 [参考]](https://pytorch.org/tutorials/beginner/blitz/neural_networks_tutorial.html#sphx-glr-beginner-blitz-neural-networks-tutorial-py)  