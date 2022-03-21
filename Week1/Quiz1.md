Week 1 Quiz
Latest Submission Grade 100%
1.
Question 1
One of these statements below is true and the other three are false. Which one is true?


1 / 1 point

Every variable in C++ has to be associated with a specific type



Every function in C++ must return a value.



Every variable in C++ holds either an integer, a character, a Boolean or a floating point value (of some precision).



A Boolean variable can only be assigned a value from this set of three reserved words: {true, false, undefined}.





Correct
C++ is “strongly typed” which means that the type of every variable is assigned when the variable is declared, and the type of a variable cannot change once the variable is declared.

2.
Question 2
According to the C++ standard, what is the name of the function is the starting point for a program?


1 / 1 point

start()



begin()



init()



main()


Correct
When you write a C++ program, the program begins when the operating system calls the function “main().”

3.
Question 3
One of these statements below is true and the other three are false. Which one is true?


1 / 1 point

A class can consist of multiple member data variables of different types, but each member variable must be one of the built-in types.



A class can consist of multiple member data variables, but the type of each data variable does not need to be specified until the class is used to declare a variable.



A class can consist of multiple member data variables of different types, but each type must be specified when the class is defined.



A class can consist of multiple member data variables, but all must be of the same type.


Correct
4.
Question 4
One of these statements below is true and the other three are false. Which one is true?


1 / 1 point

Any functions that operate on a class’s member data variables must be implemented independent of the class in a separate .cpp file.



The member data variables in a class can only be accessed by the member functions of that class.



The member functions of a class always have access to every member data variable of that class.



The member functions of a class can only operate on member data variables of that class.


Correct
5.
Question 5
Which C++ directive is used to insert the contents of another file at the current location while processing the current file?


1 / 1 point

#import



#include



#using



#library


Correct
The file indicated by the string after the “#include” directive is compiled before the rest of the current file is compiled.

6.
Question 6
Given only the following code:

12345
namespace uiuc {
 	class Pair {
 		double a,b;
 	};
}
which of the following syntax can be written outside of the namespace declaration to properly create a variable named “p” of type Pair?


1 / 1 point

uiuc::Pair p;



uiuc/Pair p;



Pair p;



(uiuc) Pair p;


Correct
We have to reference the namespace to access the classes defined in it.

7.
Question 7
Which keyword is used to indicate which namespace(s) to search to find classes and variables when they are referenced throughout the rest of the program?


1 / 1 point

using



namespace



std



uiuc


Correct
The “using” keyword indicates to the compiler from which namespace references to classes and variables should be found.

8.
Question 8
Why do we use namespaces in C++ programming?


1 / 1 point

Because all variable and class names must be defined using a namespace.



Because all references to variable and class names must be made through namespace.



Because two different libraries might use the same label for a class or variable



Because it allows a library to claim a variable or class name that cannot be used by any other library.


Correct
Namespaces allow different libraries to use the same label for a class or variable because they can each define a unique namespace to differentiate them when they are used together in a program.

9.
Question 9
What is the namespace of the C++ Standard Library?


1 / 1 point

stdio



csl



cstl



std


Correct
10.
Question 10
Which operator is used to send a sequence of strings, numbers and other values to the standard library's cout object in a specific order so that they will be printed to the console?


1 / 1 point

&



+



=



<<


Correct
This is called the “streaming” operator and sends the operand on its right to the stream on its left. Syntactically, the expression also evaluates to the stream on the left, so the line:

1
std::cout << "a" << 3;
is first evaluated as

1
(std::cout << "a") << 3;
and the expression in the parentheses returns a reference to cout after sending “a” to it, so that the second  “<<” operator sends the value 3 to cout. You can think of it like this:

123456
// After the "a" has been sent to std::cout,
// the rest of the expression evaluates as:
std::cout << 3;

// Ater the 3 has been sent:
std::cout;
After each "<<" is evaluated, the sub-expression evaluates to a reference to std::cout, including at the very end, after all the streamed items have been sent. This will be useful to know later, when we'll show you how to make your own classes compatible with streaming to std::ostream objects (like std::cout).