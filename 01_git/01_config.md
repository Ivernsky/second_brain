# 设置gitee/github公钥
```
ssh-keygen -t rsa -C "xxxxx@xxxxx.com"
ssh-keygen -t xxx -C "xxxxx@xxxxx.com"
#生成~/.ssh/rsa ~/.ssh/rsa.pub
#用rsa.pub的内容作为ssh公钥填到gitee账号里面
```

# git安装后-指定名称和邮箱
``` git
git config --global user.name "your name"
git config --global user.email "email@163.com"
```

# 创建版本库
```
mkdir learngit
cd learngit
pwd
# 初始化,生成.git文件
git init
```
