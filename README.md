# ZIS C++ Summer Course 2019
Hello and welcome to the `ZIS C++ Summer course 2019` resource page. From this page you will be able to access the presentations and any example code/ solutions that we construct during the course.





## Who is this course for?
- This course is for students who have no or very limited programming experience. 

- We do NOT expect that you have any prior knowledge regarding C++ or any other progamming language. 

- This course is constructed for beginners who wish to get a good foundation for programming.




## What to expect from the class dynamic
- Lots of programming. Learning by programming is one of the best way to further your knowledge (and it's loads of fun).  

- Classes are designed to be interactive. We will work together to find solutions and different ways of approaching a problem.

- Asking questions is by far the best thing to do if something is unclear, so we will always encourage you to ask if you don't understand something.

- We want you to engage with eachother so we will give you small problems to solve with your friends. At the end we will explain one way in which the problem could have been solved (there is mostly more than one way, so don't be discouraged if you don't get it the first time around).




## What to expect from the class content
- We will explore the basic architecture of the computer, how it works and why its important to understand.

- Introduction to how programming can be used to solve real world problems.

- Introduction to procedural programming in C++, and answerign the question "why is C++ useful?".

- Learning the basics of C++, how it works and what does it provide for us.

- How can we use C++ to do something useful, how can we make C++ do math for us, or display information on a screen.




## What can you do in advanced?
- We will be using the [`Codeboard.io`](https://codeboard.io) platform to do our programming, signing up before starting the course would be great, but we will allocate some time to do this before we get started.

- There is no need to study any advanced mathematics, as long as you are confident with simple addition, subtraction multiplication and division you will be fine. Regardless of this, all uses of maths will be explained regardless so that nobody gets confused.



## What materials are required for classes?
- If the school supplied you with a laptop then thats all you need.

- If you have a `Mac laptop` or a machine running `Linux/Unix`, feel free to use that instead of the school computer. 
  - Personaly `I would recommend using the Mac` since you will not be dependent on codeboard.io (but it's up to you)

- If you have a personal `Windows` based computer you can still use it, but you may as well use the school laptops (if they are provided)

- If you wish to take notes then bring a pen and paper, but we will make all the slides available so you can reference them later.




## A little bit about codeboard.io
- [`Codeboard.io`](https://codeboard.io) is an online development tool used to write programs, we will be using it to write C++

- [`Codeboard.io`](https://codeboard.io) allows us to run code on a server, which is nice since you won't need to install anything on your machine.

- Because we are running programs remotely (not on our own computer) we don't need to worry about things going wrong and crashing on our machine (Severe crashes <b>will never be the case</b> given the content that we will cover).





## Potential inconveniences when using this site

- `Issue:` I clicked the powerpoint here on the website and all I saw was: `(Sorry about that, but we can’t show files that are this big right now.)`.
  - `Solution:` This is just a side effect of using Github, the powerpoint is there, just click on the `Download` button on the right and the powerpoint (`.pptx` file) will be downloaded.   



## Installing Clion on Windows
- `Installing the IDE:` Go to [`JetBrains`](https://www.jetbrains.com/clion/) and install Clion
  - Follow the instalation guide and just go with the default for everything
  
 - `Installing the necessary dependencies:` Visit the [`THIS PAGE`](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html#MinGW) and follow the `MinGW` section. You may IGNORE ALL OTHER SECTIONS!
 
 - `Configuring Clion`: Once you have installed all the relevant packages (as listed in the instructions), navigate into the `settings` section (accessible by pressing `ctrl+alt+s`)
  - Navigate into `Build, Execution, Deployment` -> `Toolchains`
  - Go to [`THIS PAGE`](https://www.jetbrains.com/help/clion/how-to-create-toolchain-in-clion.html) and follow the instructions provided.

- You should now be ready to start creating projects. 
  - For sanity, create a new project in any directory you see fit.
  - Name the project whatever you like, say `myProject` for example.
  - Create a new `C++ Executable` using the `C++ 14` language standard (this should be a default)
  - Once you have done this you will see a file called `CMakeList.txt`. 
    - Change this file to make it look as follows: 
    ```c
    cmake_minimum_required(VERSION 3.13)
    project(`myProject`)
    set(CMAKE_CXX_STANDARD 14)
    set(SOURCE_FILES main.cpp)
    add_executable(`myProject` ${PROJECT_FILES})
 
  - Once you have done this you should be able to run the code in the `main.cpp` 
  
  
  
`Note:` This page will be updated over the next couple days. 
