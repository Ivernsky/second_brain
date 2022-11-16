# 网站学习

[Git教程 - 廖雪峰的官方网站](https://www.liaoxuefeng.com/wiki/896043488029600/)

# 设置gitee/github公钥

```
ssh-keygen -t rsa -C "xxxxx@xxxxx.com"
ssh-keygen -t xxx -C "xxxxx@xxxxx.com"
#生成~/.ssh/rsa ~/.ssh/rsa.pub
#用rsa.pub的内容作为ssh公钥填到gitee账号里面

#验证公钥成功生效
ssh -T git@gitee.com
```

# git安装后-指定名称和邮箱

```git
git config --global user.name "your name"
git config --global user.email "email@163.com"
```

# git创建仓库和推送到gitee

```
mkdir learngit
cd learngit
pwd
# 初始化,生成.git文件
git init
git add
git commit -m "comment"
git remote add origin https://gitee.com/ivernsky/second_brain.git
git remote add origni git@github.com:ivernsky/second_brain.git
git push -u origin "master"

#解除了本地和远程的绑定关系
git remote rm origin
```

# 创建git仓库

```
mkdir second_bradin
cd second_bradin
git init 
touch README.md
git add README.md
git commit -m "first commit"
git remote add origin git@gitee.com:xxx/xxx.git
git push -u origin "master"
```

# 已有仓库

```
cd existing_git_repo
git remote add origin git@gitee.com:ivernsky/second_bradin.git
git push -u origin "master"

```

# github的配置
设置页面的ssh配置，新建一个ssh kes，用rsa.pub的内容作为ssh公钥填到Key里面