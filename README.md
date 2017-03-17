# ST2017-hw1-gtest  
## Set the Google test on Ubuntu  
1. cd ~/  
2. wget https://github.com/google/googletest/archive/release-1.8.0.tar.gz  
3. tar zxvf release-1.8.0.tar.gz  
4. mkdir ~/ST2017-hw1-gtest  
5. cd ~/ST2017-hw1-gtest  
6. cp -r ~/googletest-release-1.8.0/googletest ~/ST2017-hw1-gtest/gtest  
7. cd ~/ST2017-hw1-gtest/gtest/make  
8. make  
9. mv gtest_main.a libgtest.a  
