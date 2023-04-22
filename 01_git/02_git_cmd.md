# git常用命令

```git
#比较
git diff

#查看状态
git status
git status -s 
git log --pretty=oneline
```

# 回退

```git
#回退到上一个版本,强制
git reset
git reset --hard HEAD^
git reset --hard f13e7fd
git reset --soft

#查看命令历史
git reflog 
```

# 修改

```git
#修改1 -> git add -> 修改2 -> git add(需要重新add) -> git commit
```

# 撤销修改(工作区)

```git
git checkout -- file
git checkout
```

`--`很重要,`--` 没有就变成切换分支



# 拉取远程master到本地仓库

```git
git pull origin master
```