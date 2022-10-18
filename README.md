# Notepad_clone
This is a Notepad clone app developed as a part of Assignment 3 of SYSTEM PROGRAMMING LAB JUCSE'24

Hi! This text file is written using the notepad clone developed by Abhiraj Sen. This application is still under development and has limited features. A breif list of features have been listed below. Be sure to read till the end to understand the full functionality of this application.

Features:
At it's core it is a notepad application. It supports writing in your native device language. You can clear the screen using the NEW button under the FILE secction. The document can be saved as a ".txt" file using the save command. For saving the file using a different extension such as ".c" or ".cpp", etc, the SAVE AS function is used. This editor also facilitates the use of the printer connected to your system using the PRINT button under FILES. 

As an added feature, this notepad is also capable of compiling C/C++ programs, and opening the "Windows Powershell" for running the compiled code. Both these functions can be found under the FILES header.

This editor also has the common notepad features such as COPY, CUT, PASTE, REDO, UNDO. You can also search the entire document for a word  or a part of a word using the FIND utility. All these can be found under the EDIT header. 

You are also equipped to change the FONT of your entire text along with other text manipulations such as making the text BOLD, ITALICS, BOLD ITALICS. These can be done using the FONT utility found under the TOOLS header. 



THIS APPLICATION IS STILL UNDER DEVELOPMENT

1. The preferences section under TOOLS is supposed to be able to change the zoom of the page, change the format of the page such A4, A5, etc, change the alignment of the text and as such. I am still developing those features.
2. Currently the editor is able to compile only C/C++ codes. I aim to make it competent enough to compile codes of PYTHON, JAVA, etc.
3. The help website is under development.
4. Text highlighting of keywords will also be added.
5. Implementation of custom device drivers.
6. Identify typographical error.


DEVELOPMENT

I have developed this application using QT Creator 5.15.2 MinGW 64-bit. I have used QT libraries to implement most of the features of the notebook. In the initial stages, the COPY, CUT and PASTE methods were using the native Windows clipboard to achieve their functionality. This has been removed and currently it is using the QClipboard. The selection of the text is done using the QCursor. The REDO and UNDO fuctions are using the native functions of the QTextEditor. I am currently trying to implement a datastructure(stack and queue) to track the cursor movements along with writing, deletion and other actions so that the dependency on the in-built functions can be removed. The SAVE AS fuction converts the entire text to PlainText before storing it. The SAVE fuction does not do this extra conversion step. 


FEW IDEAS

Creation of two modes. One for normal text editing like notepad and another to serve as an IDE such as VS Code. A huge database of keywords will have to be stored to implement text highlighting. To identify typographical errors, I will need another huge database to store correct spelling of all known words, along with an option to add to the dictionary. This will get more complicated if custom device drivers are implemented which are in a different language.


KNOWN BUGS

In case GCC is not installed it will not give any promt. It will simply not show an output file. No error is displayed.


THERE MAY BE A FEW BUGS IN THE APPLICATION. PLEASE BE SURE TO POINT IT OUT!
