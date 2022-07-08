# prog2-beleg-qt

This project is an assignment for the course "Programmieren 2" at HTW Dresden. The objective is to program an application that simulates a library. The requirements were
as follows:
1. different types of media should be available
2. users should be managed by the application
3. users can borrow media and return it
4. the generated data should be persisted

# how the application was made

This application was developt using QtCreator 7.0.1 (Community) on Windows and debugged with the Desktop (x86-windows-msvc2019-pe-64) toolkit. The applications make tool
is set to qmake. The additional dependency xml was added to store the data. 
It has been tested on Windows and an Ubuntu 20.04.1 virtual machine with the commands `qmake && make` followed by `./prog2-beleg-qt`
