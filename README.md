# WeHappyFew
WeHappyFew repository for Polygon (gamedev science club at Warsaw University of Technology) c++ project

## Installation
Create new directory root, then clone repository into that directory using <br />
git clone --recurse-submodules https://github.com/RobPiwowarek/WeHappyFew <br />
To clone specific branch add: -b branch_name --single-branch

After cloning to build project create new subdirectory build, enter it and run cmake:
1. mkdir build
2. cd build
3. cmake ..

Alternatively run setup.bat - simple setup batch script that performs above actions.

Inside build will be generated solution files, setup Game as starting project and run it. <br />
On VisualStudio first build might fail, ignore it - reopen VisualStudio again and project should work fine.
