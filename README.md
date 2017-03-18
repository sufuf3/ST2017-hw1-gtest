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

## Add hw floder
1. mkdir ~/ST2017-hw1-gtest/[hw]
2. cd ~/ST2017-hw1-gtest/[hw]
3. Add files
4. g++ triangle.cpp test.cpp -I ../gtest/include -L ../gtest/make -lgtest -lpthread -o test
5. ./test

## list

**Triangle problems**  
 - [x] Boundary value testing  
 - [x] Equivalence class testing  
 - [ ] decision table based testing   

**NextDate problems**    
 - [x] Boundary value testing   
 - [ ] Equivalence class testing  
 - [ ] decision table based testing   

**Commission problems**    
 - [ ] Boundary value testing  
 - [ ] Equivalence class testing  
 - [ ] decision table based testing  
