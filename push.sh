#!/bin/bash

# 添加所有修改
git add .

# 设置提交说明，格式为 Site updated: 2006-01-02 15:04:05
time=$(date "+%Y-%m-%d %H:%M:%S")
commit="Updated: "$time
echo $commit

# 提交
git commit -m "$commit"

# 推送到 main 分支上
git push origin main
