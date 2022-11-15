# 网站

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
git remote add origin https://gitee.com/ivernsky/second_bradin.git
git push -u origin "master"
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