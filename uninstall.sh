# 这个命令用于卸载安装在系统上的本库

# 1. 删除/usr/include/lzx0626目录
sudo rm -rf /usr/include/lzx0626
echo "Delete header file successfully."

# 2. 删除/lib64目录中的liblzx0626*.a文件
sudo rm -rf /lib64/liblzx0626*.a
echo "Delete static library successfully."
