#!/bin/bash
echo "In relative_path.sh, pwd: $(pwd)"
sh ./scripts/test_relative_path.sh


# 结论
#   在 shell 脚本中，相对路径 ⁠./ 是相对于当前的工作目录（current working directory，cwd），而不是相对于脚本文件本身的位置。
#   不管是在 ⁠relative_path.sh 调用 ⁠scripts/test_relative_path.sh
#   还是在 test_relative_path.sh 中用 ⁠./
#   ⁠./ 都是相对于你执行 ⁠relative_path.sh 时的工作目录(也就是你敲出sh xxx.sh命令的那个目录)
